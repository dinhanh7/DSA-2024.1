#include<stdio.h>

struct Node {
    int info;
    Node* prev;
    Node* next;
};

struct DoubleLinkedList {
    Node* L;
    Node* R;
};

void initDoubleLinkedList(DoubleLinkedList& DL) {
    DL.L = DL.R = NULL;
}

int isEmpty(DoubleLinkedList& DL) {
    return (DL.L == NULL);
}

Node* createNode(int _info) {
    Node* newNode = new Node;
    newNode->info = _info;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertBegin(DoubleLinkedList& DL, int _info) {
    Node* newNode = createNode(_info);
    if (isEmpty(DL)) {
        DL.L = newNode;
        DL.R = newNode;
    } else {
        newNode->next = DL.L;
        DL.L->prev = newNode;
        DL.L = newNode;
    }
}

void insertEnd(DoubleLinkedList& DL, int _info) {
    Node* newNode = createNode(_info);
    if (isEmpty(DL)) {
        DL.L = newNode;
        DL.R = newNode;
    } else {
        DL.R->next = newNode;
        newNode->prev = DL.R;
        DL.R = newNode;
    }
}

// Insert a node after node P
void insertAfter(DoubleLinkedList& DL, Node* P, int _info) {
    Node* newNode = createNode(_info);
    if (isEmpty(DL) || P == NULL)
        return;
    if (P == DL.R) {
        insertEnd(DL, _info);
    } else {
        newNode->next = P->next;
        P->next->prev = newNode;
        newNode->prev = P;
        P->next = newNode;
    }
}

// Insert a node before node P
void insertBefore(DoubleLinkedList& DL, Node* P, int _info) {
    Node* newNode = createNode(_info);
    if (isEmpty(DL)) {
        DL.L = newNode;
        DL.R = newNode;
        return;
    }
    if (P == NULL)
        return;
    if (P == DL.L) {
        insertBegin(DL, _info);
    } else {
        newNode->prev = P->prev;
        newNode->next = P;
        P->prev->next = newNode;
        P->prev = newNode;
    }
}

void deleteBegin(DoubleLinkedList& DL) {
    if (isEmpty(DL))
        return;
    if (DL.L == DL.R) { // Only one element
        Node* ptr = DL.L;
        DL.L = NULL;
        DL.R = NULL;
        delete ptr;
    } else { // General case
        Node* ptr = DL.L;
        DL.L = ptr->next;
        DL.L->prev = NULL;
        delete ptr;
    }
}

void deleteEnd(DoubleLinkedList& DL) {
    if (isEmpty(DL))
        return;
    if (DL.L == DL.R) { // Only one element
        Node* ptr = DL.L;
        DL.L = NULL;
        DL.R = NULL;
        delete ptr;
    } else {
        Node* ptr = DL.R;
        DL.R = ptr->prev;
        DL.R->next = NULL;
        delete ptr;
    }
}

void deleteNode(DoubleLinkedList& DL, Node* P) {
    if (isEmpty(DL) || P == NULL)
        return;
    if (DL.L == P && DL.R == P) { // Only one node
        delete P;
        DL.L = DL.R = NULL;
    } else if (P == DL.L) {
        deleteBegin(DL);
    } else if (P == DL.R) {
        deleteEnd(DL);
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
        delete P;
    }
}

void hienThi(DoubleLinkedList& DL) {
    if (isEmpty(DL)) {
        printf("\nList is empty");
    } else {
        Node* ptr = DL.L;
        while (ptr != NULL) {
            printf("%d, ", ptr->info);
            ptr = ptr->next;
        }
    }
}

int main() {
    DoubleLinkedList DL;
    initDoubleLinkedList(DL);
    insertBegin(DL, 11);
    insertBegin(DL, 22);
    insertBegin(DL, 33);
    hienThi(DL);
}
