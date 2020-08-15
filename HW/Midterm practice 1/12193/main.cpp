#include <iostream>
#include <string>

using namespace std;

typedef struct _Node{
    int data;
    struct _Node* left;
    struct _Node* right;
}Node;

void P(Node* root)
{
    //print out the binary search tree in in-order form
    if(root != NULL){
        P(root->left);
        cout << root->data << ' ';
        P(root->right);
    }
}

int getMax(Node* root)
{
    //print out the maximum height of the binary search tree
    if(root == NULL) return 0;

    int l, r;
    l = getMax(root->left);
    r = getMax(root->right);
    return (l>r)? l+1:r+1;
}

int sumLevel(Node* root, int inputLevel)
{
    //print out the sum value of the nodes at the input level in the line
    if(root == NULL)
        return 0;
    if(inputLevel==1){
        return root->data;
    }
    return sumLevel(root->left, inputLevel-1)+sumLevel(root->right, inputLevel-1);
}

int averLevel(Node* root, int inputLevel)
{
    //count the number of nodes of the inputLevel
    if(root == NULL)
        return 0;
    if(inputLevel==1){
        return 1;
    }
    return averLevel(root->left, inputLevel-1)+averLevel(root->right, inputLevel-1);
}

int main()
{
    int n;      //n nodes
    cin >> n;
    //create binary search tree
    Node* root = NULL;
    if(n!=0){
        root = (Node*)malloc(sizeof(Node));
        cin >> root->data;
        root->left = root->right = NULL;
    }

    Node* pos = root;
    int inputData;
    for(int i = 1; i < n; i++){
        cin >> inputData;
        pos = root;
        while(1){
            //find the right place to insert the node
            if(inputData < pos->data && pos->left != NULL)
                pos = pos->left;
            else if(inputData > pos->data && pos->right != NULL)
                pos = pos->right;
            else if(inputData < pos->data && pos->left == NULL){
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->data = inputData;
                newNode->left = newNode->right = NULL;
                pos->left = newNode;
                break;
            }
            else if(inputData > pos->data && pos->right == NULL){
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->data = inputData;
                newNode->left = newNode->right = NULL;
                pos->right = newNode;
                break;
            }
            else                          //inputData == pos->data
                break;
        }
    }

    //do instructions
    cin >> n;       //n instructions
    string instruction;
    while(n--){
        cin >> instruction;

        if(instruction == "P"){
            if(root == NULL)
                cout << "NULL" << endl;
            else{
                P(root);
                cout << endl;
            }
        }
        else if(instruction == "GetMax"){
            cout << getMax(root) << endl;
        }
        else if(instruction == "SumLevel"){
            cin >> inputData;
            if(inputData == 0)
                cout << "0" << endl;
            else
                cout << sumLevel(root, inputData) << endl;
        }
        else if(instruction == "AverLevel"){
            cin >> inputData;
            if(inputData == 0 || averLevel(root, inputData)==0)
                cout << "0" << endl;
            else{
                printf("%.3f\n", (float)sumLevel(root, inputData)/(float)averLevel(root, inputData));
            }
        }
    }
}
