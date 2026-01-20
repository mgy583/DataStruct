#include "MGrap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES (MAX_VERTICES * (MAX_VERTICES - 1) / 2) // 无向图最大边数

int compare_edges(const void *a, const void *b) {
  struct Edge *edge_a = (struct Edge *)a;
  struct Edge *edge_b = (struct Edge *)b;
  return edge_a->weight - edge_b->weight;
}
void kruskal(int vertice) {
  struct Edge edges[MAX_EDGES];
  int edge_count = 0;

  for (int i = 0; i < vertice; i++) {
    for (int j = i + 1; j < vertice; j++) {
      if (adj_matrix[i][j] > 0) {
        edges[edge_count++] = (struct Edge){i, j, adj_matrix[i][j]};
      }
    }
  }
  qsort(edges, edge_count, sizeof(struct Edge), compare_edges);

  bool connected[MAX_VERTICES] = {false};
  struct Edge mst[MAX_VERTICES - 1];
  int mst_count = 0;

  if (edge_count > 0) {
    mst[mst_count++] = edges[0];
    connected[edges[0].start] = true;
    connected[edges[0].end] = true;
  }

  for (int i = 1; i < edge_count && mst_count < vertice - 1; i++) {
    int u = edges[i].start;
    int v = edges[i].end;
    if (!connected[u] || !connected[v]) {
      mst[mst_count++] = edges[i];
      connected[u] = true;
      connected[v] = true;
    }
  }

  // 输出结果
  printf("Minimum Spanning Tree (Basic Kruskal):\n");
  int total_weight = 0;
  for (int i = 0; i < mst_count; i++) {
    printf("%d-%d: %d\n", mst[i].start, mst[i].end, mst[i].weight);
    total_weight += mst[i].weight;
  }
  printf("Total weight: %d\n", total_weight);
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
  kruskal(vertices);

  return 0;
}
