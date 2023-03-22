//
// Created by Libre Gu on 2023/3/17.
//

#include <iostream>
#include <stack>
#include <queue>
#include "BinaryNode.h"

using namespace std;

template <class T>
class BinaryTree
{
public:
    BinaryNode<T> *root;

    BinaryTree();
    BinaryTree(T prelist[], int n);
    BinaryTree(T prelist[], T inlist[], int n);
    ~BinaryTree();

    bool isEmpty();
    void preOrder();
    void inOrder();
    void postOrder();
    int count();
    int height();
    BinaryNode<T>* search(T value);
    BinaryNode<T>* getParent(BinaryNode<T> *node);
    BinaryNode<T>* insert(BinaryNode<T> *node, T value, bool leftChild=true);
    void remove(BinaryNode<T> *node, bool leftChild=true);
    void printGList();
    void preOrderTraverse();
    void inOrderTraverse();
    void postOrderTraverse();
    void levelOrder();

private:
    void preOrder(BinaryNode<T> *p);
    void inOrder(BinaryNode<T> *p);
    void postOrder(BinaryNode<T> *p);
    void destory(BinaryNode<T> *p);
    BinaryNode<T>* create(T prelist[], int n, int &i);
    BinaryNode<T>* create(T prelist[], T inlist[], int preStart, int inStart, int n);

    int count(BinaryNode<T> *p);
    int height(BinaryNode<T> *p);
    BinaryNode<T>* search(BinaryNode<T> *p, T value);
    BinaryNode<T>* getParent(BinaryNode<T> *p, BinaryNode<T> *node);
    void printGList(BinaryNode<T> *p);
};

template <class T>
void BinaryTree<T>::levelOrder() {
    if (root == NULL) {
        return;
    }
    cout<<"层次遍历：";
    queue<BinaryNode<T>*> myQueue;
    BinaryNode<T> *p = root;
    while (p != NULL)
    {
        cout<<p->data<<" ";
        if (p->left != NULL)
            myQueue.push(p->left);
        if (p->right != NULL)
            myQueue.push(p->right);
        if (!myQueue.empty()) {
            p = myQueue.front();
            myQueue.pop();
        } else p = NULL;
    }

    cout<<endl;
    
}

template <class T>
void BinaryTree<T>::postOrderTraverse() {
    if (root == NULL) {
        return;
    }
    cout<<"后根次序遍历(非递归)：";
    stack<BinaryNode<T>*> myStack;
    BinaryNode<T> *p = root;
    BinaryNode<T> *prev = NULL;
    while (p != NULL || !myStack.empty())
    {
        while (p != NULL)
        {
            myStack.push(p);
            p = p->left;
        }
        
        p = myStack.top();
        if (p->right == NULL || p->right == prev) {
            cout<<p->data<<" ";
            myStack.pop();
            prev = p;
            p = NULL;
        } else {
            p = p->right;
        }
    }
    cout<<endl;
    
}

template <class T>
void BinaryTree<T>::preOrderTraverse() {
    if (root == NULL) {
        return;
    }
    cout<<"前根次序遍历(非递归)：";
    stack<BinaryNode<T>*> myStack;
    myStack.push(root);
    while (!myStack.empty())
    {
        BinaryNode<T> *p = myStack.top();
        myStack.pop();

        cout<<p->data<<" ";

        if (p->right) {
            myStack.push(p->right);
        }
        if (p->left) {
            myStack.push(p->left);
        }
    }
    
    cout<<endl;
}

template <class T>
void BinaryTree<T>::inOrderTraverse() {
    cout<<"中根次序遍历(非递归)：";
    stack<BinaryNode<T>*> myStack;

    BinaryNode<T> *p = root;
    while (p != NULL || !myStack.empty())
    {
        if (p != NULL) {
            myStack.push(p);
            p = p->left;
        } else {
            p = myStack.top();
            myStack.pop();
            cout<<p->data<<" ";
            p = p->right;
        }
    }
    cout<<endl;
}

template <class T>
void BinaryTree<T>::remove(BinaryNode<T> *node, bool leftchild) {
    if (node != NULL) {
        if (leftchild) {
            destory(node->left);
            node->left = NULL;
        } else {
            destory(node->right);
            node->right = NULL;
        }
    }
}

template <class T>
BinaryNode<T>* BinaryTree<T>::insert(BinaryNode<T> *node, T value, bool leftchild) {
    BinaryNode<T> *p = NULL;
    if (node != NULL) {
        if (node != NULL) {
            if (leftchild) {
                p = new BinaryNode<T>(value, node->left, NULL);
                node->left = p;
            } else {
                p = new BinaryNode<T>(value, NULL, node->right);
                node->right = p;
            }
        }
    }
    return p;
}

template <class T>
BinaryTree<T>::BinaryTree(T prelist[], int n) {
    int i = 0;
    root = create(prelist, n, i);
}

