#include<stdio.h>
#include<string.h>

//Ham de quy tim UCLN cua hai so nguyen duong
int UCLN(int a, int b){
    if (b==0) return a;
    return UCLN(b,a%b);
}

//Ham de quy tinh tong cac chu so cua so nguyen duong
int tongChuSo(int a)
{
    if (a==0) return 0;
    return a%10 + tongChuSo(a/=10);
}

//Ham de quy dao nguoc chuoi ki tu
void daoNguoc(char str[],int start, int end){
    if (strlen(str)==1) return;
    char temp=str[start];
    str[start]=str[end];
    str[end]=temp;
    if (start>=end) return ;
    daoNguoc(str,start+1,end-1);
}

//Ham de quy tinh to hop nCk
int toHop(int n, int k){
   if(k==0 || n==k) return 1;
   return toHop(n-1,k-1)+toHop(n-1,k);
}


//Ham de quy in ra mot day n so theo CSC voi khoang cach d, xuat phat tu m
void dayCSC(int n, int d, int m){
    if(m>n+d*(n-1)) return;
    printf("%d ",m);
    dayCSC(n,d,m+d);
}

int main() {
    // 1. UCLN
    int a = 56, b = 98;
    printf("UCLN cua %d va %d la: %d\n", a, b, UCLN(a, b));
    
    // 2. tong cac chu so
    int number = 12345;
    printf("Tong cac chu so cua %d la: %d\n", number, tongChuSo(number));
    
    // 3. dao nguoc chuoi
    char str[] = "hello";
    printf("Chuoi truoc khi dao nguoc: %s\n", str);
    daoNguoc(str, 0, strlen(str) - 1);
    printf("Chuoi sau khi dao nguoc: %s\n", str);
    
    // 4. to hop C(n, k)
    int n = 5, k = 2;
    printf("To hop C(%d, %d) la: %d\n", n, k, toHop(n, k));
    
    // 5. day so theo cap so cong
    int khoangCach = 3, m = 1;
    printf("Day CSC co khoang cach %d va xuat phat tu %d la: ", khoangCach, m);
    dayCSC(n, khoangCach, m);
    printf("\n");

    return 0;
}