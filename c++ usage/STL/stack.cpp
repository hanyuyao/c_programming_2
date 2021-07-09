#include <iostream>
#include <stack>

using namespace std;

int main(){
    /*
    empty() – Returns whether the stack is empty – Time Complexity : O(1) 
    size() – Returns the size of the stack – Time Complexity : O(1) 
    top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
    push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
    pop() – Deletes the top most element of the stack – Time Complexity : O(1) 
    */

    stack<int> s;
    for(int i = 0; i < 5; i++)
        s.push(i);
    cout << s.size() << endl;

    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}