#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

BTNode* EXPR()
{
    //parse form end to front
    //int pos is the parse position of character array expr
    if(pos < 0) return NULL;

    BTNode* newNode = FACTOR();
    if(pos > 0 && (expr[pos]=='|' || expr[pos]=='&')){
        BTNode* root = makeNode(expr[pos--]);
        root->right = newNode;
        root->left = EXPR();
        return root;
    }
    else
        return newNode;
}

BTNode* FACTOR()
{
    if(pos < 0) return NULL;

    if(expr[pos]=='A' || expr[pos]=='B' || expr[pos]=='C' || expr[pos]=='D'){
        //ID
        BTNode* newNode = makeNode(expr[pos]);
        pos--;
        return newNode;
    }
    else{
        //(EXPR)
        pos--;
        BTNode* newNode = EXPR();
        pos--;
        return newNode;
    }
}

BTNode* makeNode(char c)
{
    BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
    switch(c){
    case 'A':
        newNode->data = ID_A;
        break;
    case 'B':
        newNode->data = ID_B;
        break;
    case 'C':
        newNode->data = ID_C;
        break;
    case 'D':
        newNode->data = ID_D;
        break;
    case '|':
        newNode->data = OP_OR;
        break;
    case '&':
        newNode->data = OP_AND;
        break;
    default:
        break;
    }
    newNode->left = newNode->right = NULL;

    return newNode;
}
