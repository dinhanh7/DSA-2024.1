#include<stdio.h>
#include<stdbool.h>

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
//sap xep chon(selection sort)
void selection_sort(int arr[], int n)
{
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])min=j;}
        if(min != i){
            swap(&arr[min],&arr[i]);
        }
    }
}

//sap xep chen(insert sort)
void insert_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && temp<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

//sap xep noi bot(bubble sort)
void bubble_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(arr[j]<arr[j-1]){
                swap(&arr[j],&arr[j-1]);
            }
        }
    }
}

//sap xep noi bot cai tien(improved bubble sort)
void improved_bubble_sort(int arr[], int n){
    int i=0;
    bool sorted=false;
    while(!sorted && i<n-1){
        sorted=true;
        for(int j=n-1;j>i;j--){
            if(arr[j]<arr[j-1]){
                swap(&arr[j],&arr[j-1]);
                sorted=false;
            }
        }
        i++;
    }
}

//sap xep nhanh(quick sort)
int partition(int arr[], int first, int last){
    int pivot=arr[first];
    int i=first+1;
    int j=last;
    while(i<=j){
        while(i<=j && arr[i] <= pivot) i++;
        while(i<=j && arr[j] > pivot) j--;
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[first],&arr[j]);
    return j;
}

void quick_sort(int arr[],int first, int last){
    if(first<last){
        int j=partition(arr,first,last);
        quick_sort(arr,first,j-1);
        quick_sort(arr,j+1,last);
    }
}

//sap xep vun dong(heap sort)

void heapify(int arr[],int n, int i){
    int max=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left < n && arr[left]>arr[max]) max=left;
    if(right < n && arr[right]>arr[max]) max=right;
    if(max != i){
        swap(&arr[max], &arr[i]);
        heapify(arr,n,max);
    }
}
void heap_sort(int arr[], int n){
    for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
    for(int i=n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

//sap xep tron(merge sort)
void merge_arrays(int arr[], int first, int mid, int last) {
    int i = first, j = mid + 1;
    while(i<j && j<=last){
        if(arr[i]<arr[j]) i++;
        else{
            int temp=arr[j];
            for(int k=j-1; k>=i;k--) arr[k+1]=arr[k];
            arr[i]=temp;
            i++;
            j++;
        }
    } 
}

void merge(int arr[], int first, int last){
    if(first>=last)return;
    int mid=(first+last)/2;
    merge(arr,first,mid);
    merge(arr,mid+1,last);
    merge_arrays(arr,first,mid,last);
}
void merge_sort(int arr[], int n){
    if(n<2)return;
    merge(arr,0,n-1);
}
//tim kiem nhi phan(binary search)
int binary_search(int arr[],int n, int x){
    int first=0, last=n-1;
    while(first <= last){
        int m=(first+last)/2;
        if(arr[m]==x) return m;
        if(arr[m]<x) first=m+1;
        if(arr[m]>x) last=m-1;
    }
    return -1;
}

int main() {
    int arr[] = {58, 22, 76, 11, 18, 54, 7, 9, 21, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang ban dau:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    printf("Sap xep bang selection sort:\n");
    selection_sort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    int arr2[] = {58, 22, 76, 11, 18, 54, 7, 9, 21, 8};
    printf("Sap xep bang insert sort:\n");
    insert_sort(arr2, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr2[i]);
    printf("\n\n");

    int arr3[] = {58, 22, 76, 11, 18, 54, 7, 9, 21, 8};
    printf("Sap xep bang bubble sort:\n");
    bubble_sort(arr3, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr3[i]);
    printf("\n\n");

    int arr4[] = {58, 22, 76, 11, 18, 54, 7, 9, 21, 8};
    printf("Sap xep bang improved bubble sort:\n");
    improved_bubble_sort(arr4, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr4[i]);
    printf("\n\n");

    int arr5[] = {58, 22, 76, 11, 18, 54, 7, 9, 21, 8};
    printf("Sap xep bang quick sort:\n");
    quick_sort(arr5, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr5[i]);
    printf("\n\n");

    int arr6[] = {58, 22, 76, 11, 18, 54, 7, 9, 21, 8};
    printf("Sap xep bang heap sort:\n");
    heap_sort(arr6, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr6[i]);
    printf("\n\n");

    int arr7[] =  {58, 22, 76, 11, 18, 54, 7, 9, 21, 8};
    printf("Sap xep bang merge sort:\n");
    merge_sort(arr7,n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr7[i]);
    printf("\n\n");

    printf("Tim kiem nhi phan voi gia tri 22:\n");
    int result = binary_search(arr7, n, 22);
    if (result != -1)
        printf("Tim thay 22 tai vi tri %d\n", result);
    else
        printf("Khong tim thay 22 trong mang\n");

    return 0;
}