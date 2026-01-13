#ifndef TREE_C

#include <stdio.h>

#define MAXSIZE 100

typedef struct PTNode {
  int data;
  int parent;
} PTNode;

typedef struct PTTree {
  PTNode node[MAXSIZE];
  int n;
} PTTree;

void init_tree(PTTree *T);

int root(PTTree T);

int parent(PTTree T, int i);

int child(PTTree T, int i, int k);

int insert_root(PTTree *T, int data);

int insert_child(PTTree *T, int parent_x, int k, int data);

int delete_sub_tree(PTTree *T, int i);

void level_order(const PTTree *T);
#endif // !TREE_C
