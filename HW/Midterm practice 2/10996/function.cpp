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

Josephus::Josephus(const int& a)
{
    generateFib(a);
    noOfPeople = a;
    generatecircularlinkedList(a);
}

int Josephus::kill() // return the survival's position
{
    Node* headPrev = head;
    while(headPrev->next != head) headPrev = headPrev->next;

    int i = 0;
    for(int i = 0; head->next != head; i++, noOfPeople--){
        int k = (sequence[i]-1) % noOfPeople;
        while(k--){
            head = head->next;
            headPrev = headPrev->next;
        }
        headPrev->next = head->next;
        delete head;
        head = headPrev->next;
    }
    return head->number;
}

void Josephus::generatecircularlinkedList(const int& a) // generate circular linked-list
{
    head = new Node(1);
    Node* temp = head;
    for(int i = 2; i <= a; i++){
        temp->next = new Node(i);
        temp = temp->next;
    }
    temp->next = head;
}

void Josephus::generateFib(const int& a) // generate a Fibonacci sequence table
{
    sequence[0] = sequence[1] = 1;
    for(int i = 2; i < a; i++)
        sequence[i] = sequence[i-1] + sequence[i-2];
}
