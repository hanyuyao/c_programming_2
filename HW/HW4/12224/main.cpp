#include <iostream>
#include <string>

using namespace std;

class Node
{
    friend class Chain;     //Chain can use private data directly
public:
    Node(){
        this->data = 0;
        this->next = nullptr;
    }
    Node(const int data, Node* next, Node* prev){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    ~Node(){
        //this->next = nullptr;
    }
private:
    int data;
    Node* next;
    Node* prev;
};

class Chain
{
public:
    Chain(){
        head = nullptr;
        tail = nullptr;
        middle = nullptr;
        n = 0;
    }
    ~Chain(){
        Node* temp = head;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void printChain() const
    {
        if(head != nullptr) cout << head->data << ' ';
        else cout << "null head ";
        if(middle != nullptr) cout << middle->data << ' ';
        else cout << "null middle ";
        if(tail != nullptr) cout << tail->data << ' ';
        else cout << "null tail ";
        cout << n << ' ';
        cout << endl;

        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }

    void IH(const int data)
    {
        if(head == nullptr){
            //empty list
            head = new Node(data, nullptr, nullptr);
            tail = head;
            middle = head;
            n++;
        }
        else{
            head->prev = new Node(data, head, nullptr);
            head = head->prev;
            if(n%2 == 0)
                middle = middle->prev;
            n++;
        }
    }

    void IT(const int data)
    {
        if(head == nullptr){
            //empty list
            head = new Node(data, nullptr, nullptr);
            tail = head;
            middle = head;
            n++;
        }
        else{
            tail->next = new Node(data, nullptr, tail);
            tail = tail->next;
            if(n%2 == 1)
                middle = middle->next;
            n++;
        }
    }

    void RH()
    {
        if(head == nullptr){
            //empty chain
            cout << endl;
        }
        else if(head == tail){
            //only one node
            cout << head->data << endl;
            delete head;
            head = middle = tail = nullptr;
            n = 0;
        }
        else{
            cout << head->data << endl;
            if(n%2 == 1)
                middle = middle->next;
            Node* temp = head->next;
            delete head;
            head = temp;
            head->prev = nullptr;
            n--;
        }
    }

    void RT()
    {
        if(head == nullptr){
            //empty chain
            cout << endl;
        }
        else if(head == tail){
            //only one node
            cout << head->data << endl;
            delete head;
            head = tail = middle = nullptr;
            n = 0;
        }
        else{
            cout << tail->data << endl;
            if(n%2 == 0)
                middle = middle->prev;
            Node* temp = tail->prev;
            delete tail;
            tail = temp;
            tail->next = nullptr;
            n--;
        }
    }

    void S()
    {
        if(head == nullptr || head == tail) return;
        Node* tempMiddle = nullptr;
        if(n%2 == 0)
            tempMiddle = head;
        else if(n%2 == 1)
            tempMiddle = tail;

        tail->next = head;
        head->prev = tail;
        tail = middle->prev;
        tail->next = nullptr;
        head = middle;
        head->prev = nullptr;

        middle = tempMiddle;
    }

private:
    Node* head;
    Node* tail;
    Node* middle;
    int n;      //number of nodes of the chain
};

int main()
{
    string instruction;
    int input;
    Chain myChain;

    while(cin >> instruction && !cin.eof()){
        if(instruction == "IH"){
            cin >> input;
            myChain.IH(input);
        }
        else if(instruction == "IT"){
            cin >> input;
            myChain.IT(input);
        }
        else if(instruction == "RH"){
            myChain.RH();
        }
        else if(instruction == "RT"){
            myChain.RT();
        }
        else if(instruction == "S"){
            myChain.S();
        }
        else if(instruction == "P"){
            myChain.printChain();
        }
        else{}
    }
}
