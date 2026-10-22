#include "Array_Stack.h"
#include "Array_List.h"

// Constructor: O(1) time, O(capacity) space for the array.
ArrayStack::ArrayStack(int size) {
    capacity = size > 0 ? size : 100;
    a = new int[capacity];
    n = 0;
}

// Destructor: O(1) time to release the allocated array.
ArrayStack::~ArrayStack() {
    delete[] a;
}

// push: O(1) when insertTail appends without shifting; O(1) extra space.
void ArrayStack::push(int data) {
    if (n >= capacity) return;
    insertTail(a, n, data);
}

// pop: O(1), because deleteTail removes the last array element without shifting.
int ArrayStack::pop() {
    if (isEmpty()) return -1;
    int value = top();
    deleteTail(a, n);
    return value;
}

// top: O(1) time and O(1) extra space.
int ArrayStack::top() {
    if (isEmpty()) return -1;
    return a[n - 1];
}

// isEmpty: O(1) time and O(1) extra space.
bool ArrayStack::isEmpty() {
    return n == 0;
}
