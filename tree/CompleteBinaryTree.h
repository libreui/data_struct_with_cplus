/*
 * @Author: Libre Gu 
 * @Date: 2023-03-22 17:38:30
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-03-22 18:08:45
 * @FilePath: /cpp/tree/CompleteBinaryTree.h
 * @Description: 
 */
#include <iostream>
#include "BinaryTree.h"

using namespace std;

template <class T>
class CompleteBinaryTree: public BinaryTree<T>
{
public:
    CompleteBinaryTree(T levellist[], int n);

private:
    BinaryNode<T>* create(T levellist[], int n, int i);
};

template <class T>
CompleteBinaryTree<T>::CompleteBinaryTree(T levellist[], int n) {
    this->root = create(levellist, n, 0);
}

template <class T>
BinaryNode<T>* CompleteBinaryTree<T>::create(T levellist[], int n, int i) {
    BinaryNode<T> *p = NULL;
    if (i < n)
    {
        p = new BinaryNode<T>(levellist[i]);
        p->left = create(levellist, n, 2 * i + 1);
        p->right = create(levellist, n, 2 * i + 2);
    }
    return p;
}