#include "function.h"
#include <stdio.h>

void printNode(Node* head)         //the function which will print the output
{
    while(head != NULL){
        if(head->data != 0){
            printf(" %ld", head->data);
            printf(" %d", head->power);
        }
        head = head->next;
    }
}

Node* create()                     //create polynomial linked list
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    scanf("%ld", &(newNode->data));
    scanf("%d", &(newNode->power));
    newNode->prev = newNode->next = NULL;

    if(newNode->power != 0){
        Node* nextNode = create();
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }
    return newNode;
}

void destroy(Node *node)           //destroy polynomial linked list
{
    Node* temp = node;
    while(node != NULL){
        node = node->next;
        free(temp);
        temp = node;
    }
}

Node* multiple(Node* p1, Node* p2) //input two polynomial linked list and return the result
{
    //create the head of the list
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->power = p1->power + p2->power;
    head->next = head->prev = NULL;

    Node* operand_1 = p1;
    Node* operand_2 = p2;
    Node* current = head;
    long tempData;
    int tempPower;

    //multiple
    for(operand_1 = p1; operand_1 != NULL; operand_1 = operand_1->next)
    {
        for(operand_2 = p2; operand_2 != NULL; operand_2 = operand_2->next)
        {
            tempData = operand_1->data * operand_2->data;
            tempPower = operand_1->power + operand_2->power;

            //find the right place with the same power in (Node* head)
            //add the tempData into the data of the node
            //if no match, create a new node
            for(current = head; current != NULL; current = current->next)
            {
                if(current->power == tempPower){
                    current->data += tempData;
                    break;
                }
                else if(current->power < tempPower){
                    //insert a new node before current
                    Node* newNode = (Node*)malloc(sizeof(Node));
                    newNode->data = tempData;
                    newNode->power = tempPower;

                    current->prev->next = newNode;
                    newNode->prev = current->prev;
                    newNode->next = current;
                    current->prev = newNode;
                    break;
                }
                else{}

                if(current->next == NULL){
                    //insert a new node at the end of the list
                    Node* newNode = (Node*)malloc(sizeof(Node));
                    newNode->data = tempData;
                    newNode->power = tempPower;

                    current->next = newNode;
                    newNode->prev = current;
                    newNode->next = NULL;
                    break;
                }
            }
        }
    }

    return head;
}
