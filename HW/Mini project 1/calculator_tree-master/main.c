#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lex.h"
/*
Something like Python
>> y = 2
>> z = 2
>> x = 3*y + 4/(2*z)
*/

/*
the only type: integer
everything is an expression
  statement   := END |  END
  +prexpr      := expr prexpr_tail
  +prexpr_tail := LOGICOP expr prexpr_tail | NIL
  expr        := term expr_tail
  expr_tail   := ADDSUB term expr_tail | NIL
  term        := factor term_tail
  term_tail   := MULDIV factor term_tail | NIL
  factor      := INT | ADDSUB INT | ADDSUB ID | ID ASSIGN expr | ID | LPAREN expr RPAREN

  expr -> prexpr (for factor and statement)
*/


#define TBLSIZE 65535
typedef struct {
	char name[MAXLEN];
	int val;
	int memoryAddress;
} Symbol;
Symbol table[TBLSIZE];
int sbcount = 0;
int memoryAddress = 12;     //x, y, z in [0], [4], [8] initially
bool equal_sign = false;    //if equal_sign == true, equal_assign has already occur
bool equal_sign_right = false;  //determine whether it is parsing right tree or not

typedef struct _Node {
	char lexeme[MAXLEN];
	TokenSet token;
	int val;
	struct _Node *left, *right;
} BTNode;

void statement(void);
BTNode* prexpr(void);
BTNode* expr(void);
BTNode* term(void);
BTNode* factor(void);
int getval(void);
int setval(char*, int);
int getAddress(char* );

typedef enum {MISPAREN, NOTNUMID, NOTFOUND, RUNOUT, NAN, DUALASSIGN, UNKNOWNVAR, LEFTVARS} ErrorType;
void error(ErrorType errorNum);

