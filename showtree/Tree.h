/*
 * @Author: Libre Gu 
 * @Date: 2023-04-26 13:29:33
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-04-26 13:53:35
 * @FilePath: /cpp/showtree/Tree.h
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#include<iostream>
#include"TreeNode.h"

using namespace std;

template <class T>
class Tree
{
public:
    TreeNode<T> *root;

    Tree();
    ~Tree();
    bool isEmpty();
    TreeNode<T>* insertChild(TreeNode<T> *p, T value);

    friend ostream& operator<<(ostream &out, Tree<T> &tree) {
        tree.perOrder(tree.root, 0);
        return out;
    }

private:
    void perOrder(TreeNode<T> *p, int i);
    void postOrder(TreeNode<T> *p);
    void destroy(TreeNode<T> *p);
};

template <class T>
Tree<T>::Tree() {
    this->root = NULL;
}

template <class T>
bool Tree<T>::isEmpty() {
    return this->root == NULL;
}

template <class T>
TreeNode<T>* Tree<T>::insertChild(TreeNode<T> *p, T value) {
    TreeNode<T> *q = NULL;

    if (p != NULL) {
        q = new TreeNode<T>(value);
        if (p->child == NULL) {
            p->child = q;
        } else {
            p = p->child;
            while (p->sibling != NULL)
            {
                p = p->sibling;
            }

            p->sibling = q;
        }
    }
    return q;
}

template <class T>
void Tree<T>::perOrder(TreeNode<T> *p, int i) {
    // 先跟次序遍历以p为根节点的子树，递归算法，参数i指定节点的层次， 输出i个tab缩进量
    if (p != NULL) {
        for (int j=0; j<i; j++) {
            cout<<"\t";
        }
        cout<<p->data<<endl;
        perOrder(p->child, i+1);
        perOrder(p->sibling, i);
    }
}

template <class T>
Tree<T>::~Tree() {
    destroy(root);
}

template <class T>
void Tree<T>::destroy(TreeNode<T> *p) {
    if (p != NULL) {
        destroy(p->child);
        destroy(p->sibling);
        delete p;
    }
}