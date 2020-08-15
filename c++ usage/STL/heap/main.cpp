#include <iostream>
#include <algorithm>    //for heap operations

using namespace std;

int main()
{
    //heap
    //complete binary search tree
    //max heap: root is larger than all of it's children
    vector<int> vec = {2, 3, 1, 5, 4};
    make_heap(vec.begin(), vec.end());     //convert vector into a max heap
    cout << "maximum element: " << vec.front() << endl;

    vec.push_back(6);
    push_heap(vec.begin(), vec.end());
    cout << "maximum element after push: " << vec.front() << endl;

    pop_heap(vec.begin(), vec.end());
    vec.pop_back();
    cout << "maximum element after pop: " << vec.front() << endl;

    //after sorting, the container is no longer a heap
    cout << "heap elements: ";
    for(int i : vec)
        cout << i << ' ';
    cout << endl;
    sort_heap(vec.begin(), vec.end());
    cout << "heap elements after sorting: ";
    for(int i : vec)
        cout << i << ' ';
    cout << endl;

    cout << is_heap(vec.begin(), vec.end()) << endl;
}
