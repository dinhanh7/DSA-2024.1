#include<stdio.h>
#include "queue.c"
#include<stdbool.h>
#define NUM 7

char value[NUM] = { '1', '2', '3', '4', '5', '6', '7' };

int graph[NUM][NUM]={
        {0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 1},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };

bool visitedDFS[NUM];
bool visitedBFS[NUM];


void DFS(int graph[NUM][NUM], int vertex){
    visitedDFS[vertex]=true;
    printf("%c\n",value[vertex]);
    for (int i = 0; i < NUM; i++) {
        if (graph[vertex][i] == 1 && !visitedDFS[i]) {
            DFS(graph, i);
        }
    }
}
void BFS(int graph[NUM][NUM], int vertex) {
    struct Queue Q;
    initialize(&Q);

    visitedBFS[vertex] = true;
    enQueue(&Q,vertex);
    printf("%c\n", value[vertex]);
    while (!isQueueEmpty(&Q)) {
        int x = deQueue(&Q);
        for (int i = 0; i < NUM; i++) {
            if (graph[x][i] == 1 && !visitedBFS[i]) {
                enQueue(&Q,i);
                printf("%c\n", value[i]);
                visitedBFS[i] = true;
            }
        }
    }
}
int main() {
    int n;
    printf("Bat dau duyet do thi tu: ");
    scanf("%d",&n);
    printf("DFS traversal starting from vertex %d:\n",n+1);
    DFS(graph,n);
    printf("BFS traversal starting from vertex %d:\n",n+1);
    BFS(graph,n);
}