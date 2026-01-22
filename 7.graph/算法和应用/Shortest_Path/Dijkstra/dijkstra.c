#include "MGrap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int parent[MAX_VERTICES];

void printpath(int v) {
  if (v == 0) {
    printf("0");
    return;
  }
  printpath(parent[v]);
  printf(" -> %d", v);
}

void dijkstra(int vertice) {
  // 排除无效输入
  if (vertice <= 0) {
    printf("Invalid number of vertices\n");
    return;
  }

  // 初始化数组
  bool visited[MAX_VERTICES] = {false};
  int dist[MAX_VERTICES];
  int parent[MAX_VERTICES];

  // 初始化距离和父节点
  for (int i = 0; i < vertice; i++) {
    dist[i] = INT_MAX;
    visited[i] = false;
  }

  dist[0] = 0;
  parent[0] = -1;

  // 遍历所有顶点
  for (int count = 0; count < vertice - 1; count++) {
    // 选择距离源点最近的未访问顶点
    int min_key = INT_MAX;
    int u = -1;

    // 找到未访问的最小距离顶点
    for (int v = 0; v < vertice; v++) {
      if (!visited[v] && dist[v] < min_key) {
        min_key = dist[v];
        u = v;
      }
    }

    // 如果找不到未访问的顶点，说明图不连通
    if (u == -1) {
      printf("Graph is not connected!\n");
      return;
    }

    // 标记顶点为已访问
    visited[u] = true;

    // 更新相邻顶点的距离
    for (int v = 0; v < vertice; v++) {
      if (adj_matrix[u][v] != 0 && !visited[v] &&
          dist[u] + adj_matrix[u][v] < dist[v]) {
        // 更新距离和父节点
        dist[v] = dist[u] + adj_matrix[u][v];
        parent[v] = u;
      }
    }
  }

  printf("shortest_path(dijkstra): \n");
  for (int i = 0; i < vertice; i++) {
    printf("to %d - %d\n", i, dist[i]);
  }
  for (int i = 1; i < vertice; i++) {
    printf("Path to %d (distance %d): ", i, dist[i]);
    printpath(i);
    putchar('\n');
  }
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

  // 运行dijkstra算法
  dijkstra(vertices);

  return 0;
}
