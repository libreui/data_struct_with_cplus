/*
 * @Author: Libre Gu 
 * @Date: 2023-05-17 15:41:35
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-05-17 17:44:21
 * @FilePath: /cpp/graph/SinglyLinkList.h
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#ifndef __SINGLYLINKLIST_H__
#define __SINGLYLINKLIST_H__
#include<iostream>
#include<stdexcept>
#include"Node.h"

using namespace std;

template <class T>
class SinglyLinkList
{
    public:
        Node<T> *head;

        SinglyLinkList();
        SinglyLinkList(T value[], int n);
        ~SinglyLinkList();
        bool isEmpty();
        int length();
        Node<T>* getNode(int i);
        T get(int i);
        bool set(int i, T x);
        void insert(T x);
        Node<T>* insert(int i, T x);
        bool remove(int i, T &old);
        void clear();
        void concat(SinglyLinkList<T> &list);

        friend ostream& operator<<(ostream& out, SinglyLinkList<T> &list)
        {
            Node<T> *p = list.head;
            out<<"(";
            while (p != NULL)
            {
                out<<p->data;
                p = p->next;
                if (p != NULL)
                    out<<",";
            }
            out<<")"<<endl;
            return out;
        }
};

template <class T>
SinglyLinkList<T>::SinglyLinkList()
{
    this->head = NULL;
}

template <class T>
SinglyLinkList<T>::SinglyLinkList(T value[], int n)
{
    head = NULL;
    if (n > 0)
    {
        head = new Node<T>(value[0]);
        Node<T> *rear = head;
        int i = 1;
        while (i < n)
        {
            rear->next = new Node<T>(value[i++]);
            rear = rear->next;
        }
        
    }
}

template <class T>
SinglyLinkList<T>::~SinglyLinkList()
{
    clear();
}

template <class T>
bool SinglyLinkList<T>::isEmpty()
{
    return this->head == NULL;
}

template <class T>
int SinglyLinkList<T>::length()
{
    int i = 0;
    Node<T> *p = head;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}

template <class T>
Node<T>* SinglyLinkList<T>::getNode(int i)
{
    if (i < 0)
        return NULL;
    int j = 0;
    Node<T> *p = head;
    while (p != NULL && j < i)
    {
        j++;
        p = p->next;
    }
    return p;
}

template <class T>
T SinglyLinkList<T>::get(int i)
{
    Node<T> *p = getNode(i);
    if (p != NULL)
        return p->data;
    throw runtime_error("单链表空或参数i指定元素序号无效");
}

template <class T>
bool SinglyLinkList<T>::set(int i, T x)
{
    Node<T> *p = getNode(i);
    if (p != NULL)
    {
        p->data = x;
        return true;
    }
    return false;
}

template <class T>
void SinglyLinkList<T>::clear()
{
    Node<T> *p = head;
    while (p != NULL)
    {
        Node<T> *q = p;
        p = p->next;
        delete q;
    }
    head = NULL;    
}

template <class T>
void SinglyLinkList<T>::insert(T x)
{
    insert(this->length(), x);
}

template <class T>
Node<T>* SinglyLinkList<T>::insert(int i, T x)
{
    Node<T> *q = NULL;
    if (head == NULL || i <= 0)
    {
        q = new Node<T>(x, head);
        head = q;
    }
    else
    {
        int j = 0;
        Node<T> *p = head;
        while (p->next != NULL && j < i-1)
        {
            j++;
            p = p->next;
        }
        q = new Node<T>(x, p->next);
        p->next = q;
    }
    return q;
}

template <class T>
bool SinglyLinkList<T>::remove(int i, T &old)
{
    if (head != NULL && i >= 0)
    {
        if (i == 0)
        {
            Node<T> *q = head;
            old = q->data;
            head = q->next;
            delete q;
            return true;
        }
        else 
        {
            Node<T> *p = getNode(i-1);
            if (p != NULL && p->next != NULL)
            {
                Node<T> *q = p->next;
                old = q->data;
                p->next = q->next;
                delete q;
                return true;
            }
        }
        return false;
    }
}

template <class T>
void SinglyLinkList<T>::concat(SinglyLinkList<T> &list)
{
    if (this->head == NULL)
        this->head = list.head;
    else
    {
        Node<T> *p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = list.head;
    }
    list.head = NULL;
}
#endif