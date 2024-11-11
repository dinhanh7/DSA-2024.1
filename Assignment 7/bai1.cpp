#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* LP,*RP;
};
typedef Node* BinaryTree;
void init(BinaryTree& T){
    T=NULL;
}
Node* createNode(int data){
    Node* NewNode=new Node;
    NewNode->data=data;
    NewNode->LP=NULL;
    NewNode->RP=NULL;
    return NewNode;
}
void preOrderTravelsal(BinaryTree T){
    if(T==NULL) return;
    else{
        cout<<T->data<<" ";
        preOrderTravelsal(T->LP);
        preOrderTravelsal(T->RP);
    }
}
void inOrderTravelsal(BinaryTree T){
    if(T==NULL) return;
    else{
        inOrderTravelsal(T->LP);
        cout<<T->data<<" ";
        inOrderTravelsal(T->RP);
    }
}
void postOrderTravelsal(BinaryTree T){
    if(T==NULL) return;
    else{
        postOrderTravelsal(T->LP);
        postOrderTravelsal(T->RP);
        cout<<T->data<<" ";
    }
}
void insertBinaryTree(BinaryTree& T,int * data,int n,int i =0){
    if (i < n) {
        T = createNode(data[i]);
        insertBinaryTree(T->LP, data, n, 2 * i + 1);
        insertBinaryTree(T->RP, data, n, 2 * i + 2);
    }
}

int sum(BinaryTree T){
    if(T==NULL) return 0;
    else{
        return T->data+sum(T->LP)+sum(T->RP);
    }
}
int highOfTree(BinaryTree T){
    if(T==NULL) return 0;
    else{
        int trai=highOfTree(T->LP);
        int phai=highOfTree(T->RP);
        if(trai>phai) return trai+1;
        else return phai+1;
    }
}
int main(){
    int array[7]={1,2,3,4,5,6,7};
    BinaryTree T;
    init(T);
    insertBinaryTree(T,array,7);
    cout<<endl<<"duyet tu dau: ";
    preOrderTravelsal(T);
    cout<<endl<<"duyet tu giua: ";
    inOrderTravelsal(T);
    cout<<endl<<"duyet tu cuoi: ";
    postOrderTravelsal(T);
    cout<<"\n"<<sum(T)<<endl;
    cout<<highOfTree(T);
}