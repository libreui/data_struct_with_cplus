#include <iostream>
#include <stdexcept>
using namespace std;

class Matrix {
    private:
        int rows, columns;
        int **element;
        void init(int rows, int columns);

    public:
        Matrix(int rows=4, int columns=4);
        Matrix(int *mat, int rows, int columns);
        ~Matrix();
        int get(int i, int j);
        bool set(int i, int j, int value);

        Matrix& operator+=(Matrix &mat) {
            if (this->rows == mat.rows && this->columns == mat.columns) {
                for (int i = 0; i < mat.rows; i++)
                {
                    for (int j = 0; j < mat.columns; j++)
                    {
                        element[i][j] += mat.element[i][j];
                    }
                    return *this;
                    
                }
                
            }
            throw runtime_error("两个矩阵结束不同，不能相加");
        }
        friend ostream& operator<<(ostream& out, Matrix &mat) {
            out<<"矩阵 Matrix ("<<mat.rows<<"X"<<mat.columns<<"): "<<endl;
            for (int i = 0; i < mat.rows; i++)
            {
                for (int j = 0; j < mat.columns; j++)
                {
                    cout<<mat.element[i][j]<< " ";
                }
                cout<<endl;
            }
            
            return out;
        }
};

void Matrix::init(int rows, int columns) {
    if (rows <= 0 || columns <=0)
        throw runtime_error("矩阵行或列数非正数异常");

    this->rows = rows;
    this->columns = columns;

    element = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        element[i] = new int[rows];
        for (int j = 0; j < columns; j++)
        {
            element[i][j] = 0;
        }
        
    }
    
}

Matrix::Matrix(int rows, int columns) {
    init(rows, columns);
}

Matrix::Matrix(int *mat, int rows, int columns) {
    init(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            element[i][j] = *(mat+i*columns+j);
        }
        
    }
    
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++)
    {
        delete element[i];        
    }
    delete element;
    
}

int Matrix::get(int i, int j) {
    if (i >= 0 && i < rows && j >=0 && j < columns)
        return element[i][j];
    throw "矩阵元素的行或列序号越界异常";
}

bool Matrix::set(int i, int j, int value) {
    if (i >= 0 && i < rows && j >=0 && j < columns) {
        element[i][j] = value;
        return true;
    }
    return false;
}