/* create a node without any child */
BTNode* makeNode(TokenSet tok, const char *lexe)
{
	BTNode *node = (BTNode*) malloc(sizeof(BTNode));
	strcpy(node->lexeme, lexe);
	node->token= tok;
	node->val = 0;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/* clean a tree */
void freeTree(BTNode *root)
{
	if (root!=NULL) {
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

int getAddress(char* lexeme)
{
    //get the address of lexeme
    int i = 0, retAddr = -1;
	while (i<sbcount) {
		if (!strcmp(lexeme, table[i].name)) {
			retAddr = table[i].memoryAddress;
			break;
		} else {
			i++;
		}
	}
	return retAddr;
}

/* traverse the syntax tree by pre-order
   and evaluate the underlying expression */
int evaluateTree(BTNode *root, int regPos)
{
	int retval = 0, lv, rv;
	if (root != NULL) {
		switch (root->token) {
		case ID:
            printf("MOV r%d [%d]\n", regPos, getAddress(root->lexeme));
            retval = root->val;
            break;
		case INT:
		    printf("MOV r%d %d\n", regPos, root->val);
			retval = root->val;
			break;
		case ASSIGN:
		    lv = 0;
            rv = evaluateTree(root->right, regPos);
            retval = setval(root->left->lexeme, rv);
            printf("MOV [%d] r%d\n", getAddress(root->left->lexeme), regPos);
            break;
		case ADDSUB:
		case MULDIV:
        case LOGICOP:
		    lv = evaluateTree(root->left, regPos);
            rv = evaluateTree(root->right, regPos+1);

			if (strcmp(root->lexeme, "+") == 0){
                printf("ADD r%d r%d\n", regPos, regPos+1);
				retval = lv + rv;
			}
			else if (strcmp(root->lexeme, "-") == 0){
                printf("SUB r%d r%d\n", regPos, regPos+1);
				retval = lv - rv;
			}
			else if (strcmp(root->lexeme, "*") == 0){
				retval = lv * rv;
                printf("MUL r%d r%d\n", regPos, regPos+1);
			}
			else if (strcmp(root->lexeme, "/") == 0){
				if (rv==0){
					error(NAN);
				}
				else{
                    printf("DIV r%d r%d\n", regPos, regPos+1);
					retval = lv / rv;
				}
			}
			else if(!strcmp(root->lexeme, "|")){
                printf("OR r%d r%d\n", regPos, regPos+1);
			}
            else if(!strcmp(root->lexeme, "^")){
                printf("XOR r%d r%d\n", regPos, regPos+1);
            }
            else if(!strcmp(root->lexeme, "&")){
                printf("AND r%d r%d\n", regPos, regPos+1);
            }
			break;
		default:
			retval = 0;
		}
	}
	return retval;
}

int getval(void)
{
    //if lookahead is int, return it's value
    //if lookahead is ID, find it's value in table
    //=> if ID not found, create a variable in table
	int i, retval, found;

	if (match(INT)) {
		retval = atoi(getLexeme());
	} else if (match(ID)) {
		i = 0;
		found = 0;
		retval = 0;
		while (i<sbcount && !found) {
			if (strcmp(getLexeme(), table[i].name)==0) {
				retval = table[i].val;
				found = 1;
				break;
			} else {
				i++;
			}
		}
		if (!found) {
			if (sbcount < TBLSIZE) {
				strcpy(table[sbcount].name, getLexeme());
				table[sbcount].val = 0;

                if(!strcmp(table[sbcount].name, "x")){
                   table[sbcount].memoryAddress = 0;
                   table[sbcount].val = 1;
                   retval = 1;
                }
                else if(!strcmp(table[sbcount].name, "y")){
                   table[sbcount].memoryAddress = 4;
                   table[sbcount].val = 1;
                   retval = 1;
                }
                else if(!strcmp(table[sbcount].name, "z")){
                   table[sbcount].memoryAddress = 8;
                   table[sbcount].val = 1;
                   retval = 1;
                }
                else{
                     if(equal_sign_right == true)
                        error(UNKNOWNVAR);

                    table[sbcount].memoryAddress = memoryAddress;
                    memoryAddress += 4;
                }
				sbcount++;
			} else {
				error(RUNOUT);
			}
		}
	}
	return retval;
}

int setval(char *str, int val)
{
    //set the variable (str)'s val to val in table
    //if str doesn't exist, return 0;
	int i, retval = 0;
	i = 0;
	while (i<sbcount) {
		if (strcmp(str, table[i].name)==0) {
			table[i].val = val;
			retval = val;
			break;
		} else {
			i++;
		}
	}
	return retval;
}

//prexpr      := expr prexpr_tail
//prexpr_tail := LOGICOP expr prexpr_tail | NIL
BTNode* prexpr(void)
{
	BTNode *retp, *left;
	retp = left = expr();
	while (match(LOGICOP)) { // tail recursion => while
		retp = makeNode(LOGICOP, getLexeme());
		advance();
		retp->right = expr();
		retp->left = left;
		left = retp;
	}
	return retp;
}


//  expr        := term expr_tail
//  expr_tail   := ADDSUB term expr_tail | NIL
BTNode* expr(void)
{
	BTNode *retp, *left;
	retp = left = term();
	while (match(ADDSUB)) { // tail recursion => while
		retp = makeNode(ADDSUB, getLexeme());
		advance();
		retp->right = term();
		retp->left = left;
		left = retp;
	}
	return retp;
}

//  term        := factor term_tail
//  term_tail := MULDIV factor term_tail | NIL
BTNode* term(void)
{
	BTNode *retp, *left;
	retp = left = factor();
	while (match(MULDIV)) { // tail recursion => while
		retp = makeNode(MULDIV, getLexeme());
		advance();
		retp->right = factor();
		retp->left = left;
		left = retp;
	}
	return retp;
}

BTNode* factor(void)
{
	BTNode* retp = NULL;
	char tmpstr[MAXLEN];

	if (match(INT)) {
        if(!equal_sign_right){
            // on the left side of equal sign
            error(LEFTVARS);
	    }

		retp =  makeNode(INT, getLexeme());
		retp->val = getval();
		advance();
	} else if (match(ID)) {
		BTNode* left = makeNode(ID, getLexeme());
		left->val = getval();
		strcpy(tmpstr, getLexeme());
		advance();
		if (match(ASSIGN)) {
            if(!equal_sign) equal_sign = true;
            else error(DUALASSIGN);

            if(!equal_sign_right) equal_sign_right = true;

			retp = makeNode(ASSIGN, getLexeme());
			advance();
			retp->right = prexpr();
			retp->left = left;
		} else if(match(ID)){
		    error(LEFTVARS);
        }else {
			retp = left;
		}
	} else if (match(ADDSUB)) {
	    if(!equal_sign_right) error(LEFTVARS);

		strcpy(tmpstr, getLexeme());
		advance();
		if (match(ID) || match(INT)) {
            if(match(INT)){
                strcat(tmpstr, getLexeme());
                retp = makeNode(INT, tmpstr);
                retp->val = atoi(tmpstr);
            }
            else{
                retp = makeNode(ADDSUB, tmpstr);
                retp->right = makeNode(ID, getLexeme());
                retp->right->val = getval();
                retp->left = makeNode(INT, "0");
                retp->left->val = 0;
            }
            advance();
		} else {
			error(NOTNUMID);
		}
	} else if (match(LPAREN)) {
        if(!equal_sign_right) error(LEFTVARS);

		advance();
		retp = prexpr();
		if (match(RPAREN)) {
			advance();
		} else {
			error(MISPAREN);
		}
	} else {
		error(NOTNUMID);
	}
	return retp;
}

void error(ErrorType errorNum)
{
/*
	switch (errorNum) {
	case MISPAREN:
		fprintf(stderr, "Mismatched parenthesis\n");
		break;
	case NOTNUMID:
		fprintf(stderr, "Number or identifier expected\n");
		break;
	case NOTFOUND:
		fprintf(stderr, "%s not defined\n", getLexeme());
		break;
	case RUNOUT:
		fprintf(stderr, "Out of memory\n");
		break;
	case NAN:
		fprintf(stderr, "Not a number\n");
		break;
    case DUALASSIGN:
        fprintf(stderr, "Two equal signs\n");
        break;
    case LEFTVARS:
        fprintf(stderr, "More than one variable on the left side\n")
	}
*/
	printf("EXIT 1\n");
	exit(0);
}

void statement(void)
{
	BTNode* retp;       //root of the syntax tree
    equal_sign = false;
    equal_sign_right = false;

	if (match(END)) {
		advance();
	} else {
		retp = prexpr();
		if (match(END)) {
            if(retp->token != ASSIGN){
                printf("EXIT 1\n");
                exit(0);
            }

            evaluateTree(retp, 0);
			freeTree(retp);
			advance();
		}
	}
}

int main()
{
	while (1) {
		statement();
	}
	return 0;
}

/*
int main(void)
{
    TokenSet tok;
    tok = getToken();
    while (tok != END) {
        printf("%d: %s\n", tok, getLexeme());
        tok = getToken();
    }
    return 0;
}
*/
