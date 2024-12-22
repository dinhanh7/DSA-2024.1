#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include "queue.c"

#define NUM 7

typedef struct{
    int mssv;
    char name[50];
    float cpa;
    bool visited;
} Student;

int graph[NUM][NUM] = {
    {0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0}
};

Student students[NUM] = {
    {20230001, "Nguyen Viet Tuan", 3.5, false},
    {20230002, "Tran Thi Dao", 3.8, false},
    {20230003, "Le Van Chuan", 2.9, false},
    {20230004, "Pham Minh Dung", 3.2, false},
    {20230005, "Vu Minh Anh", 3.0, false},
    {20230006, "Hoang Van Phuong", 4.0, false},
    {20230007, "Nguyen Thu Lan", 3.7, false}
};

void DFS(int vertex){
    students[vertex].visited=true;
    printf("MSSV: %d, Name: %s, CPA: %.2f\n", students[vertex].mssv, students[vertex].name, students[vertex].cpa);

    for(int i=0;i<NUM;i++){
        if(graph[vertex][i]==1 && !students[i].visited){ DFS(i);}
    }
}

float averageCPA(int start){
    struct Queue Q;
    initialize(&Q);
    float sum=0;
    int count=0;

    students[start].visited = true;
    enQueue(&Q,start);

    while(!isQueueEmpty(&Q)){
        int x=deQueue(&Q);
        sum+=students[x].cpa;
        count++;

        for(int i=0;i<NUM;i++){
            if(graph[x][i]==1 && !students[i].visited){
                students[i].visited =true;
                enQueue(&Q,i);
            }
        }
    }
    return sum/count;
}

void resetVisited(){
    for(int i=0;i<NUM;i++){
        students[i].visited=false;
    }
}

int main() {
    printf("Danh sach sinh vien duyet theo DFS:\n");
    DFS(0); 
    resetVisited();

    printf("\nCPA trung binh tinh theo BFS: ");
    float avgCPA = averageCPA(0); 
    printf("%.2f\n", avgCPA);

    return 0;
}
