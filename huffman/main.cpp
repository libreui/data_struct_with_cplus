/*
 * @Author: Libre Gu 
 * @Date: 2023-04-21 13:41:09
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-04-21 15:45:41
 * @FilePath: /cpp/huffman/main.cpp
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#include<iostream>
#include"HuffmanTree.h"
using namespace std;

int main() {
    int weight[] = {5,29,7,8,14,23,3,11};
    HuffmanTree htree(weight, 8);
    htree.print();
    return 0;
}