#include <iostream>
#include<string.h>
using namespace std;

typedef struct Node {
    long mssv;
    char name[50];
    float cpa;   
    struct Node* next;      
} Node;
 
typedef Node* Pnode;
typedef Node* LinkedList;
 
 //Tao danh sach rong
void createList(LinkedList* H) {
    *H = NULL;
}
 
 //Luu tru thong tin cua mot sinh vien
Pnode createStudentNode(long mssv, char hoten[], float CPA)
{
    Pnode temp =new Node;
    temp->mssv=mssv;
    strcpy(temp->name,hoten);
    temp->cpa=CPA;
    return temp;
}

 //Kiem tra danh sach rong
int isEmpty(LinkedList H) {
    return (H == NULL);
}

 //Bo sung mot sinh vien vao dau danh sach
void insertBegin(LinkedList* H, Node sv) {
	Pnode Q = new Node;
	Q->mssv=sv.mssv;
    strcpy(Q->name,sv.name);
    Q->cpa=sv.cpa;
	if (*H == NULL) {
		Q->next = NULL;
		*H = Q;
	}
	else {
		Q->next = *H;
		*H = Q;
	}
}

//Tim kiem sinh vien co ma so sinh vien la maso
Pnode searchNode(LinkedList* H, int maso) {
	Pnode P = *H;
	while (P != 0) {
		if (P->mssv == maso)
			return P;
		else P = P->next;
	}
	return 0;
}
 
//Bo sung mot sinh vien vao sau sinh vien co mssv la maso
void insertAfter(LinkedList* H, Node sv, int maso){
    Pnode P=new Node;
    P->mssv=sv.mssv;
    strcpy(P->name,sv.name);
    P->cpa=sv.cpa;
    Pnode chay=*H;
    while(chay != NULL)
    {
        if (chay->mssv== maso){
            P->next = chay->next;
            chay->next=P;
            return;
        }
        chay=chay->next;
    }
}

//Bo sung mot sinh vien vao truoc sinh vien co mssv la maso
void insertBefore(LinkedList* H, Node sv, int maso){
    if (*H == NULL) return;

    Pnode P = new Node;
    P->mssv=sv.mssv;
    strcpy(P->name,sv.name);
    P->cpa=sv.cpa;

    if ((*H)->mssv == maso) {
        P->next = *H;
        *H = P;
        return;
    }

    Pnode chay = *H;
    Pnode prev = NULL;

    while (chay != NULL) {
        if (chay->mssv == maso) {
            P->next = chay;
            prev->next = P;
            return;
        }
        prev = chay;
        chay = chay->next;
    }
}

//Xoa sinh vien o dau danh sach 
void deleteFirst(LinkedList* H){
    if (*H==NULL){
        return;
    }
    else{
        Pnode P=*H;
        *H=(*H)->next;
        delete P;
    }
}

//Xoa sinh vien duoc tro boi con tro P
void deleteNode(LinkedList* H, Pnode nodeDelete){
    if (*H==NULL || nodeDelete==NULL) return;
    if (*H== nodeDelete && nodeDelete->next == NULL){
        *H=NULL;
        delete nodeDelete;
        return;
    }
    else{
        Pnode chay=*H;
        while (chay->next != NULL && chay->next != nodeDelete){
            chay=chay->next;
            }
        if(chay->next==nodeDelete){
            chay->next=nodeDelete->next;
            delete nodeDelete;
        }
        }
    }

//Xoa sinh vien co mssv bang maso
void deleteNodeK(LinkedList* H, int mssv){
    if (*H==NULL) return;
    Pnode P=*H;
    Pnode prev=NULL;
    while(P != NULL){
        if(P->mssv == mssv){
            if (P==*H){
                *H=P->next;
                delete P;
                P=*H;
            }
            else{
                prev->next=P->next;
                delete P;
                P=prev->next;
            }
        }
        else{
            prev=P;
            P=P->next;
        }
    }
}

//Dem so phan tu trong danh sach
int sizeOf(LinkedList H){
    Pnode P=H;
    int count=0;
    if (H==NULL) return 0;
    while (P !=NULL){
        ++count;
        P=P->next;
    }
    return count;
}
//Hien thi du lieu cua sinh vien co CPA lon nhat
void bestCPA(LinkedList* H){
    if( *H == NULL){
        printf("Danh sach rong. \n");
        return;
    }
    Pnode sv= new Node;
    Pnode P=*H;
    float max=P->cpa;
    while(P != NULL){
        if(P->cpa >= max)
        {
            max=P->cpa;
            sv=P;
        }
        P=P->next;
    }
    printf("Sinh vien co CPA cao nhat la:\nMSSV: %ld\nHo ten: %s\nCPA: %.2f",sv->mssv,sv->name,sv->cpa);
}

int main() {
    LinkedList H;
    createList(&H);

    // Them sinh vien vao danh sach
    Node sv1 = {101, "Nguyen Van A", 3.8};
    Node sv2 = {102, "Tran Thi B", 3.5};
    Node sv3 = {103, "Le Van C", 3.9};

    insertBegin(&H, sv1);  
    insertBegin(&H, sv2);  
    insertAfter(&H, sv3, 101); 

    cout << "Danh sach sau khi chen sinh vien:\n";
    bestCPA(&H);  

    // Tim kiem sinh vien co ma so 102
    Pnode svTim = searchNode(&H, 102);
    if (svTim != NULL) {
        cout << "\nSinh vien tim thay: " << svTim->name << ", MSSV: " << svTim->mssv << ", CPA: " << svTim->cpa << endl;
    } else {
        cout << "\nKhong tim thay sinh vien co MSSV 102\n";
    }

    // Xoa sinh vien dau tien
    deleteFirst(&H);
    cout << "\nDanh sach sau khi xoa sinh vien dau:\n";
    bestCPA(&H);

    // Xoa sinh vien co MSSV la 103
    deleteNodeK(&H, 103);
    cout << "\nDanh sach sau khi xoa sinh vien co MSSV 103:\n";
    bestCPA(&H);

    // Dem so luong sinh vien trong danh sach
    cout << "\nSo luong sinh vien trong danh sach: " << sizeOf(H) << endl;

    return 0;
}