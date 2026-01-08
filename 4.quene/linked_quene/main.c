#include "quene.h"

int main(int argc, char *argv[]) {
  Quene Q;
  init_quene(&Q);

  enquene(&Q, 10);
  enquene(&Q, 20);
  enquene(&Q, 30);

  print_quene(&Q);

  ElemType tmp;
  dequene(&Q, &tmp);

  printf("after dequene");
  print_quene(&Q);

  ElemType x = get_head(&Q);

  printf("get head : %d\n", x);

  destory_quene(&Q);

  return EXIT_SUCCESS;
}
