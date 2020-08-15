#include "function.h"
#include <iostream>
using namespace std;

Matrix Matrix::operator*(const Matrix &a) const
{
    Matrix m(size_row, a.size_col);
    for(int i = 0; i < size_row; i++){
        for(int j = 0; j < a.size_col; j++){
            m.arr[i][j] = 0;
        }
    }

    for(int i = 0; i < size_row; i++){
        for(int j = 0; j < a.size_col; j++){
            for(int k = 0; k < size_col; k++){
                m.arr[i][j] += arr[i][k] * a.arr[k][j];
            }
        }
    }
    return m;
}

Matrix Matrix::operator=(const Matrix &a)
{
    size_row = a.size_row;
    size_col = a.size_col;
    for(int i = 0; i < a.size_row; i++){
        for(int j = 0; j < a.size_col; j++){
            arr[i][j] = a.arr[i][j];
        }
    }
}

Matrix MatrixChain::calc(int l, int r) const
{
    /*
    //recursion version
    if(l == r-1)
        return (*arr[r-1]);
    else
        return (*arr[l])*calc(l+1, r);
    */

    Matrix ans(arr[l]->get_size_row(), arr[l]->get_size_row());
    for(int i = l; i < r; i++){
        ans = ans * (*arr[i]);
    }
    return ans;
}
