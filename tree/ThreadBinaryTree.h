/*
 * @FilePath: ThreadBinaryTree.h
 * @Author: Libre Gu
 * @Date: 2023-03-24 09:36:58
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-03-24 20:53:02
 * Copyright: 2023 Libre Gu
 * @Descripttion: 
 */

#include <iostream>
#include <stack>
#include "BinaryNode.h"

using namespace std;

template <class T>
class ThreadBinaryTree
{
private:
    BinaryNode<T>* root;
    BinaryNode<T>* create(T prelist[], int n, int &i);
    void inOrderThread(BinaryNode<T> *root, BinaryNode<T>* &front);
    BinaryNode<T>* inNext(BinaryNode<T> *p);
    BinaryNode<T>* preNext(BinaryNode<T> *p);
    BinaryNode<T>* postPrev(BinaryNode<T> *p);
    void destroy(BinaryNode<T> *p);
public:
    ThreadBinaryTree();
    ThreadBinaryTree(T prelist[], int n);
    ~ThreadBinaryTree();
    void inOrder();
    void preORder();
    void postOrder();
};

template <class T>
ThreadBinaryTree<T>::~ThreadBinaryTree() {
    destroy(root);
}

template <class T>
void ThreadBinaryTree<T>::destroy(BinaryNode<T> *p) {
    if (p!=NULL) {
        if (p->ltag == 0)
            destroy(p->left);
        if (p->rtag == 0)
            destroy(p->right);
        delete p;
    }
}

template <class T>
void ThreadBinaryTree<T>::postOrder() {
    cout<<"中序线索(后序遍历)：";
    BinaryNode<T> *p = root;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p = postPrev(p);
    }
    cout<<endl;
    
}

// 中序线索二叉树中，求一个节点P后根次序的前驱节点
template <class T>
BinaryNode<T>* ThreadBinaryTree<T>::postPrev(BinaryNode<T> *p) {
    // 如果有右孩子，有孩子为前驱节点
    if (p->rtag == 0)
    {
        p = p->right;
    } else  {
        // 如果有左孩子，左孩子为前驱节点
        while (p->ltag == 1 && p->left != NULL)
        {
            p = p->left;
        }
        p = p->left;
        
    }
    
    return p;
}

template <class T>
void ThreadBinaryTree<T>::preORder() {
    cout<<"中序线索(前序遍历)：";
    BinaryNode<T> *p = root;
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = preNext(p);
    }
    cout<<endl;
}

template <class T>
BinaryNode<T>* ThreadBinaryTree<T>::preNext(BinaryNode<T> *p) {
    if (p->ltag == 0)
        p = p->left;
    else {
        while (p->rtag == 1 && p->right != NULL)
        {
            p = p->right;
        }
        p = p->right;
    }
    return p;
    
}

template <class T>
void ThreadBinaryTree<T>::inOrder() {
    cout<<"中序线索(中序遍历)：";
    BinaryNode<T> *p = root;
    while (p!=NULL && p->ltag == 0) {
        p = p->left;
    }
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = inNext(p);
    }
    cout<<endl;
    
}

template <class T>
BinaryNode<T>* ThreadBinaryTree<T>::inNext(BinaryNode<T> *p) {
    if (p->rtag == 1)
    {
        p = p->right;
    } else {
        p = p->right;
        while (p->ltag == 0)
        {
            p = p->left;
        }
        
    }
    return p;
}


template <class T>
void ThreadBinaryTree<T>::inOrderThread(BinaryNode<T> *root, BinaryNode<T>* &front) {
    if (root != NULL)
    {
        inOrderThread(root->left, front);
        if (root->left == NULL) {
            root->left = front;
            root->ltag = 1;
        }
        if (root->right == NULL)
        {
            root->rtag = 1;
        }
        if (front != NULL && front->rtag == 1)
        {
            front->right = root;
        }
        front = root;
        inOrderThread(root->right, front);
    }
    
}

template <class T>
ThreadBinaryTree<T>::ThreadBinaryTree() {
    root = NULL;
}

template <class T>
ThreadBinaryTree<T>::ThreadBinaryTree(T prelist[], int n) {
    int i = 0;
    BinaryNode<T> *front = NULL;
    root = create(prelist, n, i);
    inOrderThread(root, front);
}

template<class T>
BinaryNode<T>* ThreadBinaryTree<T>::create(T prelist[], int n, int &i) {
    BinaryNode<T> *p = NULL;
    if (i < n) {
        T elem = prelist[i];
        i++;
        if (elem != ' ') {
            p = new BinaryNode<T>(elem);
            p->left = create(prelist, n, i);
            p->right = create(prelist, n , i);
        }
    }
    return p;
}
