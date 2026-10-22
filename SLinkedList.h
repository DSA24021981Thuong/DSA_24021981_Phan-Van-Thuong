#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

struct Node {
    int data;
    Node* next;
};

// Singly linked list operations: createNode O(1), insertHead O(1),
// insertTail O(n) without a tail pointer, insertAt O(n), deleteHead O(1),
// deleteTail O(n), deleteAt O(n).
Node* createNode(int x);
void insertHead(Node*& head, int x);
void insertTail(Node*& head, int x);
void insertAt(Node*& head, int k, int x);
void deleteHead(Node*& head);
void deleteTail(Node*& head);
void deleteAt(Node*& head, int k);

#endif
