/*
 * @Author: Libre Gu 
 * @Date: 2023-04-26 13:27:00
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-04-26 13:29:09
 * @FilePath: /cpp/showtree/TreeNode.h
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#include<iostream>

template <class T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *child,*sibling;

    TreeNode(T data) {
        this->data = data;
        this->child = this->sibling = NULL;
    }
};