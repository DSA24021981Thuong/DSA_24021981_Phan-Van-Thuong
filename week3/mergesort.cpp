#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int *b = new int[r - l + 1];
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];

    while (i <= m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];

    for (i = 0; i < k; i++) a[l + i] = b[i];
    delete[] b;
}

void mergeSort(int a[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}
