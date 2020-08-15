#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec;
    string command;
    string name;
    while(cin >> command){
        if(command == "Push"){
            cin >> name;
            vec.push_back(name);
        }
        else if(command == "Pop"){
            if(!vec.empty())
                vec.erase(vec.begin(), vec.begin()+1);
        }
        else if(command == "Front"){
            if(vec.empty())
                cout << "empty" << endl;
            else
                cout << vec[0] << endl;
        }
        else{}
    }
}
