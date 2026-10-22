#ifndef LISTSTACK_H
#define LISTSTACK_H

#include "SLinkedList.h"

class ListStack {
private:
    Node* head;

public:
    ListStack(); // O(1)
    ~ListStack(); // O(n), deletes every node

    ListStack(const ListStack&) = delete;
    ListStack& operator=(const ListStack&) = delete;

    void push(int data); // O(1)
    int pop(); // O(1)
    int top(); // O(1)
    bool isEmpty(); // O(1)
};

#endif
