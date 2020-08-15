#include <iostream>

using namespace std;

void insertionSort(int* inputArr, int n);
void reInsertionSort(int* inputArr, int n);

int main()
{
    int n;
    cin >> n;
    int inputArr[n];
    for(int i = 0; i < n; i++){
        cin >> inputArr[i];
    }

    reInsertionSort(inputArr, n);

    for(int i = 0; i < n; i++)
        cout << inputArr[i] << ' ';
    cout << endl;
}

void insertionSort(int* inputArr, int n)
{
    for(int i = 1; i < n; i++){
        int k = i-1;
        int temp = inputArr[i];
        while(temp < inputArr[k] && k >= 0){
            inputArr[k+1] = inputArr[k];
            k--;
        }
        inputArr[k+1] = temp;
    }
}

void reInsertionSort(int* inputArr, int n)
{
    if(n==1) return;
    reInsertionSort(inputArr, n-1);

    int temp = inputArr[n-1];
    int k = n-2;
    while(temp < inputArr[k] && k >= 0){
        inputArr[k+1] = inputArr[k];
        k--;
    }
    inputArr[k+1] = temp;
}
