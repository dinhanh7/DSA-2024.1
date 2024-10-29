#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc cua mot node trong hang doi uu tien
typedef struct Node {
    int data;      // Du lieu
    int priority;  // Do uu tien
    struct Node* next;
}Node;
typedef struct Node* Pnode;

// Ham tao mot node moi
Pnode createNode(int data, int priority) {
    Pnode newNode = (Pnode)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Ham them phan tu vao hang doi uu tien (enqueue)
void enqueue(Pnode* head, int data, int priority) {
    Pnode newNode = createNode(data, priority);

    // Neu hang doi trong hoac do uu tien cua phan tu moi cao hon phan tu dau tien
    if (*head == NULL || (*head)->priority > priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // Tim vi tri thich hop de chen phan tu moi dua tren do uu tien
        Pnode temp = *head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Phan tu %d voi do uu tien %d da duoc them vao hang doi uu tien.\n", data, priority);
}

// Ham xoa phan tu co do uu tien cao nhat khoi hang doi (dequeue)
int dequeue(Pnode* head) {
    if (*head == NULL) {
        printf("Hang doi uu tien rong. Khong the thuc hien dequeue.\n");
        return -1;
    }

    Pnode temp = *head;
    int data = temp->data;

    *head = (*head)->next;  // Cap nhat head
    free(temp);  // Giai phong bo nho cho node bi xoa
    return data;
}

// Ham lay phan tu co do uu tien cao nhat (ma khong xoa)
int getHighestPriority(Pnode head) {
    if (head == NULL) {
        printf("Hang doi uu tien rong.\n");
        return -1;
    }

    Pnode temp = head;
    int maxPriority = temp->priority;
    int maxData = temp->data;

    // Duyet qua toan bo danh sach de tim phan tu co do uu tien cao nhat
    while (temp != NULL) {
        if (temp->priority > maxPriority) {
            maxPriority = temp->priority;
            maxData = temp->data;
        }
        temp = temp->next;
    }

    return maxData;
}


// Ham kiem tra hang doi co rong khong
int isEmpty(Pnode head) {
    return head == NULL;
}

// Ham hien thi cac phan tu trong hang doi uu tien
void display(Pnode head) {
    if (head == NULL) {
        printf("Hang doi uu tien rong.\n");
        return;
    }

    Pnode temp = head;
    printf("Cac phan tu trong hang doi uu tien: ");
    while (temp != NULL) {
        printf("%d(do uu tien %d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Pnode pq = NULL;  // Khoi tao hang doi uu tien rong

    enqueue(&pq, 10, 9);
    enqueue(&pq, 20, 5);
    enqueue(&pq, 30, 3);
    enqueue(&pq, 50, 10);
    display(pq);  // Hien thi cac phan tu trong hang doi uu tien

    printf("Phan tu co do uu tien cao nhat la: %d\n", getHighestPriority(pq));  // Lay phan tu co do uu tien cao nhat

    printf("Phan tu vua lay ra: %d\n", dequeue(&pq));
    display(pq);  // Hien thi hang doi uu tien sau khi dequeue

    return 0;
}
