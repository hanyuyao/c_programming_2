#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    int root;
    int p, c;
    map<int, vector<int>> mapNode;
    map<int, vector<int>>::iterator it;
    int countLeave;

    while(cin >> n){
        if(n == 0) break;
        //build tree
        while(n--){
            cin >> p >> c;
            it = mapNode.find(p);
            if(it == mapNode.end()){
                //p doesn't exist
                vector<int> vec;
                vec.push_back(c);
                mapNode[p] = vec;
            }
            else{
                //p has already exist
                it->second.push_back(c);
            }
            if(mapNode.find(c) == mapNode.end()){
                //c doesn't exist
                vector<int> vec;
                mapNode[c] = vec;
            }
        }

        cin >> root;
        countLeave = 0;
        for(auto i : mapNode){
            if(i.second.empty())
                countLeave++;
        }
        cout << countLeave << endl;
        mapNode.clear();
    }
}
