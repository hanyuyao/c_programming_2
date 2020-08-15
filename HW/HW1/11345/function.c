#include <stdio.h>
#include <stdlib.h>
#include "function.h"

man* createList(int n)
{
    int i;
    man* curr;
    head = (man*)malloc(sizeof(man));
    curr = head;
    curr->id = 1;
    for(i=2; i<=n; i++){
        curr->next = (man*)malloc(sizeof(man));
        curr->next->prev = curr;
        curr = curr->next;
        curr->id = i;
    }
    curr->next = head;
    head->prev = curr;

    return head;
}


int solveJosephus(int step)
{
    int i;
    int dir = 1;    //1:next, 0:previous
    while(head->next != head){
        if(dir){
            //go in the direction next, and find the man to kill
            for(i = 1; i < step; i++){
                head = head->next;
            }
            //erase the man (head)
            man* temp = head->prev;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            free(head);
            head = temp;
            dir = 0;
        }
        else{
            //go in the direction previous, and find the man to kill
            for(i = 1; i < step; i++){
                head = head->prev;
            }
            //erase the man (head)
            man* temp = head->next;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            free(head);
            head = temp;
            dir = 1;
        }
    }

    return head->id;
}
