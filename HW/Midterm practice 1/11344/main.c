#include<stdio.h>
#include"function.h"

void printList(Node* head)
{
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
	}
}

int main(void){
	int n,m;
	scanf("%u %u",&n, &m);
	josephus(m,create(n));
}
