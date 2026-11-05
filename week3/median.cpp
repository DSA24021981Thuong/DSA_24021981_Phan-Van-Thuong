#include <iostream>
using namespace std;

void findMedian(double a[], int n) {
    //Insertion Sort
    for (int i = 1; i < n; i++) {
        double key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    //Tim median
    if (n % 2 == 1)
        cout << "Median = " << a[n / 2];
    else
        cout << "Median = "
             << (a[n / 2 - 1] + a[n / 2]) / 2.0;
}

int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    if (n <= 0) {
        cout << "So phan tu khong hop le!";
        return 0;
    }

    double *a = new double[n];

    cout << "Nhap day so:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    findMedian(a, n);

    delete[] a;
    return 0;
}
