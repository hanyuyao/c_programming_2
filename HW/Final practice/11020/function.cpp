#include "function.h"

Array_BST::Array_BST()
{
    for(int i = 0; i < 1025; i++)
        array[i] = 0;
    Height = 0;
}

void Array_BST::insert(const int &x)
{
    int i = 1;
    int h = 1;
    while(array[i] != 0){
        if(x > array[i]) i = i*2+1;
        else if(x < array[i]) i = i*2;
        else return;
        h++;
    }
    array[i] = x;
    Height = (Height > h)? Height : h;
}

bool Array_BST::search(const int &x) const
{
    int i = 1;
    while(array[i] != 0){
        if(x > array[i]) i = i*2+1;
        else if(x < array[i]) i = i*2;
        else return true;
    }
    return false;
}

List_BST::List_BST()
{
    root = nullptr;
    Height = 0;
}

void List_BST::insert(const int &x)
{
    ListNode* temp = root;
    int h = 1;
    while(temp != nullptr){
        if(x < temp->key && temp->left != nullptr){
            temp = temp->left;
            h++;
        }
        else if(x < temp->key && temp->left == nullptr){
            temp->left = new ListNode(x);
            h++;
            Height = (Height > h)? Height : h;
            return;
        }
        else if(x > temp->key && temp->right != nullptr){
            temp = temp->right;
            h++;
        }
        else if(x > temp->key && temp->right == nullptr){
            temp->right = new ListNode(x);
            h++;
            Height = (Height > h)? Height : h;
            return;
        }
        else return;
    }
    //root == nullptr
    root = new ListNode(x);
    Height = 1;
}

bool List_BST::search(const int &x) const
{
    ListNode* temp = root;
    while(temp != nullptr){
        if(x < temp->key) temp = temp->left;
        else if(x > temp->key) temp = temp->right;
        else return true;
    }
    return false;
}

ListNode* List_BST::createLeaf(int key) const
{
    return new ListNode(key);
}

void List_BST::deleteTree(ListNode* root)
{
    if(root != nullptr){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
