#include "ListStack.h"

// Constructor: O(1) time and O(1) space.
ListStack::ListStack() : head(nullptr) {
}

// Destructor: O(n) time to delete all nodes; O(1) extra space.
ListStack::~ListStack() {
    while (!isEmpty()) {
        deleteHead(head);
    }
}

// push: O(1), because insertHead adds a node at the beginning.
void ListStack::push(int data) {
    insertHead(head, data);
}

// pop: O(1), because deleting the head node takes constant time.
int ListStack::pop() {
    if (isEmpty()) return -1;
    int value = top();
    deleteHead(head);
    return value;
}

// top: O(1) time and O(1) extra space.
int ListStack::top() {
    if (isEmpty()) return -1;
    return head->data;
}

// isEmpty: O(1) time and O(1) extra space.
bool ListStack::isEmpty() {
    return head == nullptr;
}
