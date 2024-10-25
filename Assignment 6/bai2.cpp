#include<stdio.h>
#include<string.h>
#include<math.h>

//Ham tim UCLN cua hai so nguyen duong
int UCLN(int a, int b){
    int lon= a>b? a:b;
    int be=a<b? a:b;
    if (lon%be == 0)  return be;
    int n=sqrt(lon);
    int ucln=1;
    for(int i=2;i<=n;i++){
        if (lon%i==0 && be%i==0) ucln=i; 
    }
    return ucln;
}
//Ham tinh tong cac chu so cua so nguyen duong
int tongChuSo(int a){
    int tong=0;
    while(a!=0){
        tong+=(a%10);
        a/=10;
    }
    return tong;
}

//Ham dao nguoc chuoi ki tu
void daoNguoc(char str[]){
    int n=strlen(str);
    char temp;
    for(int i=0;i<n/2;i++){
        temp=str[i];
        str[i]=str[n-1-i];
        str[n-1-i]=temp;
    }
}

//Ham tinh to hop C(n,k)
int giaiThua(int n){
    int count=0;
    for(int i=1;i<=n;i++){
        count+=i;
    }
    return count;
}
int toHop(int n, int k){
    return giaiThua(n)/(giaiThua(k)*giaiThua(n-k));
}

//Ham in ra mot day n so theo CSC voi khoang cach d, xuat phat tu m
void dayCSC(int n, int d, int m){
    for(int i=0;i<n;i++)
    {
        printf("%d ",m+i*d);
    }
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
    daoNguoc(str);
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