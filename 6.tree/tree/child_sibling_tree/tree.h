#ifndef CSTREE_H

typedef struct CSNode {
  int data;
  struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;

void init_tree(CSTree *cst);

void f

#endif // !CSTREE_H
