
#include<stdio.h>
#include<stdbool.h>
#define MAX 100

typedef struct {
    int info[MAX];
    int n;
} Stack;

void Initialize(Stack *S) {
    S->n = 0;
}

bool IsFull(Stack S) {
    return (S.n == MAX);
}

bool IsEmpty(Stack S) {
    return (S.n == 0);
}

void ConVert(int a, int b, Stack *S) {
    if(a == 0) {
        S->info[S->n] = 0;
        S->n++;
        return;
    }
    
    while (a != 0) {
        int r = a % b;
        S->info[S->n] = r;
        a /= b;
        S->n++;
    }
}

void DisPlayResult(Stack S) {
    if (IsEmpty(S)) {
        printf("Ngan xep khong co phan tu nao\n");
        return;
    } else {
        for (int i = S.n - 1; i >= 0; i--) {
            printf("%d", S.info[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack S;
    Initialize(&S);
    int a = 1236;
    int b = 16;
    ConVert(a, b, &S);
    DisPlayResult(S);
    return 0;
}
