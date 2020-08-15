#include <iostream>
#include <string>

using namespace std;

typedef struct _Node{
    int data;
    struct _Node* next;
    struct _Node* prev;
}Node;

void printList(Node* head)
{
    while(head != NULL){
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

void removeNode(Node** head, int a)
{
    //remove the node of data a
    Node* temp = (*head);
    while(temp!=NULL && temp->data != a )
        temp = temp->next;
    if(temp == NULL) return;        //a isn't exist in the list

    if(temp->next == NULL && temp->prev == NULL){
        //only one node
        (*head) = NULL;
        free(temp);
    }
    else if(temp==(*head)){
        //remove head
        (*head) = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
    else if(temp->next == NULL){
        //remove tail
        temp->prev->next = NULL;
        free(temp);
    }
    else{
        //remove node in the middle
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void moveOn(Node** head, int a, int b)
{
    //find the position of a
    Node* aPos = (*head);
    while(aPos != NULL && aPos->data != a)
        aPos = aPos->next;
    if(aPos == NULL) return;    //a doesn't exist in the list

    //find the position of b
    Node* bPos = (*head);
    while(bPos != NULL && bPos->data != b)
        bPos = bPos->next;
    if(bPos == NULL) return;    //b doesn't exist in the list

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = a;
    newNode->next = newNode->prev = NULL;
    removeNode(head, a);

    if(bPos->next == NULL){
        //insert newNode at the end of the list
        bPos->next = newNode;
        newNode->prev = bPos;
    }
    else{
        //insert newNode in the middle
        newNode->next = bPos->next;
        newNode->prev = bPos;
        bPos->next->prev = newNode;
        bPos->next = newNode;
    }
}

void moveUnder(Node** head, int a, int b)
{
    //find the position of a
    Node* aPos = (*head);
    while(aPos != NULL && aPos->data != a)
        aPos = aPos->next;
    if(aPos == NULL) return;    //a doesn't exist in the list

     //find the position of b
    Node* bPos = (*head);
    while(bPos != NULL && bPos->data != b)
        bPos = bPos->next;
    if(bPos == NULL) return;    //b doesn't exist in the list

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = a;
    newNode->next = newNode->prev = NULL;
    removeNode(head, a);

    if(bPos->prev == NULL){
        //insert in the front of the list
        newNode->next = bPos;
        bPos->prev = newNode;
        (*head) = newNode;
    }
    else{
        //insert in the middle of the list
        newNode->next = bPos;
        newNode->prev = bPos->prev;
        bPos->prev->next = newNode;
        bPos->prev = newNode;
    }
}

int main()
{
    int n;      //n books
    cin >> n;
    Node* head = NULL;
    Node* tail = NULL;
    Node* temp = NULL;
    if(n != 0){
        //create list
        head = (Node*)malloc(sizeof(Node));
        tail = head;
        head->data = 0;
        head->next = head->prev = NULL;
        for(int i = 1; i < n; i++){
            tail->next = (Node*)malloc(sizeof(Node));
            temp = tail;
            tail = tail->next;
            tail->data = i;
            tail->prev = temp;
            tail->next = NULL;
        }
    }

    string instruction;
    int a, b;
    while(1){
        cin >> instruction;
        if(instruction == "move"){
            cin >> a;
            cin >> instruction;
            if(instruction == "on"){
                cin >> b;
                if(a != b && a < n && b < n)
                    moveOn(&head, a, b);
            }
            else if(instruction == "under"){
                cin >> b;
                if(a != b && a < n && b < n)
                    moveUnder(&head, a, b);
            }
            else{}
        }
        else if(instruction == "remove"){
            cin >> a;
            if(a < n)
                removeNode(&head, a);
        }
        else if(instruction == "exit"){
            printList(head);
            break;
        }
        else{}
    }
}
