/*
 * @Author: Libre Gu 
 * @Date: 2023-03-16 09:18:15
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-03-16 10:11:37
 * @FilePath: /cpp/tree/BinaryNode.h
 */
#include <iostream>
using namespace std;

template <class T>
class BinaryNode
{
public:
    T data;
    BinaryNode<T> *left,*right;
    BinaryNode(T data, BinaryNode<T> *left=NULL, BinaryNode<T> *right=NULL) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};