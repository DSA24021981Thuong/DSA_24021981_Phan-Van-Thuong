#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "SLinkedList.h"

class ListQueue {
private:
    Node* head;

public:
    ListQueue(); // O(1)
    ~ListQueue(); // O(n), deletes every node

    ListQueue(const ListQueue&) = delete;
    ListQueue& operator=(const ListQueue&) = delete;

    void enqueue(int data); // O(n) if insertTail traverses from head
    int dequeue(); // O(1)
    int front(); // O(1)
    bool isEmpty(); // O(1)
};

#endif
