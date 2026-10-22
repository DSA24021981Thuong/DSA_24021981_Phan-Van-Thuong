#include "Array_Queue.h"
#include "Array_List.h"


ArrayQueue::ArrayQueue(int size) {
    capacity = size > 0 ? size : 100;
    a = new int[capacity];
    n = 0;
}


ArrayQueue::~ArrayQueue() {
    delete[] a;
}


void ArrayQueue::enqueue(int data) {
    if (n >= capacity) return;
    insertTail(a, n, data);
}


int ArrayQueue::dequeue() {
    if (isEmpty()) return -1;
    int value = front();
    deleteHead(a, n);
    return value;
}


int ArrayQueue::front() {
    if (isEmpty()) return -1;
    return a[0];
}


bool ArrayQueue::isEmpty() {
    return n == 0;
}
