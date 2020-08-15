#include <iostream>
#include <string.h>
#include <ctime>

#define QUEEN 8

using namespace std;

bool qmap[QUEEN][QUEEN];
int counting = 0;

//check if placing queen at qmap[row][col] is available
bool PlacingQueen(int row, int col)
{
    if(qmap[row][col] == true)
        return false;

    for(int i = 0; i < QUEEN; i++){
        if(col != i && qmap[row][i] == true)
            return false;
        if(row != i && qmap[i][col] == true)
            return false;
    }

    //upper left
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
        if(qmap[i][j] == true)
            return false;
    }
    //upper right
    for(int i = row-1, j = col+1; i >= 0 && j < QUEEN; i--, j++){
        if(qmap[i][j] == true)
            return false;
    }
    //lower left
    for(int i = row+1, j = col-1; i < QUEEN && j >= 0; i++, j--){
        if(qmap[i][j] == true)
            return false;
    }
    //lower right
    for(int i = row+1, j = col+1; i < QUEEN && j <QUEEN; i++, j++){
        if(qmap[i][j] == true)
            return false;
    }

    return true;
}

void PrintMap(void)
{
    for(int i = 0; i < QUEEN; i++){
        for(int j = 0; j < QUEEN; j++){
            cout << qmap[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//print out all of the possible solutions
void AvailableMap(int numOfRow, int numOfCol)
{
    if(numOfRow == QUEEN){
        PrintMap();
        counting++;
        return;
    }

    int col;
    for(col = numOfCol; col < QUEEN; col++){
        if(PlacingQueen(numOfRow, col)){
            qmap[numOfRow][col] = 1;
            break;
        }
    }

    if(col == QUEEN)
        return;
    else
        AvailableMap(numOfRow+1, 0);

    qmap[numOfRow][col] = 0;
    if(col != QUEEN-1)
        AvailableMap(numOfRow, col+1);
    else
        return;
}

int main()
{
    clock_t start = clock();

    memset(qmap, 0, sizeof(bool)*QUEEN*QUEEN);
    AvailableMap(0, 0);
    cout << counting << endl;

    cout << (clock()-start)/(double)CLOCKS_PER_SEC;
}
