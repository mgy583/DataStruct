#include "DFS.h"
#include <stdbool.h>
#include <stdio.h>
#include "../../../3.stack/stack_array.h"

#define MAX_SIZE 100
bool visited[MAX_SIZE] = {false}; // 访问标志数组

// 递归思路
void DFS(Graph *g, int v) {
    if (visited[v]) 
        return;
    visited[v] = true;
    printf("%d ", v+1);
    for (AdjNode *p = g->array[v]; p ; p = p->next) {
        DFS(g, p->vertex);
    }
}

// 显示栈
void DFS_stack(Graph *g, int v) {
    bool visited[MAX_SIZE] = {false};
    StackNode stack;
    initStack(&stack);

    push(&stack, v);

    while (!isEmpty(&stack)) {
        int n;
        pop(&stack, &n);
        if (visited[n]) 
            continue;
        visited[n] = true;
        printf("%d ", n+1);
        for (AdjNode *p = g->array[n]; p ; p = p->next)
        {
            if (!visited[p->vertex]) {
                push(&stack, p->vertex);
            }
        }
        
    }
}

int main() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph = CreateGraph(8); // 创建一个有5个顶点的图
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 1, 4);
    AddEdge(graph, 2, 5);
    AddEdge(graph, 2, 6);
    AddEdge(graph, 3, 7);
    AddEdge(graph, 4, 7);
    AddEdge(graph, 5, 6);
    PrintGraph(graph);

    int start_vertex = 0; // 从顶点0开始BFS
    DFS(graph, start_vertex);
    printf("\n");
    DFS_stack(graph, start_vertex);

    // 释放图的内存
    free(graph);
    return 0;
}