#include <iostream>
#include <ctime>

#define QUEEN 8

using namespace std;

/* q[i] 記錄的是在第 i 列 (row) 出現的皇后，要擺在第幾行 (column) */
/* 譬如，q[] 的內容如果是 {2, 0, 3, 1}，表示四個皇后分別放在棋盤的 (0,2), (1,0), (2,3), (3,1) 四個位置 */

int q[QUEEN] = {0};
int counting = 0;

bool Valid(int row, int col)
{
    for(int i = 0; i < row; i++){
        if(q[i]==col || (row-i)==(col-q[i]) || (row-i)==(q[i]-col))
            return 0;
    }
    return 1;
}

void PrintMap(void)
{
    for(int i = 0; i < QUEEN; i++){
        for(int j = 0; j < QUEEN; j++){
            if(q[i] == j)
                cout << 1 ;
            else
                cout << 0 ;
        }
        cout << endl;
    }
    cout << endl;
}

void Place(int row)
{
    if(row == QUEEN){
        PrintMap();
        counting++;
    }
    else{
        for(int j = 0; j < QUEEN; j++){
            if(Valid(row, j)){
                q[row] = j;
                Place(row+1);
            }
        }
    }
}

int main()
{
    clock_t start = clock();

    Place(0);
    cout << counting << endl;

    cout << (clock()-start)/(double)CLOCKS_PER_SEC << endl;
}
