#include "quene.h"
#include <stdbool.h>

void init_quene(Quene *Q) {
  Q->rear = (Quene *)malloc(sizeof(Quene));
  Q->first = (Quene *)malloc(sizeof(Quene));
  Q->first->next = NULL;
}

bool is_empty(Quene *Q) { return Q->rear == 0; }

bool is_empty(Quene *Q) { return Q->first == Q->rear; }

void enquene(Quene *Q, ElemType x) {}
