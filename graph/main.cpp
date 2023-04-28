/*
 * @Author: Libre Gu 
 * @Date: 2023-04-28 13:34:21
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-04-28 15:49:10
 * @FilePath: /cpp/graph/main.cpp
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#include<iostream>
#include"AdjMatrixGraph.h"

using namespace std;
int main()
{
    char *vertices="ABCDE";
    Edge edges[] = {
        {0,1,5},
        {0,3,2},
        {1,0,5},
        {1,2,7},
        {1,3,6},
        {2,1,7},
        {2,3,8},
        {2,4,3},
        {3,0,2},
        {3,1,6},
        {3,2,8},
        {3,4,9},
        {4,2,3},
        {4,3,9}
    };
    AdjMatrixGraph<char> graph(vertices, 5, edges, 14);
    cout<<"带权无向图G3，"<<graph<<endl;

    graph.insertVertex('F');
    cout<<"插入顶点 F，插入边(A,F,20)? "<<graph.insertEdge(0, 5, 20)<<endl;

    char old=' ';
    if (graph.removeVertex(2, old))
        cout<<"删除顶点"<<old<<endl;
    
    cout<<"删除边(v2, v3)，"<<(graph.removeEdge(2, 3) && graph.removeEdge(3, 2))<<endl;
    cout<<graph<<endl;
    
    return 0;
}