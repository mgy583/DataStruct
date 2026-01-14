#include "bitree.h"
#include <stdio.h>
#include <stdlib.h>

void init_bitree(BiTree *bt) { *bt = NULL; }

void destory(BiTree *bt) {
  if (!*bt)
    return;
  destory(&(*bt)->lchild);
  destory(&(*bt)->rchild);
  free(*bt);
  init_bitree(&(*bt));
}

void pre_order(BiTree bt) {
  if (!bt)
    return;
  printf("%d ", bt->data);
  pre_order(bt->lchild);
  pre_order(bt->rchild);
}

void in_order(BiTree bt) {
  if (!bt)
    return;
  in_order(bt->lchild);
  printf("%d ", bt->data);
  in_order(bt->rchild);
}

void post_order(BiTree bt) {
  if (!bt)
    return;
  post_order(bt->lchild);
  post_order(bt->rchild);
  printf("%d ", bt->data);
}

BiTree create_manual_pre(ElemType *arr, int *idx) {
  ElemType val = arr[(*idx)++];
  if (val == Nil)
    return NULL; // 空子树
  BiTree p = (BiTree)calloc(1, sizeof(BiNode));
  p->data = val;
  p->lchild = create_manual_pre(arr, idx);
  p->rchild = create_manual_pre(arr, idx);
  return p;
}
