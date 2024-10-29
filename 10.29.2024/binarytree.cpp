#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    Node * LP, *RP;
}Node;

typedef struct  Node* PNode;

typedef PNode BinaryTree;

void InitBT (BinaryTree & T) {
    T = NULL;
}
// Chèn phần tử vào cây nhị phân
BinaryTree insertNode(BinaryTree T, int value) {
    if (T == NULL) {
        return createNode(value);
    } else {
        if (value < T->info) {
            T->LP = insertNode(T->LP, value);
        } else {
            T->RP = insertNode(T->RP, value);
        }
        return T;
    }
}

// Hàm dựng cây nhị phân từ mảng arr[]
void insertBT(BinaryTree T, int arr[], int n) {
    for (int i = 0; i < n; i++) {
        T = insertNode(T, arr[i]);
    }
}

//duyet cay theo thu tu truoc
void PreOrderTraversal(BinaryTree T) {
    if (T==NULL) return;
    printf("%d",T->info);
    PreOrderTraversal(T->LP);
    PreOrderTraversal(T->RP);
}

//duyet cay theo thu tu giua
void InOrderTraversal (BinaryTree T) {
    if (T==NULL) return;
    InOrderTraversal(T->LP);
    printf("%d",T->info);
    InOrderTraversal(T->RP);
}

//duyet cay theo thu tu sau
void PostOrderTraversal(BinaryTree T) {
    if (T==NULL) return;
    PostOrderTraversal(T->LP);
    PostOrderTraversal(T->RP);
    printf("%d",T->info);
}

void insertBT(BinaryTree T, int data){}