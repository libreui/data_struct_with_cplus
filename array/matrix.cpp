#include <ostream>
#include "matrix.h"
#include "SeqSparseMatrix.h"

using namespace std;

int main() {
    /*    
    const int M=3, N=4;
    Matrix mat1;
    cout<<mat1<<endl;

    int table1[M*N] = {1,0,0,0,0,1};
    Matrix mat2(table1, M, N);
    cout<<mat2<<endl;
    cout<<mat2.get(0,0)<<endl;

    int table2[M][N] = {1,2,3,4,5,6,7,8,9};
    Matrix mat3(&table2[0][0], M, N);
    mat3.set(0, 0, 9);
    cout<<mat3<<endl;

 
    // 矩阵相加
    mat3 += mat2;
    cout<<"矩阵相加\n"<<mat3;
    */
   
    Element itema[] = {{0,2,11},{0,4,17},{4,4,50},{1,1,20},{3,5,28}};
    SeqSparseMatrix smata(5, 6, itema, 5);
    cout << smata << endl;
    cout << smata.get(1, 1) << endl;
    return 0;
}