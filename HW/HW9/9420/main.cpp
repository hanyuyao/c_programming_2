#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    int first, second;
    int root;
    set<int> setParent;
    set<int> setChildren;

    while(cin >> n){
    	if(n == 0) break;
		while(n--){
            cin >> first >> second;
            setParent.insert(first);
            setChildren.insert(second);
        }
        cin >> root;

        int counting = setChildren.size();
        for(auto i : setParent){
            if(setChildren.find(i) != setChildren.end())        //i exist in setChildren
                counting--;
        }
        cout << counting << endl;
    }
}
