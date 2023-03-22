/*
 * @Author: Libre Gu 
 * @Date: 2023-03-08 09:33:32
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-03-08 14:42:36
 * @FilePath: /cpp/array/SeqSparseMatrix.h
 */
#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include "Element.h"

using namespace std;

class SeqSparseMatrix {
    private:
        int rows, columns;
        vector<Element> list;
    
    public:
        SeqSparseMatrix(int rows=4, int columns=4);
        SeqSparseMatrix(int rows, int columns, Element item[], int n);
        ~SeqSparseMatrix();
        int get(int i, int j);
        bool set(int i, int j, int value);
        bool set(Element item);

        friend ostream& operator<<(ostream& out, SeqSparseMatrix &mat) {
            out << "三元组顺序表：\n";
            for (int i = 0; i < mat.list.size(); i++) {
                out << "{";
                out << mat.list[i].row << ",";
                out << mat.list[i].column << ",";
                out << mat.list[i].value;
                out << "} \n";
            }
            out << endl;

            out << "系数矩阵(" << mat.rows << "X" << mat.columns << ")：\n";
            Element elem;
            for (int i = 0; i < mat.rows; i++)
            {
                for (int j = 0; j < mat.columns; j++)
                {

                    int k = 0;
                    bool y = false;
                    while (k < mat.list.size()) 
                    {
                        elem = mat.list[k];
                        if (i == elem.row && j == elem.column) {
                            y = true;
                            break;
                        }
                        k++;
                    } 
                    if (y)
                        out << elem.value << "\t";
                    else {
                        cout << 0 << "\t";
                    }
                }
                out << endl;
                
            }
            
            return out;
        }
        
};

SeqSparseMatrix::~SeqSparseMatrix() {
    
}

SeqSparseMatrix::SeqSparseMatrix(int rows, int columns) {
    if (rows <= 0 || columns <= 0) {
        throw runtime_error("阵列行或列数非正数异常");
    }
    this->rows = rows;
    this->columns = columns;
}

SeqSparseMatrix::SeqSparseMatrix(int rows, int columns, Element item[], int n) {
    if (rows <= 0 || columns <= 0) {
        throw runtime_error("阵列行或列数非正数异常");
    }

    this->rows = rows;
    this->columns = columns;
    for (int i = 0; i < n; i++)
    {
        set(item[i]);
    }
    
    
}

bool SeqSparseMatrix::set(Element item) {
    if (item.row>=0 && item.row < this->rows && item.column>=0 && item.column < this->columns) {
        int k = 0;
        while (k < list.size())
        {
            Element elem = list[k];
            // cout<<"item: {"<<item.row<<","<<item.column<<","<<item.value<<"} ";
            // cout<<"elem: {"<<elem.row<<","<<elem.column<<","<<elem.value<<"}"<<endl;

            // 如果相等了，修改相应位置的值
            if (item.row == elem.row && item.column == elem.column) {
                // elem.value = item.value;
                list[k] = item;
                return true;
            }
            if (elem.row < item.row || elem.row == item.row && elem.column < item.column) {
                k++;
            } else {
                break;
            }
        }
        list.push_back(item);
        return true;
    }
    
    return false;
}

bool SeqSparseMatrix::set(int i, int j, int value) {
    Element elem = {i, j, value};
    return set(elem);
}

int SeqSparseMatrix::get(int i, int j) {
    if (i < 0 || i > rows || j < 0 || j > columns)
        throw runtime_error("矩阵行列序号越界错误");

    int k = 0;
    while (k < list.size())
    {
        Element elem = list[k];
        if (elem.row == i && elem.column == j) {
            return elem.value;
        }
        if (elem.row < rows || elem.row == rows && elem.column < j) {
            k++;
        } else {
            break;
        }
    }
    return 0;
    
}
