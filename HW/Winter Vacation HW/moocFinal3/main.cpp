#include <iostream>

using namespace std;

int find_max(int row, int col, int** matrix)
{
    //find maximum in the 3*3 block base on the upper left row and col
    int maxNum = 0;
    for(int i = row; i < row+3; i++){
        for(int j = col; j < col+3; j++){
            maxNum = (matrix[i][j] > maxNum)? matrix[i][j]:maxNum;
        }
    }
    return maxNum;
}

int main()
{
    int n;
    cin >> n;

    int** matrix;
    matrix = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];

    for(int row = 0; row < n-2; row++){
        for(int col = 0; col < n-2; col++){
            cout << find_max(row, col, matrix);
            if(col != n-3) cout << ' ';
        }
        cout << endl;
    }


    return 0;
}
