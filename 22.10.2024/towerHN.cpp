#include <stdio.h>

// Ham tinh tong tu 0 den n
int tinhTong(int n) {
    if (n == 1) {
        return 1; 
    }
    return n + tinhTong(n - 1); 
}

// Ham tim so nho nhat trong mang
int timMin(int a[], int n) {
    if (n == 1) {
        return a[0]; 
    }
    int min_so_con_lai = timMin(a, n - 1); 
    return (a[n - 1] < min_so_con_lai) ? a[n - 1] : min_so_con_lai;

// Ham tim UCLN cua hai so
int UCLN(int a, int b) {
    if (b == 0) {
        return a; 
    }
    return UCLN(b, a % b); 
}

// Ham tinh tong cac chu so cua mot so
int tongChuSo(int n) {
    if (n == 0) {
        return 0; 
    }
    return (n % 10) + tongChuSo(n / 10);
}

// Ham dao nguoc chuoi ky tu
void daoNguocChuoi(char str[], int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    daoNguocChuoi(str, start + 1, end - 1);
}

// Ham tinh to hop C(n, k)
int toHop(int n, int k) {
    if (k == 0 || k == n) {
        return 1; 
    }
    return toHop(n - 1, k - 1) + toHop(n - 1, k); 
}

int main() {

    // Tinh tong tu 0 den n-1
    int n = 5;
    printf("Tong tu 0 den %d la: %d\n", n, tinhTong(n));
    
    // Tim so nho nhat trong mang
    int arr[] = {12, 3, 45, 1, 23};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("So nho nhat trong mang la: %d\n", timMin(arr, size));
    
    // Tinh UCLN cua hai so
    int a = 56, b = 98;
    printf("UCLN cua %d va %d la: %d\n", a, b, UCLN(a, b));
    
    // Tinh tong cac chu so cua mot so
    int num = 12345;
    printf("Tong cac chu so cua %d la: %d\n", num, tongChuSo(num));
    
    // Dao nguoc chuoi ky tu
    char str[] = "Hello";
    daoNguocChuoi(str, 0, 4);
    printf("Chuoi sau khi dao nguoc: %s\n", str);
    
    // Tinh to hop C(n, k)
    int k = 3;
    printf("To hop C(%d, %d) la: %d\n", n, k, toHop(n, k));

    return 0;
}
