#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    clock_t start = clock();
    cout << "hahahahaha" << endl;
    for(int i = 0; i < 5000; i++)
        cout << "a";
    cout << endl;
    clock_t stop = clock();

    cout << (stop - start)/(double)CLOCKS_PER_SEC << endl;
}
