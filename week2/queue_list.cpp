#include "ListQueue.h"

// Constructor: O(1) time and O(1) space.
ListQueue::ListQueue() : head(nullptr) {
}

// Destructor: O(n) time to delete all nodes; O(1) extra space.
ListQueue::~ListQueue() {
    while (!isEmpty()) {
        deleteHead(head);
    }
}

// enqueue: O(n) if insertTail traverses from head to the last node.
void ListQueue::enqueue(int data) {
    insertTail(head, data);
}

// dequeue: O(1), because deleteHead removes the first node in constant time.
int ListQueue::dequeue() {
    if (isEmpty()) return -1;
    int value = front();
    deleteHead(head);
    return value;
}

// front: O(1) time and O(1) extra space.
int ListQueue::front() {
    if (isEmpty()) return -1;
    return head->data;
}

// isEmpty: O(1) time and O(1) extra space.
bool ListQueue::isEmpty() {
    return head == nullptr;
}
