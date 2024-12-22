#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include "queue.c"

#define NUM 7 // Số lượng sinh viên

// Định nghĩa cấu trúc sinh viên
typedef struct {
    int mssv;           // Mã số sinh viên
    char name[50];      // Họ tên
    float cpa;          // CPA
    bool visited;       // Trạng thái đã duyệt
} Student;

// Ma trận kề của đồ thị
int graph[NUM][NUM] = {
    {0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0}
};

// Mảng chứa thông tin sinh viên
Student students[NUM] = {
    {1, "Nguyen Van A", 3.5, false},
    {2, "Tran Thi B", 3.8, false},
    {3, "Le Van C", 2.9, false},
    {4, "Pham Thi D", 3.2, false},
    {5, "Vu Minh E", 3.0, false},
    {6, "Hoang Van F", 4.0, false},
    {7, "Nguyen Thi G", 3.7, false}
};

// Hàm DFS
void DFS(int vertex) {
    students[vertex].visited = true;
    printf("MSSV: %d, Name: %s, CPA: %.2f\n", students[vertex].mssv, students[vertex].name, students[vertex].cpa);

    for (int i = 0; i < NUM; i++) {
        if (graph[vertex][i] == 1 && !students[i].visited) {
            DFS(i);
        }
    }
}

// Hàm tính CPA trung bình bằng BFS
float calculateAverageCPA(int start) {
    struct Queue Q;
    initialize(&Q);
    float totalCPA = 0.0;
    int count = 0;

    // Bắt đầu từ đỉnh start
    students[start].visited = true;
    enQueue(&Q, start);

    while (!isQueueEmpty(&Q)) {
        int curr = deQueue(&Q);
        totalCPA += students[curr].cpa;
        count++;

        for (int i = 0; i < NUM; i++) {
            if (graph[curr][i] == 1 && !students[i].visited) {
                students[i].visited = true;
                enQueue(&Q, i);
            }
        }
    }
    return totalCPA / count; // Trả về CPA trung bình
}

void resetVisited() {
    for (int i = 0; i < NUM; i++) {
        students[i].visited = false;
    }
}

// Hàm chính
int main() {
    printf("Danh sach sinh vien duyet theo DFS:\n");
    DFS(0); // Duyệt từ đỉnh đầu tiên
    resetVisited();

    printf("\nCPA trung bình tính theo BFS: ");
    float avgCPA = calculateAverageCPA(0); // Bắt đầu từ đỉnh 0
    printf("%.2f\n", avgCPA);

    return 0;
}
