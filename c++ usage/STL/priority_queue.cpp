#include <iostream>
#include <queue>
// no need to include <functional>

using namespace std;

int main(){
    // priority_queue<Type, Container, Functional>
    /*
        Type: 數據類型
        Container: 容器類型（Container必須是用數組實現的容器，比如vector,deque等等，但不能用list。STL裏面默認用的是vector）
        Functional: 比較的方式 (less<>, greater<>)
        當需要用自定義的數據類型時才需要傳入這三個參數，使用基本數據類型時，只需要傳入Type，默認是max heap
    */

    priority_queue<int> a;
    // == priority_queue<int, vector<int>, less<int>> a;

    // initialize priority_queue from vector or array
    vector<int> vec = {2, 3, 1, 5, 4};
    int arr[] = {2, 3, 1, 5, 4};

    priority_queue<int> b(vec.begin(), vec.end());
    priority_queue<int> c(arr, arr+5);

    // priority queue member function: empty, top, pop
    while(!b.empty()){
        cout << b.top() << ' ';
        b.pop();
    }
    cout << endl;

    while(!c.empty()){
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;
    cout << "---------------------------------------" << endl;

    // priority queue member function: push, size
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 10; i <= 50; i+=10)
        pq.push(i);
    
    cout << pq.size() << endl;


    // priority queue member function: swap
    priority_queue<int, vector<int>, less<int>> pq_1, pq_2;
    for(int i = 0; i < 3; i++) pq_1.emplace(i);
    for(int i = 3; i < 5; i++) pq_2.emplace(i);
    pq_1.swap(pq_2);

    while(!pq_1.empty()){
        cout << pq_1.top() << ' ';
        pq_1.pop();
    }
    cout << endl;

    while(!pq_2.empty()){
        cout << pq_2.top() << ' ';
        pq_2.pop();
    }
    cout << endl;
}