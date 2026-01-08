#ifndef QUENE_H

#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
  ElemType data;
  struct Node *next;
} Node;

typedef struct Quene {
  Node *first, *rear;
} Quene;

void init_quene(Quene *Q);

void enquene(Quene *Q, ElemType x);

ElemType dequene(Quene *Q, ElemType *x);

ElemType get_head(Quene *Q);

void destory_quene(Quene *Q);

bool is_full(Quene *Q);

bool is_empty(Quene *Q);

#endif // !QUENE_H
