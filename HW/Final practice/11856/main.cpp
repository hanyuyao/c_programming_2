#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    char c;
    int x;
    int op1, op2;
    stack<int> s;

    while(cin >> c && c != '0'){
        if(c == '+'){
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            s.push(op1 + op2);
        }
        else if(c == '-'){
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            s.push(op1 - op2);
        }
        else if(c == '*'){
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            s.push(op1 * op2);
        }
        else if(c == '/'){
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            s.push(op1 / op2);
        }
        else{
            ungetc(c, stdin);
            cin >> x;
            s.push(x);
        }
    }
    cout << s.top() << endl;
}
