#include <iostream>
#include <queue>

using namespace std;

int main(){
    /*
    push: 把值加到尾巴
    pop: 移除頭的值
    back: 回傳尾巴的值
    front: 回傳頭的值
    size: 回傳目前長度
    empty: 回傳是否為空
    */

    queue<int> q;
    for(int i = 0; i < 5; i++)
        q.push(i);
    cout << q.size() << endl;
    cout << q.front() << ' ' << q.back() << endl;

    while(!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;
}