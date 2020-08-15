#include "function.h"
#include <iostream>
using namespace std;

Array_BST::Array_BST()
{
    for(int i = 0; i < 1025; i++)
        array[i] = 0;
    Height = 0;
}

void Array_BST::insert(const int& a)
{
    int i = 1, h = 1;
    while(array[i] != 0){
        if(a == array[i]) return;
        else if(a < array[i]){
            i *= 2;
            h++;
        }
        else{
            i = i*2 + 1;
            h++;
        }
    }
    array[i] = a;
    if(i != 1){
        Height = (Height > h)? Height:h;
    }
}

bool Array_BST::search(const int& a) const
{
    int i = 1;
    while(array[i] != 0){
        if(array[i] == a) return true;
        else if(a < array[i])
            i *= 2;
        else
            i = i*2 + 1;
    }
    return false;
}

List_BST::List_BST()
{
    root = new ListNode(0);
    Height = 0;
}

void List_BST::insert(const int& a)
{
    if(root->key == 0){
        root->key = a;
        return;
    }
    ListNode* temp = root;
    int h = 1;
    while(temp != NULL){
        if(a == temp->key) return;
        else if(a < temp->key && temp->left != NULL){
            temp = temp->left;
            h++;
        }
        else if(a < temp->key && temp->left == NULL){
            temp->left = new ListNode(a);
            Height = (Height > h)? Height:h+1;
            return;
        }
        else if(a >= temp->key && temp->right != NULL){
            temp = temp->right;
            h++;
        }
        else{
            temp->right = new ListNode(a);
            Height = (Height > h)? Height:h+1;
            return;
        }
    }
}

bool List_BST::search(const int& a) const
{
    ListNode* temp = root;
    while(temp != NULL){
        if(temp->key == a) return true;
        else if(a < temp->key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

ListNode* List_BST::createLeaf(int key) const
{
    return new ListNode(key);
}

void List_BST::deleteTree(ListNode *root)
{
    if(root != NULL){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}

