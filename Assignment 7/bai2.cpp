#include<iostream>
#include <stack>
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
    if (T == NULL) return;
    stack<Node*> stk;
    stk.push(T);
    while (!stk.empty()) {
        Node* node = stk.top();
        stk.pop();
        cout << node->data << " ";
        if (node->RP != NULL) stk.push(node->RP);
        if (node->LP != NULL) stk.push(node->LP);
    }
}
void inOrderTravelsal(BinaryTree T){
    stack<Node*> stk;
    Node* current = T;
    while (current != NULL || !stk.empty()) {
        while (current != NULL) {
            stk.push(current);
            current = current->LP;
        }
        current = stk.top();
        stk.pop();
        cout << current->data << " ";
        current = current->RP;
    }
}
void postOrderTravelsal(BinaryTree T){
    if (T == NULL) return;
    stack<Node*> stk1, stk2;
    stk1.push(T);
    while (!stk1.empty()) {
        Node* node = stk1.top();
        stk1.pop();
        stk2.push(node);
        if (node->LP != NULL) stk1.push(node->LP);
        if (node->RP != NULL) stk1.push(node->RP);
    }
    while (!stk2.empty()) {
        cout << stk2.top()->data << " ";
        stk2.pop();
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
    if (T == NULL) return 0;
    int totalSum = 0;
    stack<Node*> stk;
    stk.push(T);
    while (!stk.empty()) {
        Node* node = stk.top();
        stk.pop();
        totalSum += node->data;

        if (node->RP != NULL) stk.push(node->RP);
        if (node->LP != NULL) stk.push(node->LP);
    }
    return totalSum;
}
int highOfTree(BinaryTree T){
    if (T == NULL) return 0;
    int height = 0;
    stack<pair<Node*, int>> stk;
    stk.push({T, 1});
    while (!stk.empty()) {
        auto [node, level] = stk.top();
        stk.pop();
        height = max(height, level);
        if (node->LP != NULL) stk.push({node->LP, level + 1});
        if (node->RP != NULL) stk.push({node->RP, level + 1});
    }
    return height;
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