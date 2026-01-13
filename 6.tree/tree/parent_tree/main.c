#include "tree.h"

int main(void) {
  PTTree T;
  init_tree(&T);

  /* 1. 根 */
  int r = insert_root(&T, 10);
  printf("insert root 10 , idx = %d\n", r);

  /* 2. 给根插 3 个孩子 */
  int c1 = insert_child(&T, r, 0, 20);
  int c2 = insert_child(&T, r, 1, 30);
  int c3 = insert_child(&T, r, 2, 40);
  printf("insert 20 30 40 under root, idx = %d %d %d\n", c1, c2, c3);

  /* 3. 给 30（idx=2）再插 2 个孩子 */
  int c4 = insert_child(&T, c2, 0, 31);
  int c5 = insert_child(&T, c2, 1, 32);
  printf("insert 31 32 under 30, idx = %d %d\n", c4, c5);

  /* 4. 层序打印整棵树 */
  printf("\nLevel-order traversal:\n");
  level_order(&T);
  return 0;
}
