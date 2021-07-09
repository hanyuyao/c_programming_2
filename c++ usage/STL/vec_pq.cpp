#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

int main(){
    vector<int> vec{2, 3, 1, 5, 4};
    // greater<int>(): sort value from large to small
    // default: less<>()
    sort(vec.begin(), vec.end(), greater<int>());
    for(auto x : vec)
        cout << x << ' ';
    cout << endl;

    // greater<int>: min-heap
    // default: less<>: max-heap
    priority_queue<int, vector<int>, greater<int>> pq(vec.begin(), vec.end());
    while(!pq.empty()){
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << endl;
}