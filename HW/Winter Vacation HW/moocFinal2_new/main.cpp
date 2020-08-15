#include <iostream>

using namespace std;

int m, n;
int counting = 0;

bool Valid(int* queen, int* castle, int row, int col, int type)
{
    //type = 0, queen, type = 1, castle
    for(int i = 0; i < row; i++){
        if(queen[i] != -1){
            //row i had been put queen
            if(queen[i]==col || (row-i)==(col-queen[i]) || (row-i)==(queen[i]-col)){
                return 0;
            }
        }
        if(castle[i] != -1){
            //row i had been put castle
            if(castle[i]==col) return 0;
            if(type==0){
                if((row-i)==(castle[i]-col) || (row-i)==(col-castle[i]))
                    return 0;
            }
        }
    }
    return 1;
}

void Place(int* queen, int* castle, int row, int restQueen, int restCastle)
{
    if(row == m+n){
        counting++;
        return;
    }

    for(int i = 0; i < m+n; i++){
        if(Valid(queen, castle, row, i, 0) && restQueen){
            queen[row] = i;
            Place(queen, castle, row+1, restQueen-1, restCastle);
            queen[row] = -1;
        }
        if(Valid(queen, castle, row, i, 1) && restCastle){
            castle[row] = i;
            Place(queen, castle, row+1, restQueen, restCastle-1);
            castle[row] = -1;
        }
    }
}

int main()
{
    cin >> m >> n;
    int queen[m+n] = {-1};      //queen[row] = col
    int castle[m+n] = {-1};     //castle[row] = col

    for(int i = 0; i < m+n; i++){
        queen[i] = -1;
        castle[i] = -1;
    }

    Place(queen, castle, 0, m, n);
    cout << counting << endl;
}
