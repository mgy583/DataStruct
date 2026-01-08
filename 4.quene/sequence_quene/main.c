#include "quene.h"
#include <stdio.h>

int main() {
  SqQueue Q;
  ElementType x;

  init_quene(&Q);

  enquene(&Q, 10);
  enquene(&Q, 20);
  enquene(&Q, 30);

  printf("Quene is :");
  print_quene(&Q);

  dequene(&Q, &x);
  printf("Dequeued element: %d\n", x);
  printf("Ater dequene quene is :");
  print_quene(&Q);

  printf("Head element after dequeue: %d\n", get_head(&Q, &x));

  enquene(&Q, 30);

  printf("After enquene quene is :");
  print_quene(&Q);

  destroy_quene(&Q);
  return 0;
}
