#include<stdio.h>
#include<stdbool.h>
#define MAX 100


typedef struct {
    int data;
    int priority;
}Element;

typedef struct 
{
    Element infor[MAX];
    int size;
}PriorityQ;
//ham ktra day
bool isFull(PriorityQ P)
{
    return P.size==MAX;
}
//ham ktra rong
bool isEmpty(PriorityQ P){
    return P.size==0;
}
//ham khoi tao
void Initialize(PriorityQ *P)
{
    P->size=0;
}
//ham enQueue
void enQueue(PriorityQ * P, Element E)
{
    if (isFull(*P)){
        return;
        }
    else{
        int i = P->size-1;
        while (i >= 0 && E.priority > P->infor[i].priority) {
        P->infor[i + 1] = P->infor[i];
        i--;
        }
        P->infor[i+1]=E;
        P->size++;
        }
    }
//ham deQueue
Element Eno;
Element deQueue(PriorityQ * P)
{
    if (isEmpty(*P)){
        printf("Hang doi rong\n");
        return Eno;
    }
    else{
        Element tra=P->infor[0];
        for(int i=0;i<P->size;i++)
        {
            P->infor[i]=P->infor[i+1];
        }
        P->size--;
        return tra;
    }

}
//ham hien thi
void display(PriorityQ P) {
    if (isEmpty(P)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Hang doi uu tien (data, priority):\n");
    for (int i = 0; i < P.size; i++) {
        printf("(%d, %d) ", P.infor[i].data, P.infor[i].priority);
    }
    printf("\n");
}

int main()
{
    Element E1={100,3};
    Element E2={215,4};
    Element E3={95,2};
    Element E4={23,6};
    Element E5={315,1};
    PriorityQ P;
    Initialize(&P);
    enQueue(&P,E1);
    enQueue(&P,E2);
    enQueue(&P,E3);
    enQueue(&P,E4);
    enQueue(&P,E5);
    printf("Sau khi them 5 phan tu:\n");
    display(P);
    deQueue(&P);
    deQueue(&P);
    printf("\n");
    printf("Sau khi xoa 2 phan tu:\n");
    display(P);
    return 0;
}
