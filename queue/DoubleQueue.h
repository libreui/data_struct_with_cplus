#include <iostream>
#include <stdexcept>
#include "ListNode.h"

using namespace std;

class DoubleQueue {
private:
    ListNode *front;
    ListNode *rear;
    int size;

public:
    DoubleQueue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void push(int data) {
        ListNode *node = new ListNode(data);
        if (isEmpty()) {
            front = node;
            rear = node;
            front->prev = rear;
            rear->next = front;
        } else {
            rear->next = node;
            node->prev = rear;
            rear = node;
            rear->next = front;
            front->prev = rear;
        }
        size++;
    }

    int pop() {
        if (isEmpty()) {
            throw "Queue is empty!";
        }

        ListNode *temp = front;
        int value = temp->val;

        if (front == rear) {
            front = NULL;
            rear = NULL;
        } else {
            front = front->next;
            front->prev = rear;
            rear->next = front;
        }

        delete temp;
        size--;
        return value;
    }
    
    int peek() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty!");
        }
        return front->val;
    }
};
