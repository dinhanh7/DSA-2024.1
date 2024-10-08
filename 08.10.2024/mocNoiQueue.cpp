#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một node
typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Node* Qnode;
// Định nghĩa cấu trúc của hàng đợi
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
    // Nếu hàng đợi rỗng, cả front và rear đều trỏ tới node mới
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        printf("%d đã được thêm vào hàng đợi.\n", data);
        return;
    }

    // Thêm node mới vào cuối hàng đợi và cập nhật rear
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("%d đã được thêm vào hàng đợi.\n", data);
}

// Hàm xóa một phần tử khỏi hàng đợi (dequeue)
int dequeue(Qqueue queue) {
    if (queue->front == NULL) {
        printf("Hàng đợi rỗng. Không thể thực hiện dequeue.\n");
        return -1;
    }

    Qnode temp = queue->front;
    int data = temp->data;

    // Di chuyển front đến node tiếp theo
    queue->front = queue->front->next;

    // Nếu front trở thành NULL, rear cũng phải là NULL (hàng đợi rỗng)
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);  // Giải phóng bộ nhớ của node vừa bị xóa
    return data;
}

// Hàm xem phần tử đầu tiên của hàng đợi (peek)
int peek(Qqueue queue) {
    if (queue->front == NULL) {
        printf("Hàng đợi rỗng.\n");
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
    Qqueue queue = createQueue();  // Khởi tạo hàng đợi rỗng

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);  // Hiển thị các phần tử trong hàng đợi

    printf("Phần tử đầu tiên trong hàng đợi: %d\n", peek(queue));

    printf("Phần tử vừa lấy ra: %d\n", dequeue(queue));
    display(queue);  // Hiển thị hàng đợi sau khi dequeue

    return 0;
}
