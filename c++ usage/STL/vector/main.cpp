#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector is somewhat the same as string in c++

int main()
{
    //initialize vector
    vector<int> vec;                        //empty vector
    vector<string> vec2(5, "allen");        //capacity=5, all elements are "allen"
    vector<float> vec3(5);                  //capacity=5
    vector<float> vec4(vec3);               //copy vec3
    vector<int> vec5{1, 2, 3, 4, 5};        //direct initialization
    // vector<int> vec5 = {1, 2, 3, 4, 5};  //another way of direct initialization
    int arr[] = {3, 1, 4, 2, 5};
    vector<int> vec6(arr, arr+5);           // vec = [3, 1, 4, 2, 5]
    vector<int> vec7(vec6.begin(), vec6.begin()+3);     //vec = [3, 1, 4]
    string str = "allenyao";
    vector<char> vec8(str.begin(), str.end()):

    // return iterator
    vec.begin();
    vec.end();

    // return value
    vec.front()
    vec.back()

    //assign
    //if an vector has been initialized, use assign
    vec7.assign(10, 0);
    vec7.assign(vec6.begin(), vec6.end());

    //1.add or delete elements
    for(int i = 0; i < 5; i++)
        vec.push_back(i);
    vec.pop_back();
    int i = 2;
    vec.insert(vec.begin()+i, 10);          //insert 10 in position i
    vec.erase(vec.begin()+i);               //erase element in position i
    vec.erase(vec.begin(), vec.begin()+i);  //erase elements form 0 to i-1
    vec.clear();                            //clear the vector

    //2.access element
    for(int i = 0; i < 5; i++)
        vec.push_back(i);         //allocate memory consume a lot of time
    cout << vec[3] << endl;       //vec[3] equals to vec.at(3)
    cout << vec.at(3) << endl;    /*if index out of bound, vec.at(i) will throw an exception*/
    cout << vec.front() << endl;  //first element
    cout << vec.back() << endl;   //last element

    //3.size and capacity
    bool b = vec.empty();
    vec.size();                   //how many elements in vector now
    vec.capacity();               //can hold how many elements
    vec.resize(5, 9);             //if(size<5) push_back 9 until size=5, else size=5
    vec.resize(3);                //equals to resize(3,0)
    vec.reserve(20);              //if capacity<20, capacity=20, size remain unchanged

    //4.iterator
    vec.begin();                  //return an iterator pointing to the first element
    vec.end();                    //return an iterator pointing to the next element of the last element
    vec.rbegin();                 //return an reverse iterator pointing to the last element
    vec.rend();                   //return an reverse iterator pointing to the previous element of the first element

    //5.iterate the vector
    // the range is [begin(), end())
    for(auto i : vec)
        cout << i << ' ';
    cout << endl;

    vector<int>::iterator it;     //think of iterator as an smarter pointer
    for(it = vec.begin(); it != vec.end(); it++)
        cout << *it << ' ';
    cout << endl;

    //6.sorting & find (need to include <algorithm>)
    sort(vec.begin(), vec.begin()+2);
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    vector<int>::iterator itF;
    itF = find(vec.begin(), vec.end(), 2);
    if(itF != vec.end()) cout << *itF << endl;
    else cout << "Not found!" << endl;

    //insert vs. emplace
    //Emplace takes the arguments necessary to construct an object in place,
    //whereas insert takes (a reference to) an object.
    struct Foo
    {
        Foo(int d, double dd):data(d), ddata(dd){}
        int data;
        double ddata;
    };
    std::vector<Foo> v;
    v.insert(v.end(), Foo(10, 123.123));    //equals to v.push_back(Foo(10, 123.123));
    v.emplace(v.end(), 20, 456.456);
    for(auto i : v)
        cout << i.data << ' ' << i.ddata << ' ' << endl;

    // move all elements in A to B, and clear vector A
    vector<int> A = {1, 2, 3};
    vector<int> B = {};
    B = move(A);
}
