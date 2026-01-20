#ifndef MGRAP_H
#define MGRAP_H

#define MAX_VERTICES 100

extern int adj_matrix[MAX_VERTICES][MAX_VERTICES];

void init_adj_matrix(int vertices);

void add_edge(int start, int end, int weight);

void print_graph(int vertices);

void prim_mst(int vertice);

#endif // !MGRAP_H
