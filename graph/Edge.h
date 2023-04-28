/*
 * @Author: Libre Gu 
 * @Date: 2023-04-28 13:21:43
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-04-28 13:24:14
 * @FilePath: /cpp/graph/Edge.h
 * @Description: 边的对象
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#include<iostream>

using namespace std;

struct Edge
{
    int start;
    int dest;
    int weight;

    friend ostream& operator<<(ostream &out, Edge &e);
};

ostream& operator<<(ostream &out, Edge &e) 
{
    out<<"("<<e.start<<","<<e.dest<<","<<e.weight<<")";
    return out;
}
