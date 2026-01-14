#ifndef BITREE_H

#include <stdio.h>
#include <stdlib.h>

#define Nil 0x3f3f3f3f

typedef int ElemType;

typedef struct BiNode {
  ElemType data;
  struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

void init_bitree(BiTree *bt);

void destory(BiTree *bt);

void pre_order(BiTree bt);

void in_order(BiTree bt);

void post_order(BiTree bt);

void level_order(BiTree bt);

BiTree create_manual_pre(ElemType *arr, int *idx);

#endif // !BITREE_H
