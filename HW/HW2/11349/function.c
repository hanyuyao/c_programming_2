#include "function.h"
#include <stdio.h>
#include <stdlib.h>

void create_node(Node* root, int number)
{
    if(number < root->data && root->left != NULL){
        create_node(root->left, number);
    }
    else if(number < root->data && root->left == NULL){
        root->left = (Node*)malloc(sizeof(Node));
        root->left->data = number;
        root->left->left = NULL;
        root->left->right = NULL;
    }
    else if(number > root->data && root->right != NULL){
        create_node(root->right, number);
    }
    else if(number > root->data && root->right == NULL){
        root->right = (Node*)malloc(sizeof(Node));
        root->right->data = number;
        root->right->left = NULL;
        root->right->right = NULL;
    }
    else{return;}
}

void create_tree(Node **root, int n)
{
    int temp;
    Node* tempNode;
    tempNode = (Node*)malloc(sizeof(Node));
    scanf("%d", &(tempNode->data));
    tempNode->left = NULL;
    tempNode->right = NULL;

    int i;
    Node* tempRoot = tempNode;
    for(i = 1; i < n; i++){
        scanf("%d", &temp);
        //recursively build tree
        //create_node(tempNode, temp);

        //iteratively build tree
        while(1){
            if(temp < tempNode->data && tempNode->left != NULL){
                tempNode = tempNode->left;
            }
            else if(temp > tempNode->data && tempNode->right != NULL){
                tempNode = tempNode->right;
            }
            else if(temp < tempNode->data && tempNode->left == NULL){
                tempNode->left = (Node*)malloc(sizeof(Node));
                tempNode->left->data = temp;
                tempNode->left->left = NULL;
                tempNode->left->right = NULL;
                tempNode = tempRoot;
                break;
            }
            else if(temp > tempNode->data && tempNode->right == NULL){
                tempNode->right = (Node*)malloc(sizeof(Node));
                tempNode->right->data = temp;
                tempNode->right->left = NULL;
                tempNode->right->right = NULL;
                tempNode = tempRoot;
                break;
            }
            else{
                tempNode = tempRoot;
                break;
            }
        }
    }

    *root = tempNode;
}

void preorder(Node* root)
{
    if(root != NULL){
        printf(" %d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root)
{
    if(root != NULL){
        inorder(root->left);
        printf(" %d", root->data);
        inorder(root->right);
    }
}

void postorder(Node* root)
{
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" %d", root->data);
    }
}

void print_tree(Node *root)
{
    printf("preorder:");
    preorder(root);
    printf("\n");

    printf("inorder:");
    inorder(root);
    printf("\n");

    printf("postorder:");
    postorder(root);
    printf("\n");
}
