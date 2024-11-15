#include<iostream>
using namespace std;

struct Node{
    int key;
    Node* LP,* RP;
};
typedef Node* PNode;
typedef PNode BinaryTree;
typedef BinaryTree BSearchTree;


PNode createNode(int value) {
    PNode newNode = new Node; 
    newNode->key = value;
    newNode->LP = newNode->RP = nullptr;
    return newNode;
}
PNode createEmptyTree(){
    return nullptr;
}
void InsertT(BSearchTree & root, int value){
    if(root==nullptr){
        root=createNode(value);
    }
    else{
        if(value < root->key) InsertT(root->LP,value);
        else if(value > root->key) InsertT(root->RP,value);
        else return;
    }
}
void DelNode(PNode & P){
    PNode Q,R;
    if(P->LP == NULL){ 
        Q=P;
        P=P->RP;
    }
    else if(P->RP ==NULL){
        Q=P;
        P=P->LP;
    }
    else{
        Q=P->LP;
        if (Q->RP==NULL){
            P->key= Q->key;
            P->LP=Q->LP;
        }
        else{
            do{
                R=Q;
                Q=Q->RP;
            }
            while(Q->RP != NULL);
            P->key = Q->key;
            R->RP = Q->LP;
        }
    }
    delete Q;
}

void DeleteT(BSearchTree & root, int value){
    if(root != NULL){
        if(value > root->key) DeleteT(root->RP, value);
        else if(value < root->key) DeleteT(root->LP, value);
        else DelNode(root);
    }
}

PNode SearchT( BSearchTree root, int value){
    if(root==NULL) return NULL;
    if(root->key == value) return root;
    else if(value < root->key) return SearchT(root->LP, value);
    else return SearchT(root->RP, value);
}

void displayTree(Node *root){
    if(root != nullptr){
        cout<<root->key<<" ";
        displayTree(root->LP);
        displayTree(root->RP);
    }
}

int sumKeys(Node * root){
    if (root == nullptr) return 0;
    return root->key +sumKeys(root->LP)+sumKeys(root->RP);
}

int countNodes(Node * root){
    if (root == nullptr) return 0;
    return 1 +countNodes(root->LP) + countNodes(root->RP);
}

int main()
{
    int x, xoa;

    Node * root = createEmptyTree();
    InsertT(root,50);
    InsertT(root,30);
    InsertT(root,70);
    InsertT(root,20);
    InsertT(root,40);
    InsertT(root,60);
    InsertT(root,80);
    cout<<"Cac khoa tren cay la: ";
    displayTree(root);
    cout<<endl;

    
    cout<<"Nhap khoa muon tim kiem: ";
    cin>>x;
    PNode find= SearchT(root,x);
    if (find != nullptr) cout <<"Tim thay khoa "<<x<<endl;
    else cout<<"Khong tim thay khoa "<<x<<endl;

    cout<<"Nhap khoa muon xoa: ";
    cin>>xoa;
    DeleteT(root, xoa);
    cout << "Cay sau khi xoa "<<xoa<<" :"<<endl;
    displayTree(root);
    cout << endl;

    
    cout << "Tong cac khoa cua cay: " << sumKeys(root) << endl;

    
    cout << "So phan tu cua cay: " << countNodes(root) << endl;

    return 0;

}