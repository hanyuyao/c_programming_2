#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int x;
    string command;
    vector<int> vec;
    make_heap(vec.begin(), vec.end());

    while(cin >> command){
        if(command == "PUSH"){
            cin >> x;
            vec.push_back(x);
            push_heap(vec.begin(), vec.end());
        }
        else if(command == "TOP"){
            if(!vec.empty())
                cout << vec.front() << endl;
            else
                cout << "Null" << endl;
        }
        else if(command == "POP"){
            pop_heap(vec.begin(), vec.end());
            vec.pop_back();
        }
        else{}
    }
}
