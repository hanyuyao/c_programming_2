#include <stdio.h>
#include "function.h"

void do_I(Node **head,size_t pos,unsigned short val)
{
    Node* current = *head;
    if(current == NULL){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = val;
        newNode->next = NULL;
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    if(pos==0){
        //insert at the front
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = val;
        newNode->next = current;
        current->prev = newNode;
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    int count = 0;
    while(current != NULL){
        if(pos == count){
            //insert in the middle
            current = current->prev;
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->val = val;
            newNode->next = current->next;
            current->next = newNode;
            newNode->prev = current;
            newNode->next->prev = newNode;
            return;
        }
        count++;
        if(current->next != NULL)
            current = current->next;
        else
            break;
    }
    //insert at the back
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = current;
    current->next = newNode;
}

void do_E(Node **head,size_t begin_pos,size_t end_pos)
{
    Node* current = *head;
    if(begin_pos == end_pos || current==NULL) return;

    int count = 0;
    while(current != NULL){
        if(count == begin_pos){
            Node* end = current;
            while(count != end_pos && end != NULL){
                count++;
                end = end->next;
            }
            //current is the beginning, end is the end(do not delete)
            while(current != end && current->next != NULL){
                //delete current and assign current to the next node
                Node* temp = current;
                current = current->next;
                if(begin_pos != 0){
                    temp->prev->next = current;
                    current->prev = temp->prev;
                }
                else{
                    *head = current;
                    current->prev = NULL;
                }
                free(temp);
            }
            if(end == NULL){
                //erase the last Node ("current" will be the last Node)
                if(begin_pos==0){
                    free(current);
                    *head = NULL;
                }
                else{
                    current->prev->next = NULL;
                    free(current);
                }
            }
            return;
        }
        count++;
        current = current->next;
    }
    //begin position > length of the list
    return;
}

void do_P(Node  *head,size_t pos)
{
    if(head == NULL)
        return;

    int count = 0;
    while(head->next != NULL){
        if(count == pos){
            printf("%hu ", head->val);
            return;
        }
        head = head->next;
        count++;
    }

    printf("%hu ", head->val);
}

void do_R(Node **head,unsigned short val)
{
    Node* current = *head;
    while(current != NULL){
        if(current->val == val){
            //remove current and point current to the next Node
            if(current->prev == NULL){
                //current is the first Node
                if(current->next == NULL){
                    //there's only one Node
                    free(current);
                    *head = NULL;
                    return;
                }
                else{
                    current->next->prev = NULL;
                    *head = current->next;
                    free(current);
                    current = *head;
                }
            }
            else if(current->next == NULL){
                //current is the last Node
                current->prev->next = NULL;
                free(current);
                current = NULL;
            }
            else{
                //current is in the middle
                Node* temp = current->next;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                free(current);
                current = temp;
            }
        }
        else{
            current = current->next;
        }
    }
}

void do_S(Node  *head)
{
    while(head != NULL){
        printf("%hu ", head->val);
        head = head->next;
    }
}
