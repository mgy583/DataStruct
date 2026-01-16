#include "ALGraph.h"
#include <stdlib.h>

Node *new_node(int dest) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->dest = dest;
  node->next = NULL;
  return node;
}

Graph *create_graph(int V) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->V = V;

  // 创建邻接表数组
  graph->array = (AdjList *)malloc(V * sizeof(AdjList));
  for (int i = 0; i < V; ++i)
    graph->array[i].head = NULL;

  return graph;
}

void add_edge(Graph *graph, int src, int dest) {
  Node *n1 = new_node(dest);
  n1->next = graph->array[src].head;
  graph->array[src].head = n1;

  Node *n2 = new_node(dest);
  n2->next = graph->array[dest].head;
  graph->array[dest].head = n2;
}
