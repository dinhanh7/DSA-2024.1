#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
}Node;


typedef struct Node* Snode;

// Hàm tạo node mới với giá trị data
Snode createNode(int data) {
    Snode newNode = (Snode)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm phần tử vào stack (push)
void push(Snode* top, int data) {
    Snode newNode = createNode(data);
    if (newNode == NULL) {
        printf("Chua duoc cap phat bo nho\n");
        return;
    }
    newNode->next = *top;  
    *top = newNode;        
    printf("%d da duoc them vao stack\n", data);
}

// Hàm xóa phần tử khỏi stack (pop)
int pop(Snode* top) {
    if (*top == NULL) {
        printf("Stack rong, khong the thuc hien pop\n");
        return -1;
    }
    Snode temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next; 
    free(temp);          
    return poppedData;
}

// Hàm trả về phần tử ở đầu stack mà không xóa
int peek(Snode top) {
    if (top == NULL) {
        printf("Stack rong.\n");
        return -1;
    }
    return top->data;
}

// Hàm kiểm tra stack có rỗng không
int isEmpty(Snode top) {
    return top == NULL;
}

// Hàm trả về kích thước (số lượng phần tử) của stack
int size(Snode top) {
    int count = 0;
    Snode temp = top;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

//Ham hien thi tat ca phan tu
void display(Snode top){
    if (top==NULL){
        printf("Stack rong\n");
    }
    Snode temp=top;
    printf("Stack gom: ");
    while(temp != NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    Snode stack = createNode(50);
    display(stack);
    push(&stack, 10);
    display(stack);
    push(&stack, 20);
    display(stack);
    push(&stack, 30);
    display(stack);

    printf("Phan tu tren cung cua Stack %d\n", peek(stack));
    printf("So luong phan tu cua Stack: %d\n", size(stack));
    printf("Phan tu vua lay ra: %d\n", pop(&stack));
    display(stack);
    printf("Phan tu tren cung cua stack sau khi pop: %d\n", peek(stack));
    printf("So luong phan tu trong stack sau khi pop: %d\n", size(stack));

    return 0;
}

