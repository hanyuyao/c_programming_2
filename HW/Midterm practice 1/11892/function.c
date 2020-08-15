#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end)
{
    static int counting = 0;
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = preorder[counting++];
    root->left = root->right = NULL;

    int i = inorder_start;      //root position in in_order
    while(inorder[i] != root->data) i++;
    if(i > inorder_start){
        root->left = buildTree(inorder, preorder, inorder_start, i-1);
    }
    if(inorder_end > i){
        root->right = buildTree(inorder, preorder, i+1, inorder_end);
    }

    return root;
}

int countingSum(Node* root)
{
    if(root==NULL) return 0;
    if(root->left == NULL && root->right == NULL)
        return root->data;
    else
        return countingSum(root->left)+countingSum(root->right);
}

void caculateLeafNodesSum(Node* root)
{
    printf("%d\n", countingSum(root));
}
