#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

// Khai bao stack cho bieu thuc (luu tru cac toan tu)
typedef struct {
    int dinh;
    char phanTu[MAX];
} NganXep;

// Khai bao stack cho gia tri (luu tru cac toan hang)
typedef struct {
    int dinh;
    double phanTu[MAX];
} NganXepGiaTri;

// Khoi tao ngan xep cho bieu thuc
void khoiTaoNganXep(NganXep* s) {
    s->dinh = -1;
}

// Khoi tao ngan xep cho gia tri
void khoiTaoNganXepGiaTri(NganXepGiaTri* s) {
    s->dinh = -1;
}

// Kiem tra ngan xep rong
int nganXepRong(NganXep* s) {
    return (s->dinh == -1);
}

// Kiem tra ngan xep day
int nganXepDay(NganXep* s) {
    return (s->dinh == MAX - 1);
}

// Them phan tu vao ngan xep
void dayNganXep(NganXep* s, char giaTri) {
    if (!nganXepDay(s)) {
        s->phanTu[++(s->dinh)] = giaTri;
    }
}

// Lay phan tu khoi ngan xep
char layNganXep(NganXep* s) {
    if (!nganXepRong(s)) {
        return s->phanTu[(s->dinh)--];
    }
    return -1;
}

// Tra ve phan tu tren cung ngan xep
char xemDinhNganXep(NganXep* s) {
    if (!nganXepRong(s)) {
        return s->phanTu[s->dinh];
    }
    return -1;
}

// Them phan tu vao ngan xep gia tri
void dayNganXepGiaTri(NganXepGiaTri* s, double giaTri) {
    if (s->dinh < MAX - 1) {
        s->phanTu[++(s->dinh)] = giaTri;
    }
}

// Lay phan tu khoi ngan xep gia tri
double layNganXepGiaTri(NganXepGiaTri* s) {
    if (s->dinh != -1) {
        return s->phanTu[(s->dinh)--];
    }
    return -1;
}

// Ham kiem tra toan tu
int laToanTu(char kyTu) {
    return (kyTu == '+' || kyTu == '-' || kyTu == '*' || kyTu == '/' || kyTu == '^');
}

// Ham lay do uu tien cua toan tu
int doUuTien(char toanTu) {
    switch (toanTu) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Ham so sanh do uu tien
int soSanhUuTien(char toanTu1, char toanTu2) {
    int doUuTien1 = doUuTien(toanTu1);
    int doUuTien2 = doUuTien(toanTu2);
    if (doUuTien1 == doUuTien2 && toanTu1 == '^') {
        return 0;
    }
    return doUuTien1 - doUuTien2;
}

// Ham chuyen doi bieu thuc trung to sang hau to
void trungToSangHauTo(char trungTo[], char hauTo[]) {
    NganXep nganXep;
    khoiTaoNganXep(&nganXep);
    int k = 0;
    for (int i = 0; i < strlen(trungTo); i++) {
        char kyTu = trungTo[i];
        if (kyTu >= '0' && kyTu <= '9') { // Kiem tra chu so
            hauTo[k++] = kyTu;
        } else if (kyTu == '(') {
            dayNganXep(&nganXep, kyTu);
        } else if (kyTu == ')') {
            while (!nganXepRong(&nganXep) && xemDinhNganXep(&nganXep) != '(') {
                hauTo[k++] = layNganXep(&nganXep);
            }
            layNganXep(&nganXep); // Loai bo dau ngoac '('
        } else if (laToanTu(kyTu)) {
            while (!nganXepRong(&nganXep) && soSanhUuTien(xemDinhNganXep(&nganXep), kyTu) >= 0) {
                hauTo[k++] = layNganXep(&nganXep);
            }
            dayNganXep(&nganXep, kyTu);
        }
    }
    while (!nganXepRong(&nganXep)) {
        hauTo[k++] = layNganXep(&nganXep);
    }
    hauTo[k] = '\0'; // Ket thuc chuoi hau to
}

// Ham tinh toan bieu thuc hau to
double tinhHauTo(char hauTo[]) {
    NganXepGiaTri nganXepGiaTri;
    khoiTaoNganXepGiaTri(&nganXepGiaTri);

    for (int i = 0; i < strlen(hauTo); i++) {
        char kyTu = hauTo[i];
        if (kyTu >= '0' && kyTu <= '9') { // Neu la so
            dayNganXepGiaTri(&nganXepGiaTri, kyTu - '0'); // Chuyen ky tu thanh gia tri so
        } else if (laToanTu(kyTu)) {
            double giaTri2 = layNganXepGiaTri(&nganXepGiaTri);
            double giaTri1 = layNganXepGiaTri(&nganXepGiaTri);
            double ketQua;
            switch (kyTu) {
                case '+':
                    ketQua = giaTri1 + giaTri2;
                    break;
                case '-':
                    ketQua = giaTri1 - giaTri2;
                    break;
                case '*':
                    ketQua = giaTri1 * giaTri2;
                    break;
                case '/':
                    ketQua = giaTri1 / giaTri2;
                    break;
                case '^':
                    ketQua = pow(giaTri1, giaTri2);
                    break;
            }
            dayNganXepGiaTri(&nganXepGiaTri, ketQua);
        }
    }

    return layNganXepGiaTri(&nganXepGiaTri);
}s

int main() {
    char trungTo[MAX], hauTo[MAX];

    // Nhap bieu thuc trung to tu ban phim
    printf("Nhap bieu thuc trung to: ");
    gets(trungTo); // Khong an toan, nhung su dung theo yeu cau

    // Chuyen doi bieu thuc trung to sang hau to
    trungToSangHauTo(trungTo, hauTo);

    // Hien thi bieu thuc hau to
    printf("Bieu thuc hau to: %s\n", hauTo);

    // Tinh toan gia tri cua bieu thuc hau to
    double ketQua = tinhHauTo(hauTo);
    printf("Ket qua: %.2f\n", ketQua);

    return 0;
}

