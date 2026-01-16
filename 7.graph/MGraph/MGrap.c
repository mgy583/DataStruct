#include "MGrap.h"
#include <stdio.h>
#include <stdlib.h>

int adj_matrix[MAX_VERTICES][MAX_VERTICES];

void init_adj_matrix(int vertices) {
  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      adj_matrix[i][j] = 0;
    }
  }
}
void add_edge(int start, int end) {
  adj_matrix[start][end] = 1;
  adj_matrix[end][start] = 1;
}

void print_graph(int vertices) {
  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      printf("%d ", adj_matrix[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int vertices = 5;
  init_adj_matrix(vertices);
  add_edge(0, 1);
  add_edge(0, 3);
  add_edge(1, 2);
  add_edge(1, 4);
  add_edge(2, 3);
  add_edge(2, 4);

  print_graph(vertices);

  return EXIT_SUCCESS;
}
