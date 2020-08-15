#include <iostream>

using namespace std;

int findMax(int* inputArr, int n)
{
    if(n==1)
        return inputArr[0];

    int k = findMax(inputArr, n-1);

    if(k > inputArr[n-1])
        return k;
    else
        return inputArr[n-1];
}

int main()
{
    int n;
    cin >> n;

    int inputArr[n];
    for(int i = 0; i < n; i++)
        cin >> inputArr[i];

    cout << findMax(inputArr, n) << endl;;
}
