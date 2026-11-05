#include <iostream>
using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
 
    for (int end = n - 1; end > 0; end--) {
        int temp = a[0];
        a[0] = a[end];
        a[end] = temp;

        heapify(a, end, 0);
    }
}

int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    if (n <= 0) {
        cout << "So phan tu phai lon hon 0.\n";
        return 1;
    }

    int *a = new int[n];
    cout << "Nhap " << n << " so nguyen: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    heapSort(a, n);

    cout << "Day sau khi Heap Sort tang dan: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";

    delete[] a;
    return 0;
}
