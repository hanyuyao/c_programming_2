#include <iostream>
#include "function.h"
using namespace std;

Josephus::Josephus()
{
    generateFib(0);
    noOfPeople = 0;
    head = NULL;
}

Josephus::~Josephus()
{
    delete head;
    head = NULL;
}

Josephus::Josephus(const int& n)
{
    generateFib(n);
    generatecircularlinkedList(n);
    noOfPeople = n;
}

int Josephus::kill()
{
    Node* temp = head;      //temp will be the previous node of head
    for(int i = 0; i < noOfPeople-1; i++)
        temp = temp->next;

    int index = 0;
    while(head->next != head){
        //determine which node to delete
        int m = (sequence[index]-1) % noOfPeople;
        for(int i = 0; i < m; i++){
            head = head->next;
            temp = temp->next;
        }
        index++;

        temp->next = head->next;
        delete head;
        head = temp->next;
        noOfPeople--;
    }

    return head->number;
}

void Josephus::generatecircularlinkedList(const int& n)
{
    if(n <= 0){
        noOfPeople = 0;
        head = NULL;
        return;
    }

    int i = 1;
    head = new Node(i);
    Node* temp = head;
    for(i = 2; i <= n; i++){
        temp->next = new Node(i);
        temp = temp->next;
    }
    temp->next = head;
}

void Josephus::generateFib(const int& n)
{
    sequence[0] = sequence[1] = 1;
    for(int i = 2; i <= 45; i++)
        sequence[i] = sequence[i-1] + sequence[i-2];
    for(int i = 46; i <= 50; i++)
        sequence[i] = 0;
}
