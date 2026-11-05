#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int *a;
    int n, capacity;

    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (a[parent] >= a[i]) break;

            int temp = a[parent];
            a[parent] = a[i];
            a[i] = temp;
            i = parent;
        }
    }

    void siftDown(int i) {
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && a[left] > a[largest])
                largest = left;
            if (right < n && a[right] > a[largest])
                largest = right;

            if (largest == i) break;

            int temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            i = largest;
        }
    }

public:
    explicit PriorityQueue(int cap = 100) {
        capacity = cap;
        a = new int[capacity];
        n = 0;
    }

    ~PriorityQueue() {
        delete[] a;
    }

    bool isEmpty() const { return n == 0; }
    int size() const { return n; }

    void push(int x) {
        if (n == capacity) {
            cout << "Priority Queue da day!\n";
            return;
        }
        a[n] = x;
        siftUp(n);
        n++;
    }

    int top() const {
        if (isEmpty()) {
            cout << "Priority Queue rong!\n";
            return -1;
        }
        return a[0];
    }

    int pop() {
        if (isEmpty()) {
            cout << "Priority Queue rong!\n";
            return -1;
        }

        int result = a[0];
        a[0] = a[n - 1];
        n--;

        if (n > 0) siftDown(0);
        return result;
    }

    void print() const {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";
    }
};

int main() {
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    cout << "Heap trong Priority Queue: ";
    pq.print();
    cout << "Phan tu uu tien cao nhat: " << pq.top() << "\n";
    cout << "Lay ra theo thu tu uu tien: ";

    while (!pq.isEmpty()) cout << pq.pop() << " ";
    cout << "\n";
    return 0;
}
