/*
 * @Author: Libre Gu 
 * @Date: 2023-03-16 09:34:47
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-03-24 20:54:03
 * @FilePath: main.cpp
 */
#include <iostream>
// #include "CompleteBinaryTree.h"
#include "BinaryTree.h"
#include "ThreadBinaryTree.h"

using namespace std;

void make(BinaryTree<char> &bitree) {
    BinaryNode<char> *child_d = new BinaryNode<char>('D', NULL, new BinaryNode<char>('G'));
    BinaryNode<char> *child_b = new BinaryNode<char>('B', child_d, NULL);
    BinaryNode<char> *child_f = new BinaryNode<char>('F', new BinaryNode<char>('H'), NULL);
    BinaryNode<char> *child_c = new BinaryNode<char>('C', new BinaryNode<char>('E'), child_f);
    bitree.root = new BinaryNode<char>('A', child_b, child_c);    
}

BinaryNode<char>* createGList(char *glist, int &i) {
    BinaryNode<char> *p = NULL;
    if (glist[i]>='A' && glist[i]<='Z') {
        p = new BinaryNode<char>(glist[i++]);
        if (glist[i] == '(') {
            i++;
            p->left = createGList(glist, i);
            i++;
            p->right = createGList(glist, i);
            i++;
        }
    }
    if (glist[i] == '^') {
        i++;
    }
    return p;
}

void createGList(BinaryTree<char> &bitree, char glist[]) {
    int i = 0;
    bitree.root = createGList(glist, i);
}

int main() {

    // BinaryTree<char> bitree;
    // make(bitree);

    // char prelist[] = "ABDGCEFH";
    // char inlist[] = "DGBAECHF";
    // BinaryTree<char> bitree(prelist, inlist, 8);

    // char prelist[] = {'A','B','D',' ','G',' ',' ',' ','C','E',' ',' ','F','H'};
    // BinaryTree<char> bitree(prelist, 14);

    BinaryTree<char> bitree;

    // 广义表创建二叉树
    char glist[] = "A(B(D(^,G),^),C(E,F(H,^)))";
    createGList(bitree, glist);

    // 创建完全二叉树
    // char levellist[] = "ABCEDFGH";
    // CompleteBinaryTree<char> bitree(levellist, 8);
    

    bitree.preOrder();
    bitree.inOrder();
    bitree.postOrder();

    // 非递归中序遍历
    bitree.preOrderTraverse();
    bitree.inOrderTraverse();
    bitree.postOrderTraverse();

    // 广度优先遍历
    bitree.levelOrder();

    cout<<"节点个数："<<bitree.count()<<endl;
    cout<<"二叉树高度："<<bitree.height()<<endl;

    cout<<"查找F："<<bitree.search('F')->data<<endl;

    BinaryNode<char> *searchF = bitree.search('F');
    BinaryNode<char> *parent = bitree.getParent(searchF);
    cout<<"F父节点："<<parent->data<<endl;

    //用广义表打印二叉树
    bitree.printGList();

    // 查找节点F
    BinaryNode<char> *f = bitree.search('F');
    // 插入一个新的节点'Z','Y'
    bitree.insert(f, 'Z');
    bitree.insert(f, 'Y', false);
    //用广义表打印二叉树
    bitree.printGList();

    // 删除'F'节点左右子树
    bitree.remove(f);
    bitree.remove(f, false);
    //用广义表打印二叉树
    bitree.printGList();

    /**** 线索二叉树 ****/
    char prelist[] = {'A', 'B', 'D', ' ', ' ', 'E', 'G', ' ', ' ', ' ', 'C', 'F', ' ', 'H', ' ', ' ', 'K'};
    ThreadBinaryTree<char> tbtree(prelist, 17);
    BinaryTree<char> b(prelist, 17);
    tbtree.inOrder();
    b.inOrder();
    tbtree.preORder();
    b.preOrder();
    tbtree.postOrder();
    b.postOrder();
    
    return 0;
}