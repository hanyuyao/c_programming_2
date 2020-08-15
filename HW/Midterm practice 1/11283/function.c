#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void rotateList(Node** head,int n)
{
    Node* tail = (*head);
    while(tail->next != NULL)
        tail = tail->next;

    int i;
    Node* temp = (*head)->next;
    for(i=0; i<n; i++){
        tail->next = (*head);
        (*head)->next = NULL;
        (*head) = temp;
        tail = tail->next;
        temp = (*head)->next;
    }
}
