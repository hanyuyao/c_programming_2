#include "function.h"
#include <iostream>

using namespace std;

void printNode(Node* head)         //the function which will print the output
{
    while(head != nullptr){
        if(head->data != 0)
            cout << ' ' << head->data << ' ' << head->power;
        head = head->next;
    }
}

Node* create()                     //create polynomial linked list
{
    long co;
    int po;
    Node* head = new Node;
    Node* current = head;
    Node* currentPrev;
    cin >> co >> po;
    current->data = co;
    current->power = po;
    current->next = nullptr;
    current->prev = nullptr;
    if(po == 0) return head;

    while(cin >> co >> po){
        currentPrev = current;
        current->next = new Node;
        current = current->next;
        current->data = co;
        current->power = po;
        current->next = nullptr;
        current->prev = currentPrev;
        if(po == 0) return head;
    }
}

void destroy(Node *node)           //destroy polynomial linked list
{
    Node* temp = node;
    while(node->next != nullptr){
        node = node->next;
        delete temp;
        temp = node;
    }
    delete node;
}

Node* multiple(Node* p1, Node* p2) //input two polynomial linked list and return the result
{
    int degree = p1->power + p2->power;
    Node* newList = new Node;
    Node* current = newList;
    current->prev = nullptr;
    current->next = nullptr;
    current->power = degree;
    current->data = 0;

    long co;
    int po;
    for(Node* n1 = p1; n1 != nullptr; n1 = n1->next){
        for(Node* n2 = p2; n2 != nullptr; n2 = n2->next){
            co = n1->data * n2->data;
            po = n1->power + n2->power;
            //if find the power in newlist, add data to it's data
            //else insert a now node of power po, data co
            current = newList;
            if(co != 0)
            while(current != nullptr){
                if(current->power == po){
                    current->data += co;
                    break;
                }
                else if(po < current->power && current->next != nullptr)
                    current = current->next;
                else if(po < current->power && current->next == nullptr){
                    //not found, insert a node at the end
                    Node* temp = new Node;
                    current->next = temp;
                    temp->prev = current;
                    temp->data = co;
                    temp->power = po;
                    break;
                }
                else{
                    //not found, insert a node in the middle
                    Node* temp = new Node;
                    temp->prev = current->prev;
                    temp->next = current;
                    current->prev->next = temp;
                    current->prev = temp;
                    temp->data = co;
                    temp->power = po;
                    break;
                }
            }
        }
    }
    return newList;
}
