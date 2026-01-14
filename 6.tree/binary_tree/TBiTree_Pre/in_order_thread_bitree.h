#ifndef THREAD_TREE_H

#define Nil 0x3f3f3f3f
typedef int ElemType;
typedef struct BiNode {
  ElemType data;
  struct BiNode *lchild, *rchild;
  int ltag, rtag;
} BiNode, *BiTree;

void init_bitree(BiTree *bt);

void destory(BiTree bt);

BiTree create_manual_pre(ElemType *arr, int *idx);

void in_order(BiTree bt);

void in_thread(BiTree bt);

void in_threading(BiTree bt);

void in_order_thread(BiTree bt);

#endif // !THREAD_TREE_H
