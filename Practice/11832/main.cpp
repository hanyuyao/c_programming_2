#include <iostream>
#include <string.h>

using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void showCards(Node* head)
{
    while(head != NULL){
        cout << head->data << endl;
        head = head->next;
    }
}

void ADD(Node** head, int idx, int num)
{
    //Add a new card with number num before card idx.
    if(idx==0){
        Node* tempHead = *head;
        *head = (Node*)malloc(sizeof(Node));
        (*head)->data = num;
        (*head)->next = tempHead;
    }
    else{
        Node* temp = *head;
        for(int i = 0; i < idx-1; i++){
            //find the insert position
            temp = temp->next;
        }
        //insert after temp
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = num;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void CUT(Node** head, int a, int b)
{
    //Move cards whose index between a and a+b-1 ( [a, a+b) )
    //to the top of the card stack.
    //Order of the cards inside the moved part won't be changed.
    if(a==0) return;
    else{
        Node* beginNode=(*head);
        Node* endNode=NULL;
        Node* beginNodePrev = (*head);     //the node before begin node
        //find begin node's and endNode's position
        //find beginNodePrev's position
        for(int i = 0; i < a-1; i++){
            beginNodePrev = beginNodePrev->next;
        }
        beginNode = beginNodePrev->next;
        endNode = beginNode;
        for(int i = 0; i < b-1; i++){
            endNode = endNode->next;
        }

        //take to the top
        beginNodePrev->next = endNode->next;
        endNode->next = (*head);
        (*head) = beginNode;
    }
}

void freeList(Node* head)
{
    Node* temp = head;
    while(head->next != NULL){
        head = head->next;
        free(temp);
        temp = head;
    }
    free(head);
}

int main()
{
    int n, m;   //# of cards, # of operations
    cin >> n >> m;

    int temp;
    Node* head = (Node*)malloc(sizeof(Node));
    cin >> temp;
    head->data = temp;
    head->next = NULL;

    Node* tempNode = head;
    for(int i = 1; i < n; i++){
        cin >> temp;
        tempNode->next = (Node*)malloc(sizeof(Node));
        tempNode->next->data = temp;
        tempNode->next->next = NULL;
        tempNode = tempNode->next;
    }

    char s[4];
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> s >> a >> b;
        if(!strcmp(s, "ADD")){
            ADD(&head, a, b);
        }
        if(!strcmp(s, "CUT")){
            CUT(&head, a, b);
        }
    }

    showCards(head);
    freeList(head);
}
