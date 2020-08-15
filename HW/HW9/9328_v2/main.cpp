#include <iostream>
#include <queue>

using namespace std;

int main()
{
    string command;
    string name;
    queue<string> q;
    while(cin >> command){
        if(command == "Push"){
            cin >> name;
            q.push(name);
        }
        else if(command == "Front"){
            if(q.empty())
                cout << "empty" << endl;
            else
                cout << q.front() << endl;
        }
        else if(command == "Pop"){
            if(!q.empty())
                q.pop();
        }
        else{}
    }
}
