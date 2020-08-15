#include <iostream>
#include "function.h"

Array_BST::Array_BST()
{
    for(int i = 0; i < 1025; i++)
        array[i] = 0;
    Height = 0;
}

void Array_BST::insert(const int& val) //root node is stored at index 1.
{
    int i = 1, h = 1;
    while(array[i] != 0){
        if(val == array[i]) return;
        else if(val < array[i])
            i *= 2;
        else
            i = i*2 + 1;
        h++;
    }
    array[i] = val;
    Height = (h > Height)? h:Height;
}

bool Array_BST::search(const int& val) const
{
    int i = 1;
    while(array[i] != 0){
        if(array[i] == val) return true;
        else if(val < array[i])
            i *= 2;
        else
            i = i*2 + 1;
    }
    return false;
}

List_BST::List_BST()
{
    root = nullptr;
    Height = 0;
}

void List_BST::insert(const int& val)
{
    if(root == nullptr){
        root = new ListNode(val);
        return;
    }
    int h = 1;
    ListNode* temp = root;
    while(1){
        if(val == temp->key) return;
        else if(val < temp->key && temp->left != nullptr){
            temp = temp->left;
            h++;
        }
        else if(val < temp->key && temp->left == nullptr){
            temp->left = new ListNode(val);
            h++;
            Height = (h > Height)? h:Height;
            return;
        }
        else if(val > temp->key && temp->right != nullptr){
            temp = temp->right;
            h++;
        }
        else{
            temp->right = new ListNode(val);
            h++;
            Height = (h > Height)? h:Height;
            return;
        }
    }
}

bool List_BST::search(const int& val) const
{
    ListNode* temp = root;
    while(temp != nullptr){
        if(temp->key == val) return true;
        else if(val < temp->key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

ListNode* List_BST::createLeaf(int key) const //new a ListNode and return its address
{
    return new ListNode(key);
}

void List_BST::deleteTree(ListNode *root)
{
    if(root != nullptr){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }
}
