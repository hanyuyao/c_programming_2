#include <iostream>
#include <string.h>

using namespace std;

using Node = struct _node {
    int data;
    struct _node* next;
    struct _node* prev;
};

void InsertHead(Node* &head, Node* &tail){

    if (head == nullptr) {
    } else {
    }
}

void RemoveHead(Node* &head, Node* &tail){
    Node* temp;

    if (head == nullptr){
        cout << endl;
    } else {
        cout << head->data<<endl;
    }
}

void InsertTail(Node* &head, Node* &tail){
    if (tail == nullptr) {
    } else {
    }
}

void RemoveTail(Node* &head, Node* &tail){
    Node* temp;

    if (tail == nullptr){
        cout << endl;
    } else {
        cout << tail->data <<endl;
    }
}

void Swap(Node* &head, Node* &tail){
    int i, cnt=0, mid;
    Node* temp;

    // count the number of nodes

    // if cnt == 0 or cnt == 1, do nothing
    if (cnt>1) {
        // find the middle node

        // link the head and tail to form
        // a circular doubly linked list

        // break the circular list from the middle node
    }
}

int main(){
    Node *head=nullptr, *tail=nullptr;
    char cmd[4];
    int data;

    while(cin >> cmd){
        if(strcmp(cmd, "IH")==0){ // insert an integer to the head
            InsertHead(head, tail);
        } else if (strcmp(cmd, "IT")==0){ // insert an integer to the end
            InsertTail(head, tail);
        } else if (strcmp(cmd,"RH")==0){   // print and remove a node from head
            RemoveHead(head, tail);
        } else if (strcmp(cmd, "RT") == 0) {// print and remove a node from tail
            RemoveTail(head, tail);
        } else if (strcmp(cmd, "S")==0){
            Swap(head, tail);
        }
    }
}
