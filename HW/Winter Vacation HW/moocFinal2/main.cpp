/*
#include <iostream>
#include <math.h>

using namespace std;

int m, n;
int counting = 0;   //number of valid (m+n)*(m+n) map, which put (m+n) queens on

int Factorial(int a)
{
    if(a==1)
        return 1;
    else
        return a*Factorial(a-1);
}

int Combination(int m, int n)
{
    //C m take n
    int ans = 1;
    int k = m;
    for(int i = 1; i <= n; i++){
        ans *= k;
        ans /= i;
        k--;
    }
    return ans;
}

bool Valid(int row, int col, int* q)
{
    for(int i = 0; i < row; i++){
        if(q[i]==col || (row-i)==(col-q[i]) || (row-i)==(q[i]-col))
            return 0;
    }
    return 1;
}

void PrintMap(int* q)
{
    for(int i = 0; i < (m+n); i++){
        for(int j = 0; j < (m+n); j++){
            if(q[i] == j)
                cout << 1 ;
            else
                cout << 0 ;
        }
        cout << endl;
    }
    cout << endl;
}

void Place(int row, int* q)
{
    if(row == (m+n)){
        //PrintMap(q);
        counting++;
    }
    else{
        for(int j = 0; j < (m+n); j++){
            if(Valid(row, j, q)){
                q[row] = j;
                Place(row+1, q);
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    int q[m+n] = {0};

    Place(0, q);        //calculate variable "counting"

    //all castles
    if(m==0){
        cout << Factorial(n) << endl;
        return 0;
    }

    int putCastle = Combination(m+n, n);
    cout << putCastle*counting << endl;
}
*/
