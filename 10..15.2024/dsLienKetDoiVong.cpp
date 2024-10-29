#include<stdio.h>

typedef struct Node {
    int info;
    Node* prev;
    Node* next;
} Node;

typedef struct Node* NNode;

struct DoubleLinkedList {
    NNode L;
    NNode R;
};

void initDoubleLinkedList(DoubleLinkedList& DL) {
    DL.L = DL.R = NULL;
}

bool isEmpty(DoubleLinkedList DL) {
    return (DL.L == NULL);
}

NNode createNode(int _info) {
    NNode newNode = new Node;
    newNode->info = _info;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Chèn vào đầu danh sách
void insertBegin(DoubleLinkedList& DL, int _info) {
    NNode newNode = createNode(_info);
    if (isEmpty(DL)) {
        DL.L = newNode;
        DL.R = newNode;
        // Liên kết vòng giữa phần tử đầu và cuối
        DL.L->prev = DL.R;
        DL.R->next = DL.L;
    } else {
        newNode->next = DL.L;
        DL.L->prev = newNode;
        DL.L = newNode;
        // Cập nhật liên kết vòng
        DL.L->prev = DL.R;
        DL.R->next = DL.L;
    }
}

// Chèn vào cuối danh sách
void insertEnd(DoubleLinkedList& DL, int _info) {
    NNode newNode = createNode(_info);
    if (isEmpty(DL)) {
        DL.L = newNode;
        DL.R = newNode;
        // Liên kết vòng giữa phần tử đầu và cuối
        DL.L->prev = DL.R;
        DL.R->next = DL.L;
    } else {
        newNode->prev = DL.R;
        DL.R->next = newNode;
        DL.R = newNode;
        // Cập nhật liên kết vòng
        DL.L->prev = DL.R;
        DL.R->next = DL.L;
    }
}

// Xóa phần tử đầu tiên
void deleteBegin(DoubleLinkedList& DL) {
    if (isEmpty(DL)) return;
    if (DL.L == DL.R) {
        NNode ptr = DL.L;
        DL.L = NULL;
        DL.R = NULL;
        delete ptr;
    } else {
        NNode ptr = DL.L;
        DL.L = DL.L->next;
        DL.L->prev = DL.R;
        DL.R->next = DL.L;
        delete ptr;
    }
}

// Xóa phần tử cuối cùng
void deleteEnd(DoubleLinkedList& DL) {
    if (isEmpty(DL)) return;
    if (DL.L == DL.R) {
        NNode ptr = DL.L;
        DL.L = NULL;
        DL.R = NULL;
        delete ptr;
    } else {
        NNode ptr = DL.R;
        DL.R = DL.R->prev;
        DL.R->next = DL.L;
        DL.L->prev = DL.R;
        delete ptr;
    }
}

// Hiển thị danh sách vòng
void hienThi(DoubleLinkedList& DL) {
    if (isEmpty(DL)) {
        printf("List is empty\n");
    } else {
        NNode ptr = DL.L;
        do {
            printf("%d, ", ptr->info);
            ptr = ptr->next;
        } while (ptr != DL.L);  // Dừng lại khi quay về đầu danh sách
        printf("\n");
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
