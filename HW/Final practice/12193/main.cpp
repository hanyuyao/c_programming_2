#include <iostream>

using namespace std;

class Node
{
public:
    Node(int d):data(d), left(nullptr), right(nullptr){}
    Node(int d, Node* l, Node* r):data(d), left(l), right(r){}
    int data;
    Node* left;
    Node* right;
};

void Inorder(Node* root)
{
    if(root){
        Inorder(root->left);
        cout << root->data << ' ';
        Inorder(root->right);
    }
}

int Height(Node* root)
{
    if(root == nullptr) return 0;
    int l = Height(root->left);
    int r = Height(root->right);
    return (l > r)? l+1 : r+1;
}

int SumLevel(Node* root, int level)
{
    if(root == nullptr) return 0;

    if(level == 1)
        return root->data;
    else
        return SumLevel(root->left, level-1) + SumLevel(root->right, level-1);
}

int NumOfNodeLevel(Node* root, int level)
{
    if(root == nullptr) return 0;

    if(level == 1)
        return 1;
    else
        return NumOfNodeLevel(root->left, level-1) + NumOfNodeLevel(root->right, level-1);
}

int main()
{
    int n, m;
    int input;
    int height;
    string command;
    Node* root;
    Node* current;

    //build tree
    cin >> n;
    if(n != 0){
        cin >> input;
        root = new Node(input);
    }
    else
        root = nullptr;

    for(int i = 0; i < n-1; i++){
        cin >> input;
        current = root;
        //insert the node
        while(1){
            if(input < current->data && current->left != nullptr){
                current = current->left;
            }
            else if(input < current->data && current->left == nullptr){
                current->left = new Node(input);
                break;
            }
            else if(input > current->data && current->right != nullptr){
                current = current->right;
            }
            else if(input > current->data && current->right == nullptr){
                current->right = new Node(input);
                break;
            }
            else
                break;
        }
    }

    if(root != nullptr) height = Height(root);
    else height = 0;

    cin >> m;
    while(m--){
        cin >> command;
        if(command == "P"){
            if(root == nullptr)
                cout << "NULL" << endl;
            else{
                Inorder(root);
                cout << endl;
            }
        }
        else if(command == "GetMax"){
            cout << height << endl;
        }
        else if(command == "SumLevel"){
            cin >> input;
            if(input > height || input == 0)
                cout << '0' << endl;
            else
                cout << SumLevel(root, input) << endl;
        }
        else if(command == "AverLevel"){
            cin >> input;
            if(input > height || input == 0)
                cout << '0' << endl;
            else
                printf("%.3f\n", (float)SumLevel(root, input)/(float)NumOfNodeLevel(root, input));
        }
    }
}
