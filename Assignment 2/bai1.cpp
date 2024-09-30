#include<stdio.h>
#include<stdbool.h>
#define size 5

typedef struct {
	int info[size];
	int front,rear;
}CircleQueue;

void Initialize(CircleQueue * C){
	C->front=-1;
    C->rear=-1;
}
bool IsEmpty(CircleQueue C){
	return (C.front == -1);
}
bool IsFull(CircleQueue C){
	return((C.rear % size +1) == (C.front % size) || ((C.rear%size)+1 ==size)&C.front==0);
}
void Enqueue(CircleQueue * C, int value){
    if (IsFull(*C)){
        printf("Hang doi day. Khong the them phan tu\n");
        return;
    }
    if (IsEmpty(*C)){
        C->front=0;
    }
    C->rear=(C->rear+1)%size;
    C->info[C->rear]=value;
    printf("Hang doi them phan tu: %d \n",value);
}
void Dequeue(CircleQueue * C){
    if ((IsEmpty(*C))) {
        printf("Hang doi rong. Khong the lay phan tu\n");
        return;
    }
    printf("Phan tu bi xoa: %d \n",C->info[C->front]);
    if ((C->front)%size == (C->rear)%size){
        C->front=C->rear=-1;
    }
    else{
        C->front=(C->front+1)%size;
    }
}
void Display(CircleQueue C){
    if (IsEmpty(C)){
        printf("Hang doi rong\n");
        return;
    }
    printf("Cac phan tu trong hang doi: ");
    if ((C.rear%size)>(C.front%size))
    {
        for(int i=C.front;i<=C.rear;i++){
            printf("%d ",C.info[i]);
        }
        printf("\n");
    }
    if ((C.rear%size) < (C.front%size)){
        for(int i=0;i<size;i++){
            printf("%d ",C.info[i]);
        }
        printf("\n");
    }
    }

int main() {
    CircleQueue q;
    Initialize(&q);

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);
    Enqueue(&q, 50);
    Enqueue(&q, 60);
    Enqueue(&q, 70);

    Display(q); 

    Dequeue(&q);
    Dequeue(&q);

    Display(q); 

    Enqueue(&q, 80);
    Enqueue(&q, 90);

    Display(q); 

    return 0;
}
