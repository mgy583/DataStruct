#include "ALGraph.h"

int main() {
  int V = 5;
  Graph *graph = CreateGraph(V);
  AddEdge(graph, 0, 1);
  AddEdge(graph, 0, 4);
  AddEdge(graph, 1, 2);
  AddEdge(graph, 1, 3);
  AddEdge(graph, 1, 4);
  AddEdge(graph, 2, 3);
  AddEdge(graph, 3, 4);

  PrintGraph(graph);

  freeGraph(graph);
  return 0;
}
