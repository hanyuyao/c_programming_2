#include <stdio.h>
#include <stdlib.h>
#include "function.h"

/*
Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end)
{
    if(inorder_start==inorder_end){
        Node* root = (Node*)malloc(sizeof(Node));
        root->data = preorder[0];
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    Node* root = (Node*)malloc(sizeof(Node));
    root->data = preorder[0];

    int i;          //i is root position in in_order traversal
    for(i = inorder_start; i <= inorder_end; i++){
        if(inorder[i] == preorder[0]){
            break;
        }
    }

    if(i-1 >= inorder_start){
        //if left subtree exist, build left subtree
        root->left = buildTree(inorder, &preorder[1], inorder_start, i-1);
    }
    if(i+1 <= inorder_end){
        //if right subtree exist, build right subtree
        root->right = buildTree(inorder, &preorder[(i-inorder_start)+1], i+1, inorder_end);
    }

    return root;
}
*/

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end)
{
    if(inorder_start > inorder_end) return NULL;    //there's no subtree

    static int a = 0;       // a is to take the root position in preOrder
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = preorder[a++];
    root->left = root->right = NULL;

    if(inorder_start == inorder_end){
        //the subtree only has one node
        return root;
    }
    else{
        int i = inorder_start;      //i will be the position of root in inOrder
        while(root->data != inorder[i]) i++;
        root->left = buildTree(inorder, preorder, inorder_start, i-1);
        root->right = buildTree(inorder, preorder, i+1, inorder_end);
    }
}

void showPostorder(Node* root)
{
    if(root == NULL) return;
    else{
        showPostorder(root->left);
        showPostorder(root->right);
        printf("%d ", root->data);
    }
}

