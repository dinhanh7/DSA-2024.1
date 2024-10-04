#include <iostream>
using namespace std;

typedef struct Node {
    int info;               
    struct Node* next;      
} Node;
 
typedef Node* Pnode;
typedef Node* LinkedList;
 
 //Tao danh sach rong
void createList(LinkedList* H) {
    *H = NULL;
}
 
 //Kiem tra danh sach rong
int isEmpty(LinkedList H) {
    return (H == NULL);
}
 //Bo sung phan tu K vao dau danh sach
void insertBegin(LinkedList* H, int K) {
	Pnode Q = new Node;
	Q->info = K;
	if (*H == NULL) {
		Q->next = NULL;
		*H = Q;
	}
	else {
		Q->next = *H;
		*H = Q;
	}
}
//Tim kiem phan tu co gia tri bang K
Pnode searchNode(LinkedList* H, int K) {
	Pnode P = *H;
	while (P != 0) {
		if (P->info == K)
			return P;
		else P = P->next;
	}
	return 0;
}
 
//Bo sung phan tu K vao sau phan tu co gia tri bang X
void insertAfter(LinkedList* H, int K, int X){
    Pnode P=new Node;
    P->info=K;
    Pnode chay=*H;
    while(chay != NULL)
    {
        if (chay->info == X){
            P->next = chay->next;
            chay->next=P;
            return;
        }
        chay=chay->next;
    }
}

//Bo sung phan tu K vao sau phan tu co gia tri bang X
void insertBefore(LinkedList* H, int K, int X){
    if (*H == NULL) return;

    Pnode P = new Node;
    P->info = K;

    if ((*H)->info == X) {
        P->next = *H;
        *H = P;
        return;
    }

    Pnode chay = *H;
    Pnode prev = NULL;

    while (chay != NULL) {
        if (chay->info == X) {
            P->next = chay;
            prev->next = P;
            return;
        }
        prev = chay;
        chay = chay->next;
    }
}

//Xoa phan tu o dau danh sach
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

//Xoa phan tu duoc tro boi con tro P
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

//Xoa cac phan tu co gia tri bang K
void deleteNodeK(LinkedList* H, int K){
    if (*H==NULL) return;
    Pnode P=*H;
    Pnode prev=NULL;
    while(P != NULL){
        if(P->info == K){
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

//Xoa tat ca cac phan tu trong danh sach
void deleteAllNode(LinkedList* H){
    Pnode P= *H;
    Pnode nextNode=NULL;

    while(P != NULL)
    {
        nextNode=P->next;
        delete P;
        P=nextNode;
    }
    *H=NULL;
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

//Tinh gia tri trung binh cua danh sach
double average(LinkedList H)
{
    Pnode P= H;
    int count=sizeOf(H);    
    if (count==0) return 0.0;
    int sum=0;
    while(P != NULL){
        sum+=P->info;
        P=P->next;
    }
    return (double) sum/count;
}

//Hien thi du lieu cua danh sach ra man hinh
void printList(LinkedList H)
{
    Pnode P=H;
    if(H==NULL) {
        cout<<"Danh sach trong"<<endl;
        return;
    }
    while(P != NULL){
        cout<<P->info<<"->";
        P=P->next;
    }
    cout<<"NULL\n";
}

int main() {
    LinkedList H;   
    createList(&H);  

    int choice, value, pos;
    do {
        cout << "\nMenu:";
        cout << "\n1. Them phan tu vao dau danh sach";
        cout << "\n2. Them phan tu vao sau mot gia tri";
        cout << "\n3. Them phan tu vao truoc mot gia tri";
        cout << "\n4. Xoa phan tu dau tien";
        cout << "\n5. Xoa phan tu co gia tri X";
        cout << "\n6. Tinh kich thuoc cua danh sach";
        cout << "\n7. Tinh gia tri trung binh";
        cout << "\n8. Xoa tat ca cac phan tu";
        cout << "\n0. Thoat";
        cout << "\nNhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri can them vao dau danh sach: ";
                cin >> value;
                insertBegin(&H, value);
                cout << "Danh sach sau khi them: ";
                printList(H);
                break;

            case 2:
                cout << "Nhap gia tri can them: ";
                cin >> value;
                cout << "Nhap gia tri X de them sau no: ";
                cin >> pos;
                insertAfter(&H, value, pos);
                cout << "Danh sach sau khi them: ";
                printList(H);
                break;

            case 3:
                cout << "Nhap gia tri can them: ";
                cin >> value;
                cout << "Nhap gia tri X de them truoc no: ";
                cin >> pos;
                insertBefore(&H, value, pos);
                cout << "Danh sach sau khi them: ";
                printList(H);
                break;

            case 4:
                deleteFirst(&H);
                cout << "Danh sach sau khi xoa phan tu dau tien: ";
                printList(H);
                break;

            case 5:
                cout << "Nhap gia tri X can xoa: ";
                cin >> pos;
                deleteNodeK(&H, pos);
                cout << "Danh sach sau khi xoa phan tu co gia tri " << pos << ": ";
                printList(H);
                break;

            case 6:
                cout << "So luong phan tu trong danh sach: " << sizeOf(H) << endl;
                break;

            case 7:
                cout << "Gia tri trung binh cua danh sach: " << average(H) << endl;
                break;

            case 8:
                deleteAllNode(&H);
                cout << "Danh sach sau khi xoa tat ca cac phan tu: ";
                printList(H);
                break;

            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;

            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 0);

    return 0;
}
