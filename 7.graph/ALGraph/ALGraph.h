#ifndef ALGRAPH_h
#include <stdlib.h>

// 邻接表
typedef struct AdjNode {
  int vertex;          // 顶点编号
  struct AdjNode *next; // 指向下一个邻接点
} AdjNode;

// 图结构
typedef struct Graph {
  int vnum;                 // 顶点数
  struct AdjNode **array; // 邻接表数组
} Graph;

Graph *CreateGraph(int vnum);

void AddEdge(Graph *graph, int src, int dest);

void PrintGraph(Graph *graph);

#endif // !ALGRAPH_h