template <class T>
BinaryNode<T>* BinaryTree<T>::create(T prelist[], int n, int &i) {
    BinaryNode<T> *p = NULL;
    if (i < n) {
        T elem = prelist[i];
        i++;
        if (elem != ' ') {
            p = new BinaryNode<T>(elem);
            p->left = create(prelist, n, i);
            p->right = create(prelist, n, i);
        }
    }
    return p;
}

template <class T>
BinaryTree<T>::BinaryTree(T prelist[], T inlist[], int n) {
    root = create(prelist, inlist, 0, 0, n);
}

template <class T>
BinaryNode<T>* BinaryTree<T>::create(T prelist[], T inlist[], int preStart, int inStart, int n) {
    BinaryNode<T> *p = NULL;
    if (n > 0) {
        T elem = prelist[preStart];
        p = new BinaryNode<T>(elem);
        // 找到中根顺序列表中根节点位置
        int i = 0;
        while (i<n && elem!=inlist[inStart+i])
        {
            i++;
        }
        p->left=create(prelist, inlist, preStart+1, inStart, i);
        p->right=create(prelist, inlist, preStart+i+1, inStart+i+1, n-1-i);

    }
    return p;
}

template <class T>
BinaryTree<T>::BinaryTree() {
    root = NULL;
}

template <class T>
bool BinaryTree<T>::isEmpty() {
    return root == NULL;
}

template <class T>
int BinaryTree<T>::count(BinaryNode<T> *p) {
    if (p == NULL) {
        return 0;
    } else {
        return 1 + count(p->left) + count(p->right);
    }
}

template <class T>
int BinaryTree<T>::count() {
    return count(root);
}

template <class T>
void BinaryTree<T>::preOrder() {
    cout<<"先根次序遍历二叉树：";
    preOrder(root);
    cout<<endl;
}

template <class T>
void BinaryTree<T>::preOrder(BinaryNode<T> *p) {
    if (p!=NULL) {
        cout<<p->data<<" ";
        preOrder(p->left);
        preOrder(p->right);
    }
}

template <class T>
void BinaryTree<T>::inOrder() {
    cout<<"中根次序遍历二叉树：";
    inOrder(root);
    cout<<endl;
}

template <class T>
void BinaryTree<T>::inOrder(BinaryNode<T> *p) {
    if (p != NULL) {
        inOrder(p->left);
        cout<<p->data<<" ";
        inOrder(p->right);
    }
}

template <class T>
void BinaryTree<T>::postOrder() {
    cout<<"后根次序遍历二叉树：";
    postOrder(root);
    cout<<endl;
}

template <class T>
void BinaryTree<T>::postOrder(BinaryNode<T> *p) {
    if (p != NULL) {
        postOrder(p->left);
        postOrder(p->right);
        cout<<p->data<<" ";
    }
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    destory(root);
}

template <class T>
void BinaryTree<T>::destory(BinaryNode<T> *p) {
    if (p != NULL) {
        destory(p->left);
        destory(p->right);
        delete p;
    }
}

template <class T>
int BinaryTree<T>::height(BinaryNode<T> *p) {
    if (p != NULL) {
        int lh = height(p->left);
        int rh = height(p->right);
        return (lh >= rh) ? lh + 1 : rh + 1;
    }
    return 0;
}

template <class T>
int BinaryTree<T>::height() {
    return height(root);
}

template <class T>
BinaryNode<T>* BinaryTree<T>::search(BinaryNode<T> *node, T value) {
    BinaryNode<T> *find = NULL;
    if (node != NULL) {
        if (node->data == value) {
            return node;
        }
        find = search(node->left, value);
        if (find == NULL) {
            find = search(node->right, value);
        }
    }
    return find;
}

template <class T>
BinaryNode<T>* BinaryTree<T>::search(T value) {
    return search(root, value);
}


template <class T>
BinaryNode<T>* BinaryTree<T>::getParent(BinaryNode<T> *node) {
    if (root == NULL || node == NULL || root == node) {
        return NULL;
    }
    return this->getParent(root, node);
}

template <class T>
BinaryNode<T>* BinaryTree<T>::getParent(BinaryNode<T> *p, BinaryNode<T> *node) {

    BinaryNode<T> *find = NULL;

    if (p != NULL) {
        if (p->left == node || p->right == node) {
            return p;
        }
        find = getParent(p->left, node);
        if (find == NULL) {
            find = getParent(p->right, node);
        }
    }

    return find;
}

template <class T>
void BinaryTree<T>::printGList() {
    printGList(root);
    cout<<endl;
}

template <class T>
void BinaryTree<T>::printGList(BinaryNode<T> *p) {
    if (p == NULL) {
        cout<<"^";
    } else {
        cout<<p->data;
        if (p->left != NULL || p->right != NULL) {
            cout<<"(";
            printGList(p->left);
            cout<<",";
            printGList(p->right);
            cout<<")";
        }
    }
}
