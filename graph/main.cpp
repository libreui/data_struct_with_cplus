/*
 * @Author: Libre Gu 
 * @Date: 2023-04-28 13:34:21
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-05-24 17:39:11
 * @FilePath: /cpp/graph/main.cpp
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#include<iostream>
#include"AdjMatrixGraph.h"
#include"AdjListGraph.h"
#include"SinglyLinkList.h"

using namespace std;
int main()
{
    
    char vertices[] = "ABCDE";
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
    
    // 邻接矩阵表示的图
    AdjMatrixGraph<char> graph(vertices, 5, edges, 14);
    cout<<"带权无向图G3，"<<graph<<endl;

    // 从每图的每个顶点出发，深度优先遍历
    for (int i = 0; i < graph.vertexCount(); i++)
    {
        graph.DFSTraverse(i);
    }
    cout<<endl;
    for (int i = 0; i < graph.vertexCount(); i++)
    {
        graph.BFSTraverse(i);
    }
    
    /*
    graph.insertVertex('F');
    cout<<"插入顶点 F，插入边(A,F,20)? "<<graph.insertEdge(0, 5, 20)<<endl;

    char old=' ';
    if (graph.removeVertex(2, old))
        cout<<"删除顶点"<<old<<endl;
    
    cout<<"删除边(v2, v3)，"<<(graph.removeEdge(2, 3) && graph.removeEdge(3, 2))<<endl;
    cout<<graph<<endl;
    */

    /* 测试单链表 */
    // SinglyLinkList<char> lista("abc", 3);
    // SinglyLinkList<char> listb("xy", 2);
    // lista.concat(listb);
    // cout<<lista<<listb;
    /* 测试单链表 */


    /* 一下是邻接表 表示的图 */
    /*
    char vertices[] = "ABCDE";
    Edge edges[] = {
        {0,1,5},
        {0,3,2},
        {1,0,6},
        {1,2,7},
        {2,4,3},
        {3,2,8},
        {3,4,9}
    };
    
    AdjListGraph<char> graph(vertices, 5, edges, 7);
    cout<<"带权有向图 G4，\n"<<graph<<endl;

    for (int i = 0; i < graph.vertexCount(); i++)
    {
        graph.DFSTraverse(i);
    }

    
    char old = ' ';
    if (graph.removeVertex(2, old))
        cout<<"删除顶点"<<old<<",";
    cout<<"删除边(v2, v3)，"<<graph.removeEdge(2, 3)<<"\n";
    cout<<graph<<endl;
    */
    return 0;
}