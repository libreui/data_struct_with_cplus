/*
 * @Author: Libre Gu 
 * @Date: 2023-03-16 09:18:15
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-03-24 10:15:54
 * @FilePath: BinaryNode.h
 */
#ifndef BINARYTREE_BINARYNODE_H
#define BINARYTREE_BINARYNODE_H
#include <iostream>
using namespace std;

template <class T>
class BinaryNode
{
public:
    T data;
    BinaryNode<T> *left,*right;
    int ltag, rtag;
    BinaryNode(T data, BinaryNode<T> *left=NULL, BinaryNode<T> *right=NULL) {
        this->data = data;
        this->left = left;
        this->right = right;
        this->ltag = this->rtag = 0;
    }
};
#endif //BINARYTREE_BINARYNODE_H