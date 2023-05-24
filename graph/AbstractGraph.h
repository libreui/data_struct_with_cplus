/*
 * @Author: Libre Gu 
 * @Date: 2023-05-24 15:36:30
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-05-24 17:38:32
 * @FilePath: /cpp/graph/AbstractGraph.h
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#ifndef __ABSTRACT_GRAPH_H__
#define __ABSTRACT_GRAPH_H__
#include <iostream>
#include "SeqQueue.h"

using namespace std;

template <class T>
class AbstractGraph
{
    public:
        virtual int vertexCount() = 0;
        virtual T get(int i) = 0;
        virtual int getFirstNeighbor(int v) = 0;
        virtual int getNextNeighbor(int v, int w) = 0;
        void DFSTraverse(int v);
        void BFSTraverse(int v);

    private:
        void depthfs(int v, bool visited[]);
        void breadthfs(int v, bool visited[]);
};

template <class T>
void AbstractGraph<T>::DFSTraverse(int v)
{
    bool *visited = new bool[vertexCount()];
    int i;
    for (i = 0; i < vertexCount(); i++)
    {
        visited[i] = false;
    }

    i = v;
    do
    {
        if (!visited[i])
        {
            cout<<"{";
            depthfs(i, visited);
            cout<<"}";
        }
    } while (i != v);
    cout<<endl;
    delete[] visited;
}

template <class T>
void AbstractGraph<T>::depthfs(int v, bool visited[])
{
    cout<<get(v)<<" ";
    visited[v] = true;
    int w = getFirstNeighbor(v);
    while (w != -1)
    {
        if (!visited[w])
        {
            depthfs(w, visited);
        }
        w = getNextNeighbor(v, w);
    }
}

template<class T>
void AbstractGraph<T>::BFSTraverse(int v)
{
    bool *visited = new bool[vertexCount()];
    int i;
    for (i = 0; i < vertexCount(); i++)
    {
        visited[i] = false;
    }
    i = v;
    do
    {
        if (!visited[i])
        {
            cout<<"{";
            breadthfs(i, visited);
            cout<<"}";
        }
    } while (i != v);
    cout<<endl;
    delete[] visited;    
}

template<class T>
void AbstractGraph<T>::breadthfs(int v, bool visited[])
{
    cout<<get(v)<<" ";
    visited[v] = true;
    SeqQueue<int> que(vertexCount());
    que.enqueue(v);
    while (!que.isEmpty())
    {
        v = que.dequeue();
        int w = getFirstNeighbor(v);
        while (w != -1)
        {
            if (!visited[w])
            {
                cout<<get(w)<<" ";
                visited[w] = true;
                que.enqueue(w);
            }
            w = getNextNeighbor(v, w);
        }
    }
}
#endif