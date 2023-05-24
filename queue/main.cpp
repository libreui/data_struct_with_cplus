/*
 * @Author: Libre Gu 
 * @Date: 2023-02-22 15:31:38
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-05-23 13:54:53
 * @FilePath: /cpp/queue/main.cpp
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#include <iostream>
// #include "SingleQueue.h"
// #include "DoubleQueue.h"
#include "SeqQueue.h"

using namespace std;




int main() {
    // DoubleQueue queue;
    // queue.push(11);
    // queue.push(22);
    // queue.push(33);
    // queue.push(44);
    // cout<<queue.pop()<<endl;
    // cout<<queue.pop()<<endl;
    // cout<<queue.pop()<<endl;
    // cout<<queue.pop()<<endl;
    // try {
    //     cout<<queue.peek()<<endl;
    // } catch (exception *err) {
    //     cout<<err->what()<<endl;
    // }

    SeqQueue<int> queue;
    queue.enqueue(11);
    queue.enqueue(22);
    cout<<queue.dequeue()<<endl;
    
    return 0;
}