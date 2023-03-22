#include <iostream>

using namespace std;

int** create2DArray(int rows, int cols) {
    int** mat = new int*[rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new int[cols];
    }
    return mat;
}

void print(int** mat, int row, int cols) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
}

void dili2DArray(int** mat, int row) {
    for (int i = 0; i < row; i++)
    {
        delete mat[i];
    }
    delete mat;
    
}

void upmat(int n, bool up=true) {
    int **mat = create2DArray(n, n);
    int k=1, sum, i, j;
    // 上三角处理
    for (sum = 0; sum < n; sum++)
    {
        if (up) {
            for (i = sum; i >= 0; i--)
            {
                mat[i][sum - i] = k++;
            }
        } else {
            for (i = 0; i <= sum; i++)
            {
                mat[i][sum - i] = k++;
            }
            
        }
        up = !up;
    }

    // 处理下三角
    for (int sum = n; sum < 2 * n - 1; sum++)
    {
        if (up) {
            for (j = sum-n+1; j < n; j++)
            {
                mat[sum-j][j] = k++;
            }
        } else {
            for (j = n-1; j > sum-n; j--)
            {
                mat[sum-j][j] = k++;
            }
            
        }

        up = !up;
    }
    print(mat, n, n);
    dili2DArray(mat, n);
}

int main() {
    int n = 4;
    upmat(n, false);
    return 0;
}