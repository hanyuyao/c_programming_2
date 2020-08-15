#include <iostream>

using namespace std;

typedef struct _Node{
    char data;
    struct _Node* left;
    struct _Node* right;
}Node;

Node* buildTree(void)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    cin >> newNode->data;

    if(newNode->data=='|' || newNode->data=='&'){
        newNode->left = buildTree();
        newNode->right = buildTree();
    }
    else{
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

void preorder(Node* root)
{
    if(root != NULL){
        cout << root->data << ' ';
        preorder(root->left);
        preorder(root->right);
    }
}

bool calculate(bool* id, Node* root)
{
    if(root->data == '|'){
        return calculate(id, root->left)||calculate(id, root->right);
    }
    else if(root->data == '&'){
        return calculate(id, root->left)&&calculate(id, root->right);
    }
    else{
        switch(root->data){
        case 'A':
            return id[0];
            break;
        case 'B':
            return id[1];
            break;
        case 'C':
            return id[2];
            break;
        case 'D':
            return id[3];
            break;
        default:
            return id[0];
            break;
        }
    }
}

void permutation(bool* id, int n, Node* root)
{
    if(n == 4){
        for(int i = 0; i < 4; i++)
            cout << id[i] << ' ';
        cout << calculate(id, root) << endl;
    }
    else{
        id[n] = 0;
        permutation(id, n+1, root);
        id[n] = 1;
        permutation(id, n+1, root);
    }
}

int main()
{
    Node* root = buildTree();
    bool id[4] = {false};
    permutation(id, 0, root);
}
