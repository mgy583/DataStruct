#include "tree.h"
#include <stdio.h>

void init_tree(PTTree *T) { T->n = 0; }

int root(PTTree T) {
  int res = -1;
  for (int i = 0; i < T.n; i++) {
    if (T.node->parent == 0) {
      res = i;
    }
  }
  return res;
}

int parent(PTTree T, int i) { return T.node[i].parent; }

int child(PTTree T, int i, int k) {
  int cnt = -1;
  for (int pos = 0; pos < T.n; ++pos) {
    if (T.node[pos].parent == i) {
      if (cnt == k)
        return pos;
      ++cnt;
    }
  }
  return -1;
}

int insert_root(PTTree *T, int data) {
  PTNode root = {data, -1};
  if (T->n == 0) {
    T->node[0] = root;
    T->n++;
    return 1;
  }
  return -1;
}

int insert_child(PTTree *T, int parent_x, int k, int data) {
  if (T->n == MAXSIZE)
    return -1;

  if (parent_x < 0 || parent_x >= T->n)
    return -1;

  int child_cnt = 0;
  for (int j = 0; j < T->n; ++j) {
    if (T->node[j].parent == parent_x) {
      ++child_cnt;
    }
  }

  if (k < 0 || k > child_cnt)
    return -1;

  int new_idx = T->n;
  T->node[new_idx].data = data;
  T->node[new_idx].parent = parent_x;

  if (k < child_cnt) {
    int cnt = 0;
    for (int j = 0; j < T->n; ++j) {
      if (T->node[j].parent == parent_x) {
        if (cnt >= k)
          T->node[j].parent = -2;
        ++cnt;
      }
    }

    for (int j = 0; j < T->n; ++j) {
      if (T->node[j].parent == -2)
        T->node[j].parent = parent_x + 1;
    }
  }

  ++T->n;
  return new_idx;
}

void level_order(const PTTree *T) {
  if (T->n == 0)
    return;

  int q[MAXSIZE], head = 0, tail = 0;
  q[tail++] = 0;

  while (head < tail) {
    int i = q[head++];
    printf("idx=%d  data=%d  parent=%d\n", i, T->node[i].data,
           T->node[i].parent);

    int k = 0, c;
    while ((c = child(*T, i, k)) != -1) {
      q[tail++] = c;
      ++k;
    }
  }
}
