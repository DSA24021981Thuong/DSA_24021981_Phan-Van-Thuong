#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

class ArrayStack {
private:
    int* a;
    int n;
    int capacity;

public:
    explicit ArrayStack(int size = 100); // O(1) time, O(capacity) allocated space
    ~ArrayStack(); // O(1) time

    ArrayStack(const ArrayStack&) = delete;
    ArrayStack& operator=(const ArrayStack&) = delete;

    void push(int data); // O(1)
    int pop(); // O(1)
    int top(); // O(1)
    bool isEmpty(); // O(1)
};

#endif
