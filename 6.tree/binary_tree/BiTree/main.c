#include "bitree.h"

int main(int argc, char *argv[]) {
  ElemType arr[] = {1, 2, 4,   Nil, Nil, 5,   Nil, Nil,
                    3, 6, Nil, Nil, 7,   Nil, Nil};
  //      1
  //    /   \
  //   2     3
  //  /     / \
  // 4     6   7
  //  \
  //   5

  int idx = 0;

  BiTree T1 = create_manual_pre(arr, &idx);

  printf("pre_order: ");
  pre_order(T1);
  printf("\n");

  printf("in_order: ");
  in_order(T1);
  printf("\n");

  printf("post_order: ");
  post_order(T1);
  printf("\n");

  destory(&T1);

  return EXIT_SUCCESS;
}
