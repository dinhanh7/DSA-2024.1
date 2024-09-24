#include<stdio.h>
#include<stdbool.h>
#define MAX 100


typedef struct {
	int info[MAX];
	int n;
}TuanTu;

void insert(TuanTu * S, int viTri, int K) {
    if (viTri-1 > S->n || viTri < 0) {
        printf("Vi tri khong hop le\n");
        return;
    }
    for (int i = S->n; i > viTri-2; i--) {
        S->info[i] = S->info[i - 1];
    }

    S->info[viTri-1] = K;
    (S->n)++;
}
int pop(TuanTu * S, int viTri) {
    if (viTri > S->n || viTri < 0) {
        printf("Vi tri khong hop le\n");
        return -1;
    }
	int a=S->info[viTri-1];
    for (int i = viTri-1; i < S->n-1; i++) {
        S->info[i] = S->info[i + 1];
    }
    (S->n)--;
	return a;
}

void Initialize(TuanTu * S){
	S->n = 0;
}
bool IsEmpty(TuanTu S){
	return (S.n == 0);
}
bool IsFull(TuanTu S){
	return(S.n == MAX);
}
void Push(int viTri, int K,TuanTu * S){
	if(IsFull(*S)) return ;
	insert(S,viTri,K);
}
int Pop(int viTri,TuanTu * S){
	if(IsEmpty(*S)) return -1 ;
	return pop(S,viTri);
}
int Top(TuanTu S){
	if(IsEmpty(S)) return -1;
	return S.info[S.n-1];
}
void Display(TuanTu S){
	for(int i = 0 ; i < S.n; i++){
		printf("%d ",S.info[i]);
	}
    printf("\n");
}
int main(){
	TuanTu S;
	Initialize(&S);
	Push(1,1,&S);    
	Push(2,2,&S);
	Push(3,3,&S);
    Push(4,4,&S);
    Push(5,5,&S);
	Push(3,10,&S);
	printf("Ngan xep gom cac phan tu: \n");
    Display(S);
    printf("\n");

    printf("Phan tu bi loai bo: %d\n", Pop(5,&S));
    printf("Phan tu o dinh hien thi: %d\n", Top(S));
    printf("Cac phan tu trong ngan xep hien tai la: \n");
    Display(S);
    printf("\n");
    printf("Phan tu bi loai bo: %d\n", Pop(1,&S));
    printf("Phan tu o dinh hien thi: %d\n", Top(S));
    printf("Cac phan tu trong ngan xep hien tai la: \n");
    Display(S);

    return 0;
}   
