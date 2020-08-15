#include <stdio.h>
#include "function.h"

Node* createList()
{
    int input;
    scanf("%d", &input);

    if(input == -1)
        return NULL;

    Node* a = (Node*)malloc(sizeof(Node));
    a->data = input;
    a->next = createList();

    return a;
}


Node* reverse(Node* a)
{
    Node* previous = NULL;
    Node* current = a;
    Node* preceding = a->next;

    while(current->next != NULL){
        current->next = previous;
        previous = current;
        current = preceding;
        preceding = preceding->next;
    }

    current->next = previous;

    return current;
}
