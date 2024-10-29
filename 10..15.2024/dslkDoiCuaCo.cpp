#include<stdio.h>
struct Node {
    int info;
    Node* nextL;
    Node* nextR;
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
    newNode->nextL = NULL;
    newNode->nextR = NULL;
    return newNode;
}
 
void insertBegin(DoubleLinkedList& DL, int _info) {
    Node* newNode = createNode(_info);
    if (isEmpty(DL)) {
        DL.L = newNode;
        DL.R = newNode;
    }
    else {
        newNode->nextR = DL.L;
        DL.L->nextL = newNode;
        DL.L = newNode;
    }
}
 
void insertEnd(DoubleLinkedList& DL, int _info) {
    Node* newNode = createNode(_info);
    if (isEmpty(DL)) {
        DL.L = newNode;
        DL.R = newNode;
    }
    else {
        DL.R->nextR = newNode;
        newNode->nextL = DL.R;
        DL.R = newNode;
    }
}
 
//bo sung phan tu vao sau P
void insertAfter(DoubleLinkedList& DL, Node* P, int _info) {
    Node* newNode = createNode(_info);
    if (isEmpty(DL))
        return;
    if (P == NULL)
        return;
    if (P == DL.R)
        insertEnd(DL, _info);
    else{
        newNode->nextR = P->nextR;
        P->nextR->nextL = newNode;
        newNode->nextL = P;
        P->nextR = newNode;
    }
 
}
 
void insertBefore(DoubleLinkedList& DL, Node* P, int _info) {
    Node* newNode = createNode(_info);
    if (isEmpty(DL)) {
        DL.L = newNode;
        DL.R = newNode;
        return;
    }   
    if (P == NULL)
        return;
    if (P == DL.L)
        insertBegin(DL, _info);
    else {
        newNode->nextL = P->nextL;
        newNode->nextR = P;
        P->nextL = newNode;
        newNode->nextL->nextR = newNode;
    }
}
 
void deleteBegin(DoubleLinkedList& DL) {
    if (isEmpty(DL))
        return;
    if (DL.L == DL.R) {//ds chi co 1 phan tu
        Node* ptr = DL.L;
        DL.L = NULL;
        DL.R = NULL;
        delete ptr;
    }
    else {//truong hop tong quat
        Node* ptr = DL.L;
        DL.L = ptr->nextR;
        DL.L->nextL = NULL;
        delete ptr;
    }
}
 
void deleteEnd(DoubleLinkedList& DL) {
    if (isEmpty(DL))
        return;
    if (DL.L == DL.R) {//ds chi co 1 phan tu
        Node* ptr = DL.L;
        DL.L = NULL;
        DL.R = NULL;
        delete ptr;
    }
 
    else {
        Node* ptr = DL.R;
        DL.R = ptr->nextL;
        DL.R->nextR = NULL;
        delete ptr;
    }
}
 
void deleteNode(DoubleLinkedList& DL, Node* P) {
    if (isEmpty(DL))
        return;
    if (P == NULL)
        return;
    if (DL.L == P && DL.R == P) {//ds co 1 ptu chinh la P
        delete P;
        DL.L = DL.R = NULL;
    }
    if (P == DL.L) {
        deleteBegin(DL);
        return;
        if (P == DL.R) {
            deleteEnd(DL);
            return;
        }
    }
    P->nextL->nextR = P->nextR;
    P->nextR->nextL = P->nextL;
    delete P;
}
 
void hienThi(DoubleLinkedList& DL) {
    if (isEmpty(DL)) {
        printf("\n ds rong");
    }
    else {
        Node* ptr = DL.L;
        while (ptr != NULL) {
            printf("%d, ", ptr->info);
            ptr = ptr->nextR;
 
        }
    }
}
 
 
//hien thi
//search
//giong ds lien ket don
 
int main() {
    DoubleLinkedList DL;
    initDoubleLinkedList(DL);
    insertBegin(DL, 11);
    insertBegin(DL, 22);
    insertBegin(DL, 33);
    hienThi(DL);
    }