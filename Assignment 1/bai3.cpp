#include <stdio.h>
#define  MAX 10
struct Queue
{
    int front; 
    int rear; 
    int infor[MAX];
};
void initialize(Queue* Q)
{
    Q->front = -1;
    Q->rear = -1;
}
 
void enQueue(Queue* Q, int k)
{
    if (Q->front == -1) 
    {
        Q->front = Q->rear = 0;
        Q->infor[0] = k;
    }
    else if (Q->rear == MAX - 1)
    {
        return;
    }
    else
    {
        Q->rear++;
        Q->infor[Q->rear] = k;
    }
}
 
int deQueue(Queue* Q) {
    if (Q->front == -1) {
        printf("Hang doi rong\n");
        return -1;
    }
    else {
        int a= Q->front;
        if (Q->front > Q->rear)
            Q->front = Q->rear = -1;
        else if (Q->front == Q->rear) {
            int a= Q->front-1;
            Q->front = Q->rear = -1;
        }
        else {
            Q->front++;
        }
        return (Q->infor[a]);
    }
}

void display(Queue Q)
{
    if (Q.front == -1) {
        printf("Hang doi rong\n");
        return;
    printf("\n");}
    else{
    for (int i = Q.front; i <= Q.rear; i++)
    {
        printf("%d ", Q.infor[i]);
    }
    printf("\n");
    }
}
 
int main()
{
    Queue Q;
    initialize(&Q);
    enQueue(&Q, 1);
    enQueue(&Q, 2);
    enQueue(&Q, 3);
    enQueue(&Q, 4);
    printf("Danh sach hang cho la:\n");
    display(Q);
    printf("Phan tu da xoa la: %d\n", deQueue(&Q));
    printf("Danh sach hang cho sau khi xoa la:\n");
    display(Q);
    printf("Phan tu da xoa la: %d\n", deQueue(&Q));
    printf("Danh sach hang cho sau khi xoa la:\n");
    display(Q);
    return 0;
}
