#include <iostream>

using namespace std;

int m, n, p;    //m rows, n cols

void Spiral(int row, int col, int num, int dir, int** matrix, int p)
{
    //row and col is the place to fill
    //num is the number to fill in the place
    //dir is the direction, 1 for right, 2 for down, 3 for left, 4 for up
    //p is the number we want to find
    matrix[row][col] = num;
    if(num == p){
        cout << row+1 << ' ';
        cout << col+1 << endl;
        return;
    }
    switch(dir){
        case 1:
            while(col+1 < n && matrix[row][col+1] == 0){
                num++;
                col++;
                matrix[row][col] = num;
                if(num == p){
                    cout << row+1 << ' ';
                    cout << col+1 << endl;
                    return;
                }
            }
            if(num != m*n)
                Spiral(row+1, col, num+1, 2, matrix, p);
            break;
        case 2:
            while(row+1 < m && matrix[row+1][col] == 0){
                num++;
                row++;
                matrix[row][col] = num;
                if(num == p){
                    cout << row+1 << ' ';
                    cout << col+1 << endl;
                    return;
                }
            }
            if(num != m*n){
                Spiral(row, col-1, num+1, 3, matrix, p);
            }
            break;
        case 3:
            while(col-1 >= 0 && matrix[row][col-1] == 0){
                num++;
                col--;
                matrix[row][col] = num;
                if(num == p){
                    cout << row+1 << ' ';
                    cout << col+1 << endl;
                    return;
                }
            }
            if(num != m*n)
                Spiral(row-1, col, num+1, 4, matrix, p);
            break;
        case 4:
            while(row-1 >= 0 && matrix[row-1][col] == 0){
                num++;
                row--;
                matrix[row][col] = num;
                if(num == p){
                    cout << row+1 << ' ';
                    cout << col+1 << endl;
                    return;
                }
            }
            if(num != m*n)
                Spiral(row, col+1, num+1, 1, matrix, p);
            break;
    }
}

int main()
{
    cin >> m >> n >> p;

    int** matrix;
    matrix = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++){
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    //initial the matrix to zeros
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = 0;
        }
    }

    Spiral(0, 0, 1, 1, matrix, p);
}
