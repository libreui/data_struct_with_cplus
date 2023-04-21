/*
 * @Author: Libre Gu 
 * @Date: 2023-04-21 13:41:30
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-04-21 15:11:50
 * @FilePath: /cpp/huffman/triNode.h
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
template <class T>
struct TriNode
{
    T data;
    int parent,left,right;
};
