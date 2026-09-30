#include <iostream>
using namespace std;

void insertHead(int a[], int &n, int x) {
    for (int i = n; i > 0; i--) a[i] = a[i - 1];
    a[0] = x;
    n++;
}

void insertTail(int a[], int &n, int x) {
    a[n++] = x;
}

void insertAt(int a[], int &n, int k, int x) {
    if (k < 0 || k > n) return;
    for (int i = n; i > k; i--) a[i] = a[i - 1];
    a[k] = x;
    n++;
}

void deleteHead(int a[], int &n) {
    if (n == 0) return;
    for (int i = 0; i < n - 1; i++) a[i] = a[i + 1];
    n--;
}

void deleteTail(int a[], int &n) {
    if (n > 0) n--;
}

void deleteAt(int a[], int &n, int k) {
    if (k < 0 || k >= n) return;
    for (int i = k; i < n - 1; i++) a[i] = a[i + 1];
    n--;
}

void printForward(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << '\n';
}

void printBackward(int a[], int n) {
    for (int i = n - 1; i >= 0; i--) cout << a[i] << " ";
    cout << '\n';
}

int main() {
    int a[100] = {10, 20, 30, 40};
    int n = 4;

    cout << "Ban dau: ";
    printForward(a, n);

    insertHead(a, n, 5);
    insertTail(a, n, 50);
    insertAt(a, n, 2, 99);
    cout << "Sau khi chen: ";
    printForward(a, n);

    deleteHead(a, n);
    deleteTail(a, n);
    deleteAt(a, n, 2);
    cout << "Sau khi xoa: ";
    printForward(a, n);

    cout << "Duyet nguoc: ";
    printBackward(a, n);
}
