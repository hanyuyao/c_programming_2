#include <iostream>
#include <vector>

using namespace std;

void Push(vector<int>& tree)
{
    int k;
    cin >> k;
    tree.push_back(k);

    //if k is larger than it's parent, change value of k and it's parent
    k = tree.size()-1;      //now k marks index of current node
    int p = k/2;            //p marks index of current node's parent
    int temp;
    while(k > 1){
        if(tree[k] > tree[p]){
            temp = tree[k];
            tree[k] = tree[p];
            tree[p] = temp;
            k = p;
            p = k/2;
        }
        else break;
    }
}

void Pop(vector<int>& tree)
{
    if(tree.size() == 1) return;
    //delete root
    tree[1] = tree[tree.size()-1];
    tree.pop_back();

    //maintain max heap
    int k = 1;
    int child;
    int temp;
    while(2*k <= tree.size()-1){        //k has child
        if(2*k <= tree.size()-1 && 2*k+1 <= tree.size()-1){
            //k has two children
            child = (tree[2*k] > tree[2*k+1])? 2*k : 2*k+1;
        }
        else{
            //k only has left child
            child = 2*k;
        }

        if(tree[k] < tree[child]){
            temp = tree[k];
            tree[k] = tree[child];
            tree[child] = temp;
            k = child;
        }
        else break;
    }
}

void Top(vector<int>& tree)
{
    if(tree.size() == 1)
        cout << "Null" << endl;
    else
        cout << tree[1] << endl;
}

int main()
{
    vector<int> tree;
    string command;
    int k;
    int elements = 0;       //number of elements
    tree.push_back(0);      //tree[0] is empty
    while(!cin.eof()){
        cin >> command;
        if(command == "PUSH")
            Push(tree);
        else if(command == "POP")
            Pop(tree);
        else if(command == "TOP")
            Top(tree);
        else{}
    }
}
