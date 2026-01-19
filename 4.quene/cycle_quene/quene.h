#ifndef QUENE_H
#define QUENE_H

#include <stdbool.h>

// #define MAXSIZE 20
#define MAX_NUM 128
#define MAXSIZE        (MAX_NUM + 1)  

typedef int ElementType;

typedef struct {
  ElementType data[MAXSIZE];
  int front, rear;
} SqQueue;

void init_quene(SqQueue *Q);

void destroy_quene(SqQueue *Q);

void enquene(SqQueue *Q, ElementType x);

void dequene(SqQueue *Q, ElementType *x);

ElementType get_head(SqQueue *Q, ElementType *x);

bool is_empty(SqQueue *Q);

void print_quene(SqQueue *Q);

#endif
