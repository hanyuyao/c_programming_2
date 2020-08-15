#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool validStr(string input)
{
    //if character below right parenthesis is not left parenthesis, false
    //if stack is not empty at the end, false
    stack<char> sta;
    for(int i = 0; i < input.size(); i++){
        sta.push(input[i]);
        switch(input[i]){
        case '>':
            sta.pop();
            if(sta.empty() || sta.top() != '<')
                return false;
            else
                sta.pop();
            break;
        case ')':
            sta.pop();
            if(sta.empty() || sta.top() != '(')
                return false;
            else
                sta.pop();
            break;
        case ']':
            sta.pop();
            if(sta.empty() || sta.top() != '[')
                return false;
            else
                sta.pop();
            break;
        case '}':
            sta.pop();
            if(sta.empty() || sta.top() != '{')
                return false;
            else
                sta.pop();
            break;
        default:
            break;
        }
    }
    if(sta.empty()) return true;
    else return false;
}

int main()
{
    int n;
    bool valid;
    string input;
    char temp;
    cin >> n;
    temp = getchar();
    for(int i = 1; i <= n; i++){
        temp = getchar();
        if(temp == '\n'){
            valid = true;
        }
        else{
            ungetc(temp, stdin);
            cin >> input;
            temp = getchar();
            valid = validStr(input);
        }

        if(valid)
            cout << "Case " << i << ": Yes" << endl;
        else
            cout << "Case " << i << ": No" << endl;
    }
}
