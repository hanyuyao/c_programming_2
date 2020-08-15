#include <iostream>
#include <stdlib.h>

using namespace std;

int BinarySearch(int data[], int start, int end, int key)
{
    if(start > end) return -1;

    int i = start + (end-start)/2;

    if(data[i] == key) return i;
    else if(data[i] > key)
        return BinarySearch(data, start, i-1, key);
    else return
        BinarySearch(data, i+1, end, key);
}

int main()
{
    int n;
    int key;
    cin >> n;
    int *data = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        cin >> data[i];

    cin >> key;
    cout << BinarySearch(data, 0, n-1, key) << endl;
}
