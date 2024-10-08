#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;    
    int priority;  
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


    if (*head == NULL || (*head)->priority > priority) {
        newNode->next = *head;
        *head = newNode;
    } else {

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

    *head = (*head)->next; 
    free(temp); 
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
    Pnode pq = NULL; 

    enqueue(&pq, 10, 9);
    enqueue(&pq, 20, 5);
    enqueue(&pq, 30, 3);
    enqueue(&pq, 50, 10);
    display(pq);  

    printf("Phan tu co do uu tien cao nhat la: %d\n", getHighestPriority(pq));  

    printf("Phan tu vua lay ra: %d\n", dequeue(&pq));
    display(pq); 
    return 0;
}

