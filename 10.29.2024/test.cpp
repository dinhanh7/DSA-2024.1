#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    Node *LP, *RP;
} Node;

typedef struct Node* PNode;

typedef PNode BinaryTree;

// Tạo node mới
PNode createNode(int value) {
    PNode newNode = (PNode)malloc(sizeof(Node));
    newNode->info = value;
    newNode->LP = newNode->RP = NULL;
    return newNode;
}

// Chèn phần tử vào cây nhị phân
void insertNode(BinaryTree &T, int value) {
    if (T == NULL) {
        T = createNode(value);
    } else {
        if (value < T->info) {
            insertNode(T->LP, value);
        } else {
            insertNode(T->RP, value);
        }
    }
}

// Hàm dựng cây nhị phân từ mảng arr[]
void insertBT(BinaryTree &T, int arr[], int n) {
    for (int i = 0; i < n; i++) {
        insertNode(T, arr[i]);
    }
}

// Duyệt cây theo thứ tự trước
void PreOrderTraversal(BinaryTree T) {
    if (T == NULL) return;
    printf("%d ", T->info);
    PreOrderTraversal(T->LP);
    PreOrderTraversal(T->RP);
}

// Duyệt cây theo thứ tự giữa
void InOrderTraversal(BinaryTree T) {
    if (T == NULL) return;
    InOrderTraversal(T->LP);
    printf("%d ", T->info);
    InOrderTraversal(T->RP);
}

// Duyệt cây theo thứ tự sau
void PostOrderTraversal(BinaryTree T) {
    if (T == NULL) return;
    PostOrderTraversal(T->LP);
    PostOrderTraversal(T->RP);
    printf("%d ", T->info);
}

int main() {
    BinaryTree T = NULL;

    // Mảng các phần tử để chèn vào cây
    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Dựng cây nhị phân từ mảng
    insertBT(T, arr, n);

    // Duyệt cây
    printf("Duyet theo thu tu truoc (PreOrder):\n");
    PreOrderTraversal(T);
    printf("\n");

    printf("Duyet theo thu tu giua (InOrder):\n");
    InOrderTraversal(T);
    printf("\n");

    printf("Duyet theo thu tu sau (PostOrder):\n");
    PostOrderTraversal(T);
    printf("\n");

    return 0;
}
