#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<string> vec;
    string input;
    while(cin >> n && n != 0){
    	vec.reserve(n);
        for(int i = 0; i < n; i++){
            cin >> input;
            vec.push_back(input);
        }

        sort(vec.begin(), vec.end());

        for(string s : vec)
            cout << s << endl;
        cout << endl;
        vec.clear();
    }
}
