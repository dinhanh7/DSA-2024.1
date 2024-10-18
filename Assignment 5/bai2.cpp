#include<stdio.h>
typedef struct Node {
    int info;
    Node* prev;
    Node* next;
}Node;

typedef struct Node* NNode;
struct DoubleLinkedList {
    NNode L;
    NNode R;
};
 
void initDoubleLinkedList(DoubleLinkedList& DL) {
    DL.L = DL.R = NULL;
}

bool isEmpty(DoubleLinkedList DL)
{
    return (DL.L == NULL);
}

NNode createNode(int _info){
    NNode newNode=new Node;
    newNode->info=_info;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

void insertBegin(DoubleLinkedList& DL, int _info){
    NNode newNode=createNode(_info);
    if(isEmpty(DL)){
        DL.L=newNode;
        DL.R=newNode;
        DL.L->prev = DL.R;
        DL.R->next = DL.L;
    }
    else{
        newNode->next=DL.L;
        DL.L->prev=newNode;
        DL.L=newNode;
        DL.L->prev = DL.R;
        DL.R->next = DL.L;
    }
}

void insertEnd(DoubleLinkedList& DL,int _info){
    NNode newNode=createNode(_info);
    if(isEmpty(DL)){
        DL.L=newNode;
        DL.R=newNode;
        DL.L->prev = DL.R;
        DL.R->next = DL.L;
    }
    else{
        newNode->prev=DL.R;
        DL.R->next=newNode;
        DL.R=newNode;
        DL.L->prev = DL.R;
        DL.R->next = DL.L;
    }
}

void insertAfter(DoubleLinkedList& DL, NNode P, int _info){
    NNode newNode=createNode(_info);
    if(isEmpty(DL)){
        DL.L=newNode;
        DL.R=newNode;
    }
    if(P==NULL) return;
    if(P == DL.R){
        insertEnd(DL,_info);
    }
    else{
        newNode->next=P->next;
        P->next->prev=newNode;
        newNode->prev=P;
        P->next=newNode;

    }
}

void insertBefore(DoubleLinkedList& DL, NNode P, int _info){
    NNode newNode=createNode(_info);
    if(isEmpty(DL)){
        DL.L=newNode;
        DL.R=newNode;
    }
    if(P==NULL) return;
    if(P == DL.L){
        insertBegin(DL,_info);
    }
    else{
        P->prev->next=newNode;
        newNode->prev=P->prev;
        newNode->next=P;
        P->prev=newNode;
    }
}

void deleteBegin(DoubleLinkedList& DL){
    if (isEmpty(DL)) return;
    if (DL.L==DL.R){
        NNode ptr=DL.L;
        DL.L = NULL;
        DL.R=NULL;
        delete ptr;
    }
    else{
        NNode ptr=DL.L;
        DL.L = ptr->next; 
        DL.L->prev = DL.R; 
        DL.R->next = DL.L; 
        delete ptr;
    }
}

void deleteEnd(DoubleLinkedList& DL){
    if (isEmpty(DL)) return;
    if (DL.L==DL.R){
        NNode ptr=DL.L;
        DL.L = NULL;
        DL.R=NULL;
        delete ptr;
    }
    else{
        NNode ptr=DL.R;
        DL.R=ptr->prev;
        DL.R->next = DL.L;
        DL.L->prev = DL.R;
        delete ptr;
}
}

void deleteNode(DoubleLinkedList& DL, NNode P){
    if(isEmpty(DL) || P==NULL) return;
    if( DL.L==DL.R && DL.R==P){
        delete P;
        DL.L=DL.R=NULL;
    }
    else if(P==DL.L)
    {
        deleteBegin(DL);
    }
    else if(P==DL.R){
        deleteEnd(DL);
    }
    else{
        P->prev->next=P->next;
        P->next->prev=P->prev;
        delete P;
    }
}

void hienThi(DoubleLinkedList& DL){
    if(isEmpty(DL)) printf("List is empty\n");
    else{
        NNode ptr=DL.L;
        do {
            printf("%d, ", ptr->info);
            ptr = ptr->next;
        } while (ptr != DL.L); 
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
    deleteBegin(DL);
    hienThi(DL);
    deleteEnd(DL);
    hienThi(DL);
}