#include <stdio.h>
#include <stdbool.h>

#define MAX 10

struct Queue {
    int front;
    int rear;
    int infor[MAX];
};

// Hàm khởi tạo hàng đợi
void initialize(struct Queue* Q) {
    Q->front = -1;
    Q->rear = -1;
}

// Hàm kiểm tra hàng đợi rỗng
bool isQueueEmpty(struct Queue* Q) {
    return (Q->front == -1 || Q->front > Q->rear);
}

// Hàm thêm phần tử vào hàng đợi
void enQueue(struct Queue* Q, int k) {
    if (Q->rear == MAX - 1) {
        printf("Hang doi day\n");
        return;
    }
    if (Q->front == -1) {
        Q->front = Q->rear = 0;
    } else {
        Q->rear++;
    }
    Q->infor[Q->rear] = k;
}

// Hàm lấy phần tử khỏi hàng đợi
int deQueue(struct Queue* Q) {
    if (isQueueEmpty(Q)) {
        printf("Hang doi rong\n");
        return -1;
    }
    int item = Q->infor[Q->front];
    Q->front++;
    if (Q->front > Q->rear) {
        Q->front = Q->rear = -1; // Đặt lại trạng thái trống
    }
    return item;
}
