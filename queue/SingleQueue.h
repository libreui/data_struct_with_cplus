#include <iostream>
#include "ListNode.h"
using namespace std;

class SingleQueue {
private:
    ListNode *head, *tail;

public:
    SingleQueue() {
        head = NULL;
        tail = NULL;
    }

    void push(int x) {
        ListNode *node = new ListNode(x);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int pop() {
        if (head == NULL) {
            return -1;
        }

        ListNode *node = head;
        int val = node->val;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete node;
        return val;
    }

    int peek() {
        if (head == NULL) {
            return -1;
        }
        return head->val;
    }

    bool isEmpty() {
        return head == NULL;
    }
};