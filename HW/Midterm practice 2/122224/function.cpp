#include <iostream>
#include "function.h"

using namespace std;

void List::InsertHead(int data)
{
    if(head == NULL){
        head = middle = tail = new ListNode(data);
        cnt = 1;
        return;
    }
    ListNode* temp = head;
    head = new ListNode(data);
    head->next = temp;
    temp->prev = head;
    if(cnt%2 == 0)
        middle = middle->prev;
    else
        pos++;
    cnt++;
}

int  List::RemoveHead()
{
    if(head == NULL){
        throw std::out_of_range("out");
    }
    else if(head == tail){
        int ans = head->data;
        delete head;
        head = middle = tail = NULL;
        cnt = pos = 0;
        return ans;
    }
    else{
        int ans = head->data;
        if(cnt%2 == 0)
            pos--;
        else
            middle = middle->next;
        ListNode* temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        head->prev = NULL;
        cnt--;
        return ans;
    }
}

void List::InsertTail(int data)
{
    if(head == NULL){
        head = middle = tail = new ListNode(data);
        cnt = 1;
        return;
    }
    ListNode* temp = tail;
    tail = new ListNode(data);
    temp->next = tail;
    tail->prev = temp;
    if(cnt%2 == 1){
        pos++;
        middle = middle->next;
    }
    cnt++;
}

int  List::RemoveTail()
{
    if(head == NULL){
        throw std::out_of_range("out");
    }
    else if(head == tail){
        int ans = tail->data;
        delete tail;
        head = middle = tail = NULL;
        cnt = pos = 0;
        return ans;
    }
    else{
        int ans = tail->data;
        if(cnt%2 == 0){
            pos--;
            middle = middle->prev;
        }
        ListNode* temp = tail;
        tail = tail->prev;
        delete temp;
        temp = NULL;
        tail->next = NULL;
        cnt--;
        return ans;
    }
}

void List::Swap()
{
    if(head == NULL || head == tail) return;
    ListNode* tempMid = nullptr;
    if(cnt%2 == 0)
        tempMid = head;
    else
        tempMid = tail;

    tail->next = head;
    head->prev = tail;
    head = middle;
    tail = middle->prev;
    tail->next = nullptr;
    head->prev = nullptr;

    middle = tempMid;
}
