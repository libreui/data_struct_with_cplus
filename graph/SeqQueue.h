/*
 * @Author: Libre Gu 
 * @Date: 2023-05-23 13:26:26
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-05-23 13:54:48
 * @FilePath: /cpp/queue/SeqQueue.h
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */

#ifndef __SEQ_QUEUE_H__
#define __SEQ_QUEUE_H__

#include<stdexcept>
#include<iostream>

using namespace std;

template <class T>
class SeqQueue
{
    private:
        T *element;
        int size;
        int front,rear;
    public:
        SeqQueue(int size=64);
        ~SeqQueue();
        bool isEmpty();
        void enqueue(T x);
        T dequeue();
};

template <class T>
SeqQueue<T>::SeqQueue(int size)
{
    this->size = size < 64 ? 64 : size;
    element = new T[this->size];
    front = rear = 0;
}

template <class T>
SeqQueue<T>::~SeqQueue()
{
    delete[] element;
}

template <class T>
bool SeqQueue<T>::isEmpty()
{
    return front == rear;
}

template <class T>
void SeqQueue<T>::enqueue(T x)
{
    if (front == (rear + 1) % size)
    {
        T *temp = element;
        element = new T[size*2];
        int i=front, j=0;
        while (i != rear)
        {
            element[i] = temp[i];
            i = (i+1) % size;
            j++;
        }
        front = 0;
        rear = j;        
    }
    element[rear] = x;
    rear = (rear + 1) % size;
}

template <class T>
T SeqQueue<T>::dequeue()
{
    if (!isEmpty())
    {
        T x = element[front];
        front = (front + 1) % size;
        return x;
    }
    throw runtime_error("空列队");
}

#endif