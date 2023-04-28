/*
 * @Author: Libre Gu 
 * @Date: 2023-04-28 13:30:14
 * @LastEditors: Libre Gu 
 * @LastEditTime: 2023-04-28 15:36:36
 * @FilePath: /cpp/graph/SeqList.h
 * @Description: 
 * Copyright (c) 2023 by Libre, All Rights Reserved. 
 */
#include<iostream>
#include<stdexcept>

using namespace std;

template<class T>
class SeqList
{
    private:
        T *element;
        int size;
        int len;
    
    public:
        SeqList(int size=64);
        SeqList(T value[], int n);
        ~SeqList();
        bool isEmpty();
        int length();
        T get(int i);
        bool set(int i, T x);
        void insert(int i, T x);
        void insert(T x);
        bool remove(int i, T &old);
        void clear();

        friend ostream& operator<<(ostream &out, SeqList<T> &list)
        {
            out<<"(";
            if (list.len > 0)
            {
                out<<list.element[0];
                for (int i=1; i<list.len; i++)
                    out<<", "<<list.element[i];
            }
            out<<")"<<endl;
            return out;
        }
};

template<class T>
SeqList<T>::SeqList(int size)
{
    this->size = size;
    this->element = new T[this->size];
    this->len = 0;
}

template<class T>
SeqList<T>::SeqList(T value[], int n)
{
    if (n>0)
    {
        this->element = new T[2*n];
        this->size = 2*n;
        for (int i=0; i<n; i++)
            this->element[i] = value[i];
        this->len = n;
    }
}

template<class T>
SeqList<T>::~SeqList()
{
    delete this->element;
}

template<class T>
bool SeqList<T>::isEmpty()
{
    return len == 0;
}

template<class T>
int SeqList<T>::length()
{
    return len;
}

template<class T>
T SeqList<T>::get(int i)
{
    if (i>=0 && i<len)
        return this->element[i];
    throw runtime_error("参数i指定序号无效");
}

template<class T>
bool SeqList<T>::set(int i, T x)
{
    if (i>=0 && i<len)
    {
        this->element[i] = x;
        return true;
    }
    return false;
    
}

template<class T>
void SeqList<T>::insert(int i, T x)
{
    if (len == size)
    {
        T *temp = this->element;
        element = new T[size * 2];
        for (int i = 0; i < size; i++)
        {
            element[i] = temp[i];
        }
        size *= 2;
    }
    if (i<0) i=0;
    if (i>len) i=len;
    for (int j=len-1; j>=i; j--)
    {
        element[j+1] = element[j];
    }
    element[i] = x;
    len++;
}

template<class T>
void SeqList<T>::insert(T x)
{
    insert(len, x);
}

template<class T>
bool SeqList<T>::remove(int i, T &old)
{
    if (len>0 && i>=0 && i<len)
    {
        old = element[i];
        for (int j=i; j<len; j++)
        {
            element[j] = element[j+1];
        }
        len--;
        return true;
    }
    return false;
}

template<class T>
void SeqList<T>::clear()
{
    len=0;
}