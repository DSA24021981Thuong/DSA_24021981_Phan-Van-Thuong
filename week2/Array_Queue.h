#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

class ArrayQueue {
private:
    int* a;
    int n;
    int capacity;

public:
    explicit ArrayQueue(int size = 100); // O(1) time, O(capacity) allocated space
    ~ArrayQueue(); // O(1) time

    ArrayQueue(const ArrayQueue&) = delete;
    ArrayQueue& operator=(const ArrayQueue&) = delete;

    void enqueue(int data); // O(1)
    int dequeue(); // O(n), because array elements shift left
    int front(); // O(1)
    bool isEmpty(); // O(1)
};

#endif
