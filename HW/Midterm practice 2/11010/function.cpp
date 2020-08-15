#include <iostream>
#include <string>
#include "function.h"
using namespace std;

OWList::OWList()    //initializes the two pointers firstPtr and lastPtr as NULL.
{
    firstPtr = lastPtr = nullptr;
}

OWList::~OWList()   //deletes allocated dynamic memory space.
{
    if(firstPtr == nullptr) return;
    ListNode* temp = firstPtr;
    while(firstPtr != lastPtr){
        firstPtr = firstPtr->nextPtr;
        delete temp;
        temp = firstPtr;
    }
    delete firstPtr;
    firstPtr = lastPtr = nullptr;
}

void OWList::insertAtFront( const int &value )
{
    if(firstPtr == nullptr){
        firstPtr = new ListNode(value);
        lastPtr = firstPtr;
    }
    else{
        ListNode* temp = firstPtr;
        firstPtr = new ListNode(value);
        firstPtr->nextPtr = temp;
    }
}

void OWList::removeFromFront()
{
    if(firstPtr == nullptr)
        return;
    else if(firstPtr == lastPtr){
        delete firstPtr;
        firstPtr = lastPtr = nullptr;
    }
    else{
        ListNode* temp = firstPtr;
        firstPtr = firstPtr->nextPtr;
        delete temp;
        temp = nullptr;
    }
}

bool OWList::isEmpty() const
{
    return (firstPtr == nullptr);
}

void OWList::print() const
{
    ListNode* temp = firstPtr;
    while(temp != lastPtr){
        cout << temp->data << ' ';
        temp = temp->nextPtr;
    }
    cout << temp->data;
}

void TWList::insertAtBack( const int &value )
{
    if(firstPtr == nullptr){
        firstPtr = new ListNode(value);
        lastPtr = firstPtr;
    }
    else{
        lastPtr->nextPtr = new ListNode(value);
        lastPtr = lastPtr->nextPtr;
    }
}

void TWList::removeFromBack()
{
    if(firstPtr == nullptr) return;
    else if(firstPtr == lastPtr){
        delete firstPtr;
        firstPtr = lastPtr = nullptr;
    }
    else{
        ListNode* temp = firstPtr;
        while(temp->nextPtr != lastPtr)
            temp = temp->nextPtr;
        delete lastPtr;
        temp->nextPtr = nullptr;
        lastPtr = temp;
    }
}
