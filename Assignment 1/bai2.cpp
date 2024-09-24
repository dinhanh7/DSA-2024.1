#include<stdio.h>
#include<string.h> 
#include<stdbool.h>
#define MAX 100

typedef struct {
    int page;
    char name[100];
    char author[30];
}Book;
Book rong = {0, "", ""};
typedef struct {
	Book sach[MAX];
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
void Push(Book K,Stack * S){
	if(IsFull(*S)) return  ;
	S->sach[S->n].page = K.page;
    strcpy(S->sach[S->n].name, K.name);
    strcpy(S->sach[S->n].author, K.author);
	S->n++;
}
Book Pop(Stack * S){
	if(IsEmpty(*S)) return rong;
	S->n--;
	return S->sach[S->n];
}
Book Top(Stack S){
	if(IsEmpty(S)) return rong;
	return S.sach[S.n-1];
}
void DisplayStack(Stack S){
	for(int i = 0 ; i < S.n; i++){
		printf("%d.Ten sach: %s\nSo trang:%d\nTac gia: %s\n",i+1,S.sach[i].name,S.sach[i].page,S.sach[i].author);
	}
    printf("\n");
}
void DisplayBook(Book K){
	printf("\nTen sach: %s\nSo trang:%d\nTac gia: %s\n ",K.name,K.page,K.author);
    printf("\n");
}
int main(){
	Stack S;
	Book book1={230,"Qua tang cuoc song","Nguyen Van Anh"};
	Book book2={741,"Hay luon yeu doi","Le Hoang Tuan"};
	Book book3={523,"Ky nang giao tiep","Nguyen Tuan Minh"};
	Book book4={460,"Long nhan ai","Pham Anh Khoa"};

	Push(book1,&S);    
	Push(book2,&S);
	Push(book3,&S);
    Push(book4,&S);
	printf("Ngan xep gom cac phan tu: \n");
    DisplayStack(S);
    printf("\n");

    printf("Phan tu dinh bi loai bo:");
    DisplayBook(Pop(&S));
    printf("Phan tu o dinh hien thi:");
    DisplayBook(Top(S));
    printf("Cac phan tu trong ngan xep hien tai la: \n");
    DisplayStack(S);
    printf("\n");
    printf("Phan tu dinh bi loai bo:");
    DisplayBook(Pop(&S));
    printf("Phan tu o dinh hien thi:");
    DisplayBook(Top(S));
    printf("Cac phan tu trong ngan xep hien tai la: \n");
    DisplayStack(S);
    printf("\n");
    return 0;
}   
