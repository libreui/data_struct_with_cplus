/*
 * @Author: Libre Gu 
 * @Date: 2023-04-21 13:43:14
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-04-21 15:52:23
 * @FilePath: /cpp/huffman/HuffmanTree.h
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#include<iostream>
#include"TriNode.h"
using namespace std;

class HuffmanTree {
    private:
        int leafNum;
        TriNode<int> *hufftree;
        char **hufcodes;
        void createHuffmanTree(int weight[], int n);
        void getHuffmanCode();

    public:
        HuffmanTree(int weight[], int n);
        ~HuffmanTree();
        void print();
};

HuffmanTree::HuffmanTree(int weight[], int n) {
    createHuffmanTree(weight, n);
    getHuffmanCode();
}

void HuffmanTree::createHuffmanTree(int weight[], int n) {
    leafNum = n;
    hufftree = new TriNode<int>[2*n-1];
    int i;
    for (i = 0; i < n; i++)
    {
        hufftree[i].data = weight[i];
        hufftree[i].parent=hufftree[i].left=hufftree[i].right = -1;
    }
    for (i = 0; i < n-1; i++)
    {
        int min1,min2,x1,x2;
        min1 = min2 = INT_MAX;
        x1 = x2 = -1;

        for (int j=0; j<n+i; j++) {
            if (hufftree[j].data < min1 && hufftree[j].parent == -1) 
            {
                min2 = min1;
                x2 = x1;
                min1 = hufftree[j].data;
                x1 = j;
            }
            else if(hufftree[j].data < min2 && hufftree[j].parent == -1)
            {
                min2 = hufftree[j].data;
                x2 = j;
            }
        }   
        hufftree[x1].parent = n+i;
        hufftree[x2].parent = n+i;
        
        hufftree[n+i].data = hufftree[x1].data + hufftree[x2].data;
        hufftree[n+i].parent = -1;
        hufftree[n+i].left = x1;
        hufftree[n+i].right = x2;
    }  
}

void HuffmanTree::getHuffmanCode() {
    int n = leafNum;
    hufcodes = new char*[n];
    for (int i = 0; i < n; i++)
    {
        char *code = new char[n];
        code[n-1] = '\0';
        int start = n-1;
        int child = i;
        int parent = hufftree[i].parent;
        while (parent != -1)
        {
            start--;
            if (hufftree[parent].left == child){
                code[start] = '0';
            } else {
                code[start] = '1';
            }
            child = parent;
            parent = hufftree[child].parent;
        }
        hufcodes[i]=code+start;
        
    }  
}

void HuffmanTree::print() {
    cout<<"哈夫曼树的节点数组"<<endl;
    int i;
    for (i = 0; i < leafNum*2-1; i++)
    {
        cout<<"第"<<i<<"行 "<<hufftree[i].data<<","<<hufftree[i].parent<<","<<hufftree[i].left<<","<<hufftree[i].right<<endl; 
    }
    cout<<"哈夫曼编码："<<endl;
    for (i = 0; i < leafNum; i++)
    {
        cout<<hufcodes[i]<<endl;
    }
    cout<<endl;
    
    
}

HuffmanTree::~HuffmanTree() {
    delete[] hufcodes;
    delete[] hufftree;
}