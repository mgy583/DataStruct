#include "ALGraph.h"
#include <stdlib.h>
#include <stdio.h>

Graph *CreateGraph(int vnum) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->vnum = vnum;
  graph->array = (AdjNode **)malloc(vnum * sizeof(AdjNode *));
  for (int i = 0; i < vnum ; i++) {
    graph->array[i] = NULL;
  }
  return graph;
}

// 有向图加入边
void AddEdge(Graph *graph, int src, int dest) {
  AdjNode *newNode = (AdjNode *)malloc(sizeof(AdjNode));
  newNode->vertex = dest;
  newNode->next = graph->array[src];
  graph->array[src] = newNode;
}

void PrintGraph(Graph *graph) {
  for (int v = 0; v < graph->vnum; v++) {
    printf("%d:", v);
    for (AdjNode *p = graph->array[v]; p != NULL; p = p->next)
      printf(" -> %d", p->vertex);
  printf("\n");
  }
}

void freeGraph(Graph *graph) {
  for (int v = 0; v < graph->vnum; ++v)
  {
    AdjNode *p = graph->array[v];
    while(p) {
      AdjNode *temp = p;
      p = p->next;
      free(temp);
    }
  }
  free(graph->array);
  free(graph);  
}

