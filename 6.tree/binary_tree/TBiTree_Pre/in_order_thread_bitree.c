#include "in_order_thread_bitree.h"
#include <stdio.h>
#include <stdlib.h>

static BiTree pre = NULL;

void init_bitree(BiTree *bt) { *bt = NULL; }

void destory(BiTree bt) {
  if (bt) {
    if (bt->ltag == 0 && bt->lchild != NULL) {
      destory(bt->lchild);
    }
    if (bt->rtag == 0 && bt->rchild != NULL) {
      destory(bt->rchild);
    }
  }
  free(bt);
}

BiTree create_manual_pre(ElemType *arr, int *idx) {
  if (arr[*idx] == Nil) {
    (*idx)++;
    return NULL;
  }

  BiTree node = (BiTree)malloc(sizeof(BiNode));
  if (!node) {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  node->data = arr[(*idx)++];
  node->ltag = 0;
  node->rtag = 0;
  node->lchild = create_manual_pre(arr, idx);
  node->rchild = create_manual_pre(arr, idx);

  return node;
}

static void in_order_traverse(BiTree bt) {
  if (bt) {
    if (bt->ltag == 0) {
      in_order_traverse(bt->lchild);
    }
    printf("%d ", bt->data);
    if (bt->rtag == 0) {
      in_order_traverse(bt->rchild);
    }
  }
}

void in_order(BiTree bt) {
  printf("In-order traversal:");
  in_order_traverse(bt);
  printf("\n");
}

// 中序线索化
void in_threading(BiTree bt) {
  if (bt) {
    if (bt->ltag == 0) {
      in_threading(bt->lchild);
    }

    if (bt->lchild == NULL) {
      bt->ltag = 1;
      bt->lchild = pre;
    }

    if (pre && pre->rchild == NULL) {
      pre->rtag = 1;
      pre->rchild = bt;
    }

    pre = bt;

    if (bt->rtag == 0) {
      in_threading(bt->rchild);
    }
  }
}

// 中序线索化二叉树
void in_thread(BiTree bt) {
  if (bt == NULL)
    return;
  pre = NULL;
  in_threading(bt);
  if (pre && pre->rchild == NULL) {
    pre->rtag = 1;
  }
}

// 找到中序序列的第一个节点
static BiTree first_node(BiTree bt) {
  BiTree p = bt;
  if (p == NULL)
    return NULL;

  while (p->ltag == 0) {
    p = p->lchild;
  }
  return p;
}

// 找到中序序列的下一个节点
static BiTree next_node(BiTree p) {
  if (p->rtag == 1) {
    return p->rchild;
  } else {
    BiTree q = p->rchild;
    if (q == NULL)
      return NULL;
    while (q->ltag == 0) {
      q = q->lchild;
    }
    return q;
  }
}

void in_order_thread(BiTree bt) {
  printf("Threaded in-order traversal: ");
  if (bt == NULL) {
    printf("\n");
    return;
  }
  BiTree p = first_node(bt);

  while (p) {
    printf("%d ", p->data);
    p = next_node(p);
  }
  printf("\n");
}
