#include<iostream>
#include<string>
using namespace std;

struct Node {
    string data;
    Node* LP, * RP;
};
typedef Node* PNode;
typedef PNode BinaryTree;
typedef BinaryTree BSearchTree;

PNode createNode(string value) {
    PNode newNode = new Node;
    newNode->data = value;
    newNode->LP = newNode->RP = nullptr;
    return newNode;
}

PNode createEmptyTree() {
    return nullptr;
}

void InsertT(BSearchTree &root, string value) {
    if (root == nullptr) {
        root = createNode(value);
    } else {
        if (value.length() < root->data.length()) {
            InsertT(root->LP, value);
        } else if (value.length() > root->data.length()) {
            InsertT(root->RP, value);
        } else { 
            if (value < root->data) {
                InsertT(root->LP, value);
            } else if (value > root->data) {
                InsertT(root->RP, value);
            } else return; 
        }
    }
}

void DelNode(PNode &P) {
    PNode Q, R;
    if (P->LP == NULL) {
        Q = P;
        P = P->RP;
    } else if (P->RP == NULL) {
        Q = P;
        P = P->LP;
    } else {
        Q = P->LP;
        if (Q->RP == NULL) {
            P->data = Q->data;
            P->LP = Q->LP;
        } else {
            do {
                R = Q;
                Q = Q->RP;
            } while (Q->RP != NULL);
            P->data = Q->data;
            R->RP = Q->LP;
        }
    }
    delete Q;
}

void DeleteT(BSearchTree &root, string value) {
    if (root != NULL) {
        if (value.length() > root->data.length()) {
            DeleteT(root->RP, value);
        } else if (value.length() < root->data.length()) {
            DeleteT(root->LP, value);
        } else { 
            if (value < root->data) {
                DeleteT(root->LP, value);
            } else if (value > root->data) {
                DeleteT(root->RP, value);
            } else {
                DelNode(root);
            }
        }
    }
}

PNode SearchT(BSearchTree root, string value) {
    if (root == NULL) return NULL;
    if (root->data == value) return root;
    else if (value.length() < root->data.length()) {
        return SearchT(root->LP, value);
    } else if (value.length() > root->data.length()) {
        return SearchT(root->RP, value);
    } else { 
        if (value < root->data) {
            return SearchT(root->LP, value);
        } else if (value > root->data) {
            return SearchT(root->RP, value);
        } else return root;
    }
}

void displayTree(Node *root) {
    if (root != nullptr) {
        cout << root->data << " " << endl;
        displayTree(root->LP);
        displayTree(root->RP);
    }
}

int main() {
    string x, xoa;

    Node* root = createEmptyTree();

    InsertT(root, "apple red");
    InsertT(root, "banana yellow");
    InsertT(root, "cherry red");
    InsertT(root, "date");
    InsertT(root, "figma");
    InsertT(root, "grape pink");
    InsertT(root, "kiwi green");

    cout << "Cac chuoi tren cay la: " << endl;
    displayTree(root);
    cout << endl;

    cout << "Nhap chuoi muon tim kiem: ";
    getline(cin, x); 
    PNode find = SearchT(root, x);
    if (find != nullptr) {
        cout << "Tim thay chuoi '" << x << "' trong cay." << endl;
    } else {
        cout << "Khong tim thay chuoi '" << x << "' trong cay." << endl;
    }

    cout << "Nhap chuoi muon xoa: ";
    getline(cin, xoa);  
    DeleteT(root, xoa);
    cout << "Cay sau khi xoa '" << xoa << "':" << endl;
    displayTree(root);
    cout << endl;

    return 0;
}
