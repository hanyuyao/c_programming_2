#include <iostream>

using namespace std;

void bubbleSort(int* inputArr, int n);
void findMax(int* inputArr, int n);

int main()
{
    int n;
    cin >> n;
    int inputArr[n];

    for(int i = 0; i < n; i++)
        cin >> inputArr[i];

    bubbleSort(inputArr, n);

    for(int i = 0; i < n; i++)
        cout << inputArr[i] << ' ';
    cout << endl;
}

void bubbleSort(int* inputArr, int n)
{
    if(n==1) return;
    findMax(inputArr, n);
    bubbleSort(inputArr, n-1);
}

void findMax(int* inputArr, int n)
{
    //move the maximum to the end of the array recursively
    if(n==1) return;
    findMax(inputArr, n-1);
    if(inputArr[n-1] < inputArr[n-2]){
        int temp = inputArr[n-1];
        inputArr[n-1] = inputArr[n-2];
        inputArr[n-2] = temp;
    }
}
