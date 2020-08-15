#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXEXPR 256

char expr[MAXEXPR];

typedef enum {VAR_A, VAR_B, VAR_C, VAR_D, OP_AND, OP_OR} TokenSet;
char sym[6]="ABCD&|";

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

/* create a node without any child.*/
BTNode* makeNode(int val){
    BTNode *node = (BTNode*) malloc(sizeof(BTNode));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

/* print a tree by pre-order. */
void printPrefix(BTNode *root){
    if (root != NULL) {
        printf("%c",sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}


/* parse an infix expression and generate a syntax tree. */
BTNode* parser(int start, int end){
    int pos, cnt;
    char c;
    BTNode *node = NULL, *right=NULL;

    if (start<=end) {   // if the expression has length > 1.
        c = expr[end];  // parse from the end of expression.
        if (c ==')') {  // 1. the ( ) cases
            cnt = 1;    //     find the matching '('
            pos = end - 1;
            while (pos>=start) {
                if (expr[pos]==')') cnt++;
                else if (expr[pos]=='(') cnt--;
                if (cnt==0) break;
                pos--;
            }
            if (cnt!=0){
                printf("Error: no matching parenthesis \n");
                return NULL;
            }
            right = parser(pos+1, end-1);  // parse the expression inside the parenthesis

        } else if (c>= 'A' && c<='D') {  // 2. the VAR case
            right = makeNode(VAR_A + c - 'A');
            pos = end;
        } else {
            printf("Error: unknown input %c.\n",c);
            return NULL;
        }

        if (--pos>=start) { // 3. the OP case
            c = expr[pos];
            if (c=='&' || c=='|'){
                node = makeNode((c=='&')? OP_AND:OP_OR);
                node->right = right;
                node->left = parser(start, --pos);
                if (node->left == NULL) {
                    printf("Error: invalid expression, no valid left term for %c\n", c);
                    freeTree(node);
                    return NULL;
                }
            } else {
                printf("Error: unknown input %c\n",c);
                freeTree(right);
                return NULL;
            }
        } else
            node = right;
    }
    return node;
}

int main(){
    int len;
    gets(expr);
    len = strlen(expr);
    BTNode *root = parser(0, len-1);
    printPrefix(root);
    freeTree(root);
    return 0;
}
