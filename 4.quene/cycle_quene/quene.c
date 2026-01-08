#include "quene.h"
#include <stdio.h>

// 初始化队列
void init_quene(SqQueue *Q) {
  Q->front = 0;
  Q->rear = 0;
}

// 销毁队列
void destroy_quene(SqQueue *Q) {
  Q->front = 0;
  Q->rear = 0;
}

bool is_empty(SqQueue *Q) { return Q->front == Q->rear; }

bool is_full(SqQueue *Q) { return (Q->rear + 1) % MAXSIZE == Q->front; }

// 入队
void enquene(SqQueue *Q, ElementType x) {
  if (is_full(Q)) {
    printf("Queue is full\n");
    return;
  }

  Q->data[Q->rear] = x;
  Q->rear = (Q->rear + 1) % MAXSIZE;
}

void dequene(SqQueue *Q, ElementType *x) {
  if (is_empty(Q)) {
    printf("Queue is empty\n");
    return;
  }
  *x = Q->data[Q->front];
  Q->front = (Q->front + 1) % MAXSIZE;
}

ElementType get_head(SqQueue *Q, ElementType *x) {
  if (is_empty(Q)) {
    printf("Queue is empty\n");
    return -1; // Indicate error
  }
  *x = Q->data[Q->front];
  return *x;
}

void print_quene(SqQueue *Q) {
  if (is_empty(Q)) {
    return;
  }
  for (int i = Q->front; i != Q->rear; i = (i + 1) % MAXSIZE) {
    printf("%d ", Q->data[i]);
  }
  printf("\n");
}
