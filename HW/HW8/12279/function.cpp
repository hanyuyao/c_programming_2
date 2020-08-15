#include "function.h"
#include <vector>

using namespace std;

void buildData(vector<int>& v, Node* root)
{
    if(root){
        v.push_back(root->value);
        buildData(v, root->left);
        buildData(v, root->right);
    }
}

struct Content
{
    vector<int> vec;
    Content(Node* root){
        buildData(vec, root);
    }
};

Iterator::Iterator(Node *root)
{
    if(root == nullptr)
        data = nullptr;
    else
        data = new Content(root);
}

Iterator::Iterator(const Iterator &other)
{
    //copy constructor
    data = other.data;
}

Iterator::~Iterator()
{
    if(data)
        delete ((Content*)data);
}

int Iterator::operator*() const
{
    if(data != nullptr)
        return ((Content*)data)->vec.front();
}

bool Iterator::operator!=(const Iterator &it) const
{
    if(data == nullptr && it.data == nullptr) return false;
    else if(data != nullptr && it.data != nullptr)
        return ((Content*)data)->vec.front() != ((Content*)it.data)->vec.front();
    else
        return true;
}

void Iterator::operator++(int)
{
    if(data==nullptr) return;
    else if(((Content*)data)->vec.size() == 1){
        delete (Content*)data;
        data = nullptr;
    }
    else
        ((Content*)data)->vec.erase(((Content*)data)->vec.begin());
}
