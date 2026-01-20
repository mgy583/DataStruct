#include "MGrap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// int adj_matrix[MAX_VERTICES][MAX_VERTICES];

void prim(int vertice) {
  if (vertice <= 0) {
    printf("Invalid number of vertices\n");
    return;
  }

  bool in_mst[MAX_VERTICES] = {false};

  int key[MAX_VERTICES];

  int parent[MAX_VERTICES];

  for (int i = 0; i < vertice; i++) {
    key[i] = INT_MAX;
    in_mst[i] = false;
  }

  key[0] = 0;
  parent[0] = -1;

  for (int count = 0; count < vertice - 1; count++) {
    int min_key = INT_MAX;
    int u = -1;

    for (int v = 0; v < vertice; v++) {
      if (!in_mst[v] && key[v] < min_key) {
        min_key = key[v];
        u = v;
      }
    }

    if (u == -1) {
      printf("Graph is not connected!\n");
      return;
    }

    in_mst[u] = true;

    for (int v = 0; v < vertice; v++) {
      if (adj_matrix[u][v] != 0 && !in_mst[v] && adj_matrix[u][v] < key[v]) {
        key[v] = adj_matrix[u][v];
        parent[v] = u;
      }
    }
  }

  printf("MST(Prim): \n");
  printf("Edge \t Wight\n");

  int total_wight = 0;
  for (int i = 1; i < vertice; i++) {
    if (parent[i] != -1) {
      printf("%d - %d \t%d\n", parent[i], i, adj_matrix[i][parent[i]]);
      total_wight += adj_matrix[i][parent[i]];
    }
  }
  printf("Total weight of MST: %d\n", total_wight);
}

int main() {
  int vertices = 5;

  // 初始化图
  init_adj_matrix(vertices);

  // 添加边（无向图）
  add_edge(0, 1, 2);
  add_edge(0, 3, 6);
  add_edge(1, 2, 3);
  add_edge(1, 3, 8);
  add_edge(1, 4, 5);
  add_edge(2, 4, 7);
  add_edge(3, 4, 9);

  // 打印邻接矩阵
  printf("Adjacency Matrix:\n");
  print_graph(vertices);
  printf("\n");

  // 运行Prim算法
  prim(vertices);

  return 0;
}
