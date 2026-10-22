#ifndef ARRAYLIST_H
#define ARRAYLIST_H

// Array list operations: insertHead O(n), insertTail O(1), insertAt O(n),
// deleteHead O(n), deleteTail O(1), deleteAt O(n), assuming shifting is required.
void insertHead(int a[], int &n, int x);
void insertTail(int a[], int &n, int x);
void insertAt(int a[], int &n, int k, int x);
void deleteHead(int a[], int &n);
void deleteTail(int a[], int &n);
void deleteAt(int a[], int &n, int k);

#endif
