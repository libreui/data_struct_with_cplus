/*
 * @Author: Libre Gu 
 * @Date: 2023-04-28 13:25:00
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-04-28 15:57:06
 * @FilePath: /cpp/graph/AdjMatrixGraph.h
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#include<iostream>
#include"SeqList.h"
#include"Edge.h"

template<class T>
class AdjMatrixGraph
{
    private:
        SeqList<T> vertexlist;
        int **adjmatrix;
        int size;
        int vertCount;
        void init(int size);

    public:
        AdjMatrixGraph(int size=10);
        AdjMatrixGraph(T vertices[], int vertCount, Edge edges[], int edgeCount);
        
        ~AdjMatrixGraph();

        int vertexCount();
        T get(int i);
        void insertVertex(T vertex);
        bool insertEdge(int i, int j, int weight);
        bool insertEdge(Edge edge);

        bool removeEdge(int i, int j);
        bool removeVertex(int v, T &old);

        friend ostream& operator<<(ostream &out, AdjMatrixGraph<T> &graph)
        {
            out<<"顶点集合："<<graph.vertexlist<<"邻接矩阵："<<endl;
            int n = graph.vertCount;
            for(int i=0; i<n; i++)
            {
                for (int j=0; j<n; j++)
                {
                    if (graph.adjmatrix[i][j] == INT_MAX)
                        out<<"\t∞";
                    else
                        out<<"\t"<<graph.adjmatrix[i][j];
                }
                out<<endl;
            }
            return out;
        }
};

template<class T>
AdjMatrixGraph<T>::AdjMatrixGraph(int size)
{
    init(size);
}

template<class T>
void AdjMatrixGraph<T>::init(int size)
{
    this->size = size<10?10:size;
    this->adjmatrix = new int*[this->size];
    for (int i=0; i<this->size; i++)
    {
        this->adjmatrix[i] = new int[this->size];
        for (int j=0; j<this->size; j++)
            this->adjmatrix[i][j] = (i==j) ? 0 : INT_MAX;
    }
    this->vertCount = 0;
}

template<class T>
AdjMatrixGraph<T>::AdjMatrixGraph(T vertices[], int vertCount, Edge edge[], int edgeCount)
{
    init(vertCount);
    for (int i=0; i<vertCount; i++)
        insertVertex(vertices[i]);
    for (int j=0; j<edgeCount; j++)
        insertEdge(edge[j]);
}

template<class T>
AdjMatrixGraph<T>::~AdjMatrixGraph()
{
    for (int i=0; i<size; i++)
        delete adjmatrix[i];
    delete adjmatrix;
}

template<class T>
int AdjMatrixGraph<T>::vertexCount()
{
    return vertCount;
}

template<class T>
T AdjMatrixGraph<T>::get(int i)
{
    return vertexlist.get(i);
}

template<class T>
void AdjMatrixGraph<T>::insertVertex(T vertex)
{
    vertexlist.insert(vertex);
    vertCount++;
    if (vertCount > size)
    {
        int ** temp = adjmatrix;
        adjmatrix = new int*[size * 2];
        int i,j;
        for (i=0; i<size; i++)
        {
            adjmatrix[i] = new int[size * 2];
            for (j=0; j<size; j++)
                adjmatrix[i][j] = temp[i][j];
            for (j=size; j<size*2; j++)
                adjmatrix[i][j] = INT_MAX;
        }
        for (i=size; i<size*2; i++)
        {
            adjmatrix[i] = new int[size*2];
            for (j=size; j<size*2; j++)
                adjmatrix[i][j] = (i==j) ? 0 : INT_MAX;
        }
        size *= 2;
    }
}

template<class T>
bool AdjMatrixGraph<T>::insertEdge(int i, int j, int weight)
{
    if (i>=0 && i<vertCount && j>=0 && j<vertCount && i!=j && adjmatrix[i][j]==INT_MAX)
    {
        // cout<<i<<","<<j<<","<<weight<<endl;
        adjmatrix[i][j] = weight;
        return true;
    }
    return false;
}

template<class T>
bool AdjMatrixGraph<T>::insertEdge(Edge edge)
{
    return insertEdge(edge.start, edge.dest, edge.weight);
}

template<class T>
bool AdjMatrixGraph<T>::removeEdge(int i, int j)
{
    if (i>0 && i<vertCount && j>0 && j<vertCount && i!=j && adjmatrix[i][j]
    !=INT_MAX)
    {
        adjmatrix[i][j] = INT_MAX;
        return true;
    }
    return false;
}

template<class T>
bool AdjMatrixGraph<T>::removeVertex(int v, T &old)
{
    if (v >=0 && v<vertCount && vertexlist.remove(v, old))
    {
        for (int i=v; i<vertCount-1; i++)
        {
            for (int j=0; j<vertCount; j++)
                adjmatrix[i][j] = adjmatrix[i+1][j];
        }
        for (int j=v; j<vertCount-1; j++)
        {
            for (int i=0; i<vertCount-1; i++)
                adjmatrix[i][j] = adjmatrix[i][j+1];
        }
        vertCount--;
        return true;

    }
    return false;
}
