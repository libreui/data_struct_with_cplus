/*
 * @Author: Libre Gu 
 * @Date: 2023-04-26 13:26:43
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-04-26 13:51:50
 * @FilePath: /cpp/showtree/main.cpp
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#include<iostream>
#include"Tree.h"

using namespace std;

void make(Tree<char*> &tree) {
    tree.root = new TreeNode<char*>("中国");
    tree.insertChild(tree.root, "北京");
    tree.insertChild(tree.root, "上海");

    TreeNode<char*> *js = tree.insertChild(tree.root, "江苏省");
    tree.insertChild(js, "南京市");
    tree.insertChild(js, "苏州市");

    TreeNode<char*> *zj = tree.insertChild(tree.root, "浙江省");
    tree.insertChild(zj, "杭州市");
    tree.insertChild(zj, "宁波市");
}

int main() {
    Tree<char*> tree;
    make(tree);
    cout<<tree;
    return 0;
}