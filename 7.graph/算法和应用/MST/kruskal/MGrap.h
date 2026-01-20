#ifndef MGRAP_H
#define MGRAP_H

#define MAX_VERTICES 100

extern int adj_matrix[MAX_VERTICES][MAX_VERTICES];

struct Edge {
  int start;
  int end;
  int weight;
};

void init_adj_matrix(int vertices);

void add_edge(int start, int end, int weight);

void print_graph(int vertices);

#endif // !MGRAP_H
