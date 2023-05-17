/*
 * @Author: Libre Gu 
 * @Date: 2023-05-17 16:25:50
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-05-17 18:06:59
 * @FilePath: /cpp/graph/AdjListGraph.h
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#include<iostream>
#include<stdexcept>
#include"Vertex.h"

using namespace std;

template <class T>
class AdjListGraph
{
private:
    Vertex<T> *vertexlist;
    int size;
    int vertCount;
public:
    AdjListGraph(int size=10);
    AdjListGraph(T vertices[], int vertCount, Edge edges[], int edgeCount);
    ~AdjListGraph();
    int vertexCount();
    T get(int i);
    void insertVertex(T vertex);
    bool insertEdge(int i, int j, int weight);
    bool insertEdge(Edge edge);
    bool removeEdge(int i, int j);
    bool removeVertex(int v, T &old);

    friend ostream& operator<<(ostream &out, AdjListGraph<T> &graph)
    {
        for (int i = 0; i < graph.vertCount; i++)
        {
            out<<i<<" "<<"顶点"<<graph.vertexlist[i].data<<" 出边表：";
            out<<graph.vertexlist[i].adjlink;
        }
        return out;
    }
};

template <class T>
AdjListGraph<T>::AdjListGraph(int size)
{
    this->size = size < 10 ? 10 : size;
    this->vertexlist = new Vertex<T>[this->size];
    this->vertCount = 0;
}

template <class T>
AdjListGraph<T>::AdjListGraph(T vertices[], int vertCount, Edge edges[], int edgeCount)
{
    this->size = vertCount < 10 ? 10 : vertCount;
    this->vertexlist = new Vertex<T>[this->size];
    this->vertCount = 0;
    for (int i = 0; i < vertCount; i++)
    {
        insertVertex(vertices[i]);
    }
    for (int j = 0; j < edgeCount; j++)
    {
        insertEdge(edges[j]);
    }
    
}

template <class T>
AdjListGraph<T>::~AdjListGraph()
{
    delete[] vertexlist;
}

template <class T>
int AdjListGraph<T>::vertexCount()
{
    return vertCount;
}

template <class T>
T AdjListGraph<T>::get(int i)
{
    if (i >= 0 && i < vertCount)
        return vertexlist[i].data;
    throw runtime_error("参数i指定元素序号无效");
}

template <class T>
void AdjListGraph<T>::insertVertex(T vertex)
{
    if (vertCount == size)
    {
        Vertex<T> *temp = vertexlist;
        vertexlist = new Vertex<T>[size * 2];
        for (int i = 0; i < size; i++)
        {
            vertexlist[i] = temp[i];
        }
        size *= 2;
    }
    vertexlist[vertCount].data = vertex;
    vertCount++; 
}

template <class T>
bool AdjListGraph<T>::insertEdge(int i, int j, int weight)
{
    if (i>=0 && i<vertCount && j>=0 && j<vertCount && i!=j)
    {
        Edge e = {i, j, weight};
        Node<Edge> *p = vertexlist[i].adjlink.head, *front;
        if (p == NULL || p != NULL && j < p->data.dest)
        {
            vertexlist[i].adjlink.head = new Node<Edge>(e, p);
            return true;
        }
        while (p!=NULL && j>=p->data.dest)
        {
            if (j==p->data.dest)
                return false;
            front = p;
            p = p->next;
        }
        front->next = new Node<Edge>(e, p);
        return true;
        
    }
    return false;
}

template <class T>
bool AdjListGraph<T>::insertEdge(Edge edge)
{
    return insertEdge(edge.start, edge.dest, edge.weight);
}

template <class T>
bool AdjListGraph<T>::removeEdge(int i, int j)
{
    if (i>=0 && i<vertCount && j>=0 && j<vertCount && i!=j)
    {
        Node<Edge> *p = vertexlist[i].adjlink.head, *front;
        if (p!=NULL && p->data.dest==j)
        {
            vertexlist[i].adjlink.head = p->next;
            delete p;
            return true;
        }
        while (p!=NULL && p->data.dest!=j)
        {
            front = p;
            p = p->next;
        }
        if (p!=NULL)
        {
            front->next = p->next;
            delete p;
            return true;
        }
    }
    return false;
}

template <class T>
bool AdjListGraph<T>::removeVertex(int v, T &old)
{
    //判断需要无效
    if (v < 0 || v >= vertCount)
        return false;
    
    // 获取顶点v的边单链表
    Node<Edge> *p = vertexlist[v].adjlink.head;
    while (p != NULL)
    {
        //删除对应的边
        removeEdge(p->data.dest, p->data.start);
        p = p->next;
    }
    
    // 保存删除顶点的数据
    old = vertexlist[v].data;
    vertexlist[v].adjlink.clear();

    // 将顶点表v之后的元素向前移动
    int i;
    for (i = v; i < vertCount-1; i++)
    {
        vertexlist[i].data = vertexlist[i+1].data;
        vertexlist[i].adjlink.head = vertexlist[i+1].adjlink.head;
        vertexlist[i+1].adjlink.head = NULL;
    }
    vertCount--;

    // 减少序号顶点序号v对应在边单链表中的节点
    for (i = 0; i < vertCount-1; i++)
    {
        p = vertexlist[i].adjlink.head;
        while (p != NULL)
        {
            if (p->data.start > v)
                p->data.start--;
            if (p->data.dest > v)
                p->data.dest--;
            p = p->next;
        }
    }
    return true;
}