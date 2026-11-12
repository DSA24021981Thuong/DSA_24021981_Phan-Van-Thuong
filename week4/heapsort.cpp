#include <iostream>
#include <algorithm>
using namespace std;

void swim(int a[], int k) {
    while (k > 1 && a[k / 2] < a[k]) {
        swap(a[k / 2], a[k]);
        k = k / 2;
    }
}

void sink(int a[], int k, int n) {
    while (2 * k <= n) {
        int j = 2 * k;

        // Chọn con lớn hơn
        if (j < n && a[j] < a[j + 1]) {
            j++;
        }

        // Nếu cha lớn hơn hoặc bằng con thì dừng
        if (a[k] >= a[j]) {
            break;
        }

        swap(a[k], a[j]);
        k = j;
    }
}

void heapSort(int a[], int n) {
    // Bước 1: Xây dựng Max Heap bằng sink
    for (int k = n / 2; k >= 1; k--) {
        sink(a, k, n);
    }

    // Bước 2: Đưa phần tử lớn nhất về cuối
    while (n > 1) {
        swap(a[1], a[n]);
        n--;
        sink(a, 1, n);
    }
}

int main() {
    int a[] = {0, 5, 3, 8, 4, 1, 9, 2};
    int n = 7;

    heapSort(a, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
