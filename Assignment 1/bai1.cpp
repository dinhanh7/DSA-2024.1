#include<stdio.h>
#include<stdbool.h>
#define MAX 100

typedef struct {
	int info[MAX];
	int n;
}Stack;
void Initialize(Stack * S){
	S->n = 0;
}
bool IsEmpty(Stack S){
	return (S.n == 0);
}
bool IsFull(Stack S){
	return(S.n == MAX);
}
void Push(int K,Stack * S){
	if(IsFull(*S)) return  ;
	S->info[S->n] = K;
	S->n++;
}
int Pop(Stack * S){
	if(IsEmpty(*S)) return -1 ;
	S->n--;
	return S->info[S->n];
}
int Top(Stack S){
	if(IsEmpty(S)) return -1;
	return S.info[S.n-1];
}
void Display(Stack S){
	for(int i = 0 ; i < S.n; i++){
		printf("%d ",S.info[i]);
	}
    printf("\n");
}
int main(){
	Stack S;
	Initialize(&S);
	Push(1,&S);    
	Push(2,&S);
	Push(3,&S);
    Push(4,&S);
    Push(5,&S);
	printf("Ngan xep gom cac phan tu: \n");
    Display(S);
    printf("\n");

    printf("Phan tu dinh bi loai bo: %d\n", Pop(&S));
    printf("Phan tu o dinh hien thi: %d\n", Top(S));
    printf("Cac phan tu trong ngan xep hien tai la: \n");
    Display(S);
    printf("\n");
    printf("Phan tu dinh bi loai bo: %d\n", Pop(&S));
    printf("Phan tu o dinh hien thi: %d\n", Top(S));
    printf("Cac phan tu trong ngan xep hien tai la: \n");
    Display(S);

    return 0;
}   
