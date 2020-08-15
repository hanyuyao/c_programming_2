#include<stdio.h>
#include"function.h"

Node* create(int n)
{
    if(n==0) return NULL;

    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = head;

    Node* current = head;
    for(int i = 2; i <= n; i++){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        current->next = newNode;
        newNode->next = head;
        current = current->next;
    }

    return head;
}

void josephus(int m,Node *head)
{
    int i;
    Node* nodeDelete = NULL;
    Node* nodeDeletePrev = NULL;

    for(i = 0; i < m-2; i++){
        head = head->next;
    }

    while(head->next != head){
        nodeDeletePrev = head;
        nodeDelete = head->next;
        printf("%d ", nodeDelete->data);

        nodeDeletePrev->next = nodeDelete->next;
        free(nodeDelete);

        for(i = 0; i < m-1; i++){
            head = head->next;
        }
    }
    printf("%d\n", head->data);
}
