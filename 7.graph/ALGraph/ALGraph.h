#ifndef ALGRAPH_h
#include <stdlib.h>

// 链表节点
typedef struct Node {
  int dest;          // 顶点编号
  struct Node *next; // 指向下一个邻接点
} Node;

// 邻接表
typedef struct AdjList {
  struct Node *head; // 链表头
} AdjList;

// 图结构
typedef struct Graph {
  int V;                 // 顶点数
  struct AdjList *array; // 邻接表数组
} Graph;

Node *new_node(int dest);

Graph *create_graph(int V);

void add_edge(Graph *graph, int src, int dest);
#endif // !ALGRAPH_h
