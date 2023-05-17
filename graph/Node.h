/*
 * @Author: Libre Gu 
 * @Date: 2023-05-17 15:42:19
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-05-17 17:43:21
 * @FilePath: /cpp/graph/Node.h
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#ifndef __NODE_H__
#define __NODE_H__
#include<iostream>
template <class T>
class Node
{
    public:
        T data;
        Node<T> *next;

        Node()
        {
            this->next = NULL;
        }
        Node(T data, Node<T> *next=NULL)
        {
            this->data = data;
            this->next = next;
        }

};
#endif