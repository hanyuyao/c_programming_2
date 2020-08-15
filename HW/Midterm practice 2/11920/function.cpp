#include "function.h"
#include <iostream>
using namespace std;

Matrix Matrix::operator*(const Matrix &a) const
{
    Matrix ans(this->size_row, a.size_col);
    for(int i = 0; i < this->size_row; i++)
        for(int j = 0; j < a.size_col; j++)
            ans.arr[i][j] = 0;

    for(int i = 0; i < this->size_row; i++){
        for(int j = 0; j < a.size_col; j++){
            for(int k = 0; k < this->size_col; k++){
                ans.arr[i][j] += this->arr[i][k] * a.arr[k][j];
            }
        }
    }
    return ans;
}

Matrix Matrix::operator=(const Matrix &a)
{
    for(int i = 0; i < a.size_row; i++){
        for(int j = 0; j < a.size_col; j++){
            this->arr[i][j] = a.arr[i][j];
        }
    }
    return a;
}

Matrix MatrixChain::calc(int l, int r) const
{
    if(l == r-1)
        return (*arr[l]);
    else
        return (*arr[l]) * calc(l+1, r);
}
