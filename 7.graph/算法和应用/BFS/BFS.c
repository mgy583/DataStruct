#include "BFS.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../../4.quene/cycle_quene/quene.h"

void BFS(Graph* graph, int v) {
    SqQueue Q;
    init_quene(&Q);

    bool visited[MAX_VERTEX_NUM] = {false}; // 访问标志数组
                                
    enquene(&Q, v); // 入队
    visited[v] = true; // 标记为已访问

    while (!is_empty(&Q)) {
        dequene(&Q, &v); // 出队
        // printf("Dequeued: %d\n", v);  // 打印出队的元素
        printf("%d ", v);

        for (AdjNode *p = graph->array[v]; p; p = p->next)
        {
            int w = p->vertex;
            if (!visited[w])
            {
                enquene(&Q, w);    // 入队
                visited[w] = true; // 标记为已访问
                // printf("Enqueued: %d\n", w);  // 打印入队的元素
            }
        }
    }
    printf("\n");
}

int main() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph = CreateGraph(5); // 创建一个有5个顶点的图
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 4);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 1, 4);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 4);
    PrintGraph(graph);

    int start_vertex = 0; // 从顶点0开始BFS
    BFS(graph, start_vertex);

    // 释放图的内存
    free(graph);
    return 0;
}