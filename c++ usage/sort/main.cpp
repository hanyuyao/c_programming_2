#include <iostream>
#include <algorithm>

using namespace std;

void showArr(int* a, int n)
{
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

bool myCompare(int a, int b)
{
    return (a>b);
}

int main(void)
{
    int a[6] = {4, 2, 5, 1, 3, 6};
    int n = sizeof(a)/sizeof(int);  //n=6

    sort(a, a+n);
    showArr(a, n);

    reverse(a, a+n);
    showArr(a, n);
    cout << endl;


    int b[6] = {4, 2, 5, 1, 3, 6};
    n = sizeof(b)/sizeof(b[0]);

    sort(b, b+n, greater<int>());
    showArr(b, n);
    cout << endl;


    int c[6] = {4, 2, 5, 1, 3, 6};
    n = sizeof(c)/sizeof(c[0]);

    sort(c, c+n, myCompare);
    showArr(c, n);
}
