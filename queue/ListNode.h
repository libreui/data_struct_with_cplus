#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int x) : val(x), next(NULL), prev(NULL) {}
};