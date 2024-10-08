#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Node* Qnode;

struct Queue {
    Qnode front;
    Qnode rear;
};

// Hàm tạo một node mới
Qnode createNode(int data) {
    Qnode newNode = (Qnode)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
typedef struct Queue* Qqueue;

// Hàm tạo hàng đợi rỗng
Qqueue createQueue() {
    Qqueue queue = (Qqueue)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Hàm thêm một phần tử vào hàng đợi (enqueue)
void enqueue(Qqueue queue, int data) {
    Qnode newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        printf("%d da duoc them vao hang doi.\n", data);
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("%d da duoc them vao hang doi.\n", data);
}

// Hàm xóa một phần tử khỏi hàng đợi (dequeue)
int dequeue(Qqueue queue) {
    if (queue->front == NULL) {
        printf("Hang doi rong, khong the thuc hien dequeue.\n");
        return -1;
    }

    Qnode temp = queue->front;
    int data = temp->data;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);  
    return data;
}

// Hàm xem phần tử đầu tiên của hàng đợi (peek)
int peek(Qqueue queue) {
    if (queue->front == NULL) {
        printf("Hang doi rong.\n");
        return -1;
    }
    return queue->front->data;
}

// Hàm kiểm tra hàng đợi có rỗng không
int isEmpty(Qqueue queue) {
    return queue->front == NULL;
}

// Hàm hiển thị các phần tử trong hàng đợi
void display(Qqueue queue) {
    if (queue->front == NULL) {
        printf("Hang doi rong\n");
        return;
    }

    Qnode temp = queue->front;
    printf("Cac phan tu trong hang doi: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Qqueue queue = createQueue();  

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);  

    printf("Phan tu dau tien trong hang doi: %d\n", peek(queue));

    printf("Phan tu vua lay ra: %d\n", dequeue(queue));
    display(queue);

    return 0;
}

