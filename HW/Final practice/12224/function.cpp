#include "function.h"

void List::InsertHead(int data)
{
    if(head == nullptr){
        head = middle = tail = new ListNode(data);
    }
    else{
        ListNode* newNode = new ListNode(data);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        if(cnt % 2 == 0)
            middle = middle->prev;
    }
    cnt++;
}

int List::RemoveHead()
{
    if(head == nullptr){
        throw std::out_of_range("out");
    }
    else if(head == tail){
        int ans = head->data;
        delete head;
        head = middle = tail = nullptr;
        cnt--;
        return ans;
    }
    else{
        int ans = head->data;
        ListNode* temp = head;
        head = head->next;
        delete temp;
        head->prev = nullptr;
        if(cnt % 2 == 1)
            middle = middle->next;
        cnt--;
        return ans;
    }
}

void List::InsertTail(int data)
{
    if(head == nullptr){
        head = middle = tail = new ListNode(data);
    }
    else{
        ListNode* newNode = new ListNode(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        if(cnt % 2 == 1)
            middle = middle->next;
    }
    cnt++;
}

int List::RemoveTail()
{
    if(head == nullptr){
        throw std::out_of_range("out");
    }
    else if(head == tail){
        int ans = tail->data;
        delete tail;
        head = middle = tail = nullptr;
        cnt--;
        return ans;
    }
    else{
        int ans = tail->data;
        ListNode* temp = tail;
        tail = tail->prev;
        delete temp;
        tail->next = nullptr;
        if(cnt % 2 == 0)
            middle = middle->prev;
        cnt--;
        return ans;
    }
}

void List::Swap()
{
    if(head == nullptr || head == tail) return;

    ListNode* tempMiddle = nullptr;
    if(cnt % 2 == 0)
        tempMiddle = head;
    else
        tempMiddle = tail;

    tail->next = head;
    head->prev = tail;
    tail = middle->prev;
    tail->next = nullptr;
    head = middle;
    head->prev = nullptr;
    middle = tempMiddle;
}
