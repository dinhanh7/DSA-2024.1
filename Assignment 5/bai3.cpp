#include<stdio.h>
#include<string.h>
typedef struct SubjectClassNode {
    long subjectClassID;
    char subjectID[10];
    int semester;
    float processWeight;
    float finalWeight;
    float processScore;
    float finalScore;
    float subjectScore;
    struct SubjectClassNode* next;
} SubjectClassNode;
typedef struct SubjectClassNode * LopHoc;

typedef struct StudentNode {
    long studentID;
    char name[100];
    char classID[20];
    LopHoc subjectClasses;
    struct StudentNode* next;
} StudentNode;

typedef struct StudentNode* SinhVien;

//ham tao mot phan tu lop hoc phan moi
LopHoc createSubjectClassNode(long maLop, char maHP[], int kyHoc, 
float trongSoQT, float trongSoCK,float diemQT, float diemCK){
    LopHoc monHoc= new SubjectClassNode;
    monHoc->subjectClassID=maLop;
    strcpy(monHoc->subjectID,maHP);
    monHoc->semester=kyHoc;
    monHoc->processWeight=trongSoQT;
    monHoc->finalWeight=trongSoCK;
    monHoc->processScore=diemQT;
    monHoc->finalScore=diemCK;
    monHoc->subjectScore=trongSoQT*diemQT+trongSoCK*diemCK;
    monHoc->next=NULL;
    return monHoc;
}

//ham tao mot phan tu sinh vien moi
SinhVien createStudent(long mssv, char ten[], char lopSV[]){
    SinhVien sv=new StudentNode;
    sv->studentID=mssv;
    strcpy(sv->name,ten);
    strcpy(sv->classID,lopSV);
    sv->subjectClasses=NULL;
    sv->next=NULL;
    return sv;
}

//ham them mot lop hoc phan vao ds hoc phan cua sv (them vao cuoi)
void addSubjectClassNode(SinhVien& sv, LopHoc lop){
    if(sv->subjectClasses==NULL){
        sv->subjectClasses=lop; }
    else{
        LopHoc temp= sv->subjectClasses;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=lop;
    }
    lop->next=NULL;
}


void printSubjectClasses(LopHoc lop) {
    LopHoc temp = lop;
    while (temp != NULL) {
        printf("Ma lop: %ld, Ma hoc phan: %s, Ky hoc: %d\n", temp->subjectClassID, temp->subjectID, temp->semester);
        printf("Trong so QT: %.2f, Trong so CK: %.2f\n", temp->processWeight, temp->finalWeight);
        printf("Diem QT: %.2f, Diem CK: %.2f, Diem hoc phan: %.2f\n", temp->processScore, temp->finalScore, temp->subjectScore);
        temp = temp->next;
        printf("\n");
    }
    
}

// Hàm in thông tin của sinh viên
void printStudent(SinhVien sv) {
    printf("Ma so sinh vien: %ld\n", sv->studentID);
    printf("Ten sinh vien: %s\n", sv->name);
    printf("Lop sinh vien: %s\n", sv->classID);
    printf("Danh sach cac lop hoc phan:\n");
    printf("\n");
    printSubjectClasses(sv->subjectClasses);
}

// Hàm main để kiểm tra chức năng
int main() {
    // Tạo sinh viên mới
    SinhVien sv1 = createStudent(123456, "Nguyen Van A", "CTK44");

    // Tạo các lớp học phần mới
    LopHoc monHoc1 = createSubjectClassNode(153628, "MI1111", 1, 0.4, 0.6, 8.0, 7.5);
    LopHoc monHoc2 = createSubjectClassNode(154586, "MI1141", 2, 0.3, 0.7, 7.0, 6.5);
    
    addSubjectClassNode(sv1, monHoc1);
    addSubjectClassNode(sv1, monHoc2);


    printStudent(sv1);

    return 0;
}