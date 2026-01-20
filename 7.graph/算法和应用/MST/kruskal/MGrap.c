#include "MGrap.h"
#include <stdio.h>

int adj_matrix[MAX_VERTICES][MAX_VERTICES];

void init_adj_matrix(int vertices) {
  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      adj_matrix[i][j] = 0;
    }
  }
}
void add_edge(int start, int end, int weight) {
  adj_matrix[start][end] = weight;
  adj_matrix[end][start] = weight;
}

void print_graph(int vertices) {
  for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
      printf("%d ", adj_matrix[i][j]);
    }
    printf("\n");
  }
}
