/*
 * @Author: Libre Gu 
 * @Date: 2023-05-17 16:24:17
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-05-17 17:39:10
 * @FilePath: /cpp/graph/Vertex.h
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#include"Edge.h"
#include"SinglyLinkList.h"

template <class T>
struct Vertex
{
    T data;
    SinglyLinkList<Edge> adjlink;
};
