#include "quene.h"
#include <stdbool.h>
#include <stdlib.h>

void init_quene(Quene *Q) {
  Q->first = NULL;
  Q->rear = NULL;
}

bool is_empty(Quene *Q) { return Q->first == NULL; }

void enquene(Quene *Q, ElemType x) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = x;
  new_node->next = NULL;
  if (is_empty(Q)) {
    Q->rear = new_node;
    Q->first = new_node;
  } else {
    Q->rear->next = new_node;
    Q->rear = new_node;
  }
}

bool dequene(Quene *Q, ElemType *x) {
  if (is_empty(Q)) {
    return 0;
  }
  Node *de_node = Q->first;
  *x = de_node->data;
  Q->first = Q->first->next;
  if (Q->rear == de_node) {
    Q->first = NULL;
    Q->rear = NULL;
  }
  free(de_node);
  return 1;
}

ElemType get_head(Quene *Q) {
  if (is_empty(Q)) {
    printf("quene is empty");
    return EXIT_FAILURE;
  }
  return Q->first->data;
}

void destory_quene(Quene *Q) {
  ElemType tmp;
  while (dequene(Q, &tmp))
    ;
  Q->first = Q->rear = NULL;
}

void print_quene(Quene *Q) {
  Node *node = Q->first;
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}
