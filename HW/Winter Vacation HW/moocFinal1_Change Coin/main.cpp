#include <iostream>

using namespace std;

void Show(int n, int* numOfCoin);
void ChangeCoin(int n, int* numOfCoin, int* vauleOfCoin, int presentValueIndex, int totalMoney);

int main()
{
    int n;
    cin >> n;

    int valueOfCoin[n];
    for(int i = 0; i < n; i++)
        cin >> valueOfCoin[i];

    int money;
    cin >> money;

    int numOfCoin[n];
    for(int i = 0; i < n; i++)
        numOfCoin[i] = 0;

    ChangeCoin(n, numOfCoin, valueOfCoin, 0, money);
    return 0;
}

void Show(int n, int* numOfCoin)
{
    cout << '(' << numOfCoin[0];
    for(int i = 1; i < n; i++){
        cout << ',' << numOfCoin[i];
    }
    cout << ')' << endl;
}

void ChangeCoin(int n, int* numOfCoin, int* valueOfCoin, int presentValueIndex, int totalMoney)
{
    //presentValueIndex refer to what's the value we use to change now, it's the index of valueOfCoin
    //totalMoney is the rest money need to change
    if(totalMoney == 0){
        Show(n, numOfCoin);
        return;
    }
    if(totalMoney < 0){
        return;
    }
    if(totalMoney > 0 && totalMoney < valueOfCoin[0]){
        return;
    }

    if(presentValueIndex < n && valueOfCoin[presentValueIndex+1] <= totalMoney)
        ChangeCoin(n, numOfCoin, valueOfCoin, presentValueIndex+1, totalMoney);
    if(valueOfCoin[presentValueIndex] <= totalMoney){
        numOfCoin[presentValueIndex]++;
        ChangeCoin(n, numOfCoin, valueOfCoin, presentValueIndex, totalMoney-valueOfCoin[presentValueIndex]);
        numOfCoin[presentValueIndex]--;
    }
    else
        return;



    //integrated way to write
/*
    if(presentValueIndex < n){
        if(totalMoney == 0){
            Show(n, numOfCoin);
            return;
        }
        if(totalMoney > 0 && valueOfCoin[presentValueIndex] <= totalMoney){
            //first way to change
            ChangeCoin(n, numOfCoin, valueOfCoin, presentValueIndex+1, totalMoney);

            //second way to change
            numOfCoin[presentValueIndex]++;
            ChangeCoin(n, numOfCoin, valueOfCoin, presentValueIndex, totalMoney-valueOfCoin[presentValueIndex]);
            numOfCoin[presentValueIndex]--;
        }
    }
*/
}
