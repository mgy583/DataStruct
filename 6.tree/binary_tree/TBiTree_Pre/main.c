#include "in_order_thread_bitree.h"
#include <stdio.h>

int main() {
  BiTree root = NULL;

  // 二叉树结构：
  //      1
  //    /   \
  //   2     3
  //  /     / \
  // 4     6   7
  //  \
  //   5
  ElemType arr[] = {
      1,             // 根节点1
      2,             // 左孩子2
      4,   Nil,      // 2的左孩子4，4无左孩子，有右孩子5
      5,   Nil, Nil, // 4的右孩子5，5无左右孩子
      Nil,           // 2无右孩子
      3,             // 右孩子3
      6,   Nil, Nil, // 3的左孩子6，6无左右孩子
      7,   Nil, Nil, // 3的右孩子7，7无左右孩子
      Nil            // 结束
  };

  int idx = 0;

  printf("Creating binary tree...\n");

  // 创建二叉树
  root = create_manual_pre(arr, &idx);

  printf("\nBinary Tree Structure:\n");
  printf("      1\n");
  printf("    /   \\\n");
  printf("   2     3\n");
  printf("  /     / \\\n");
  printf(" 4     6   7\n");
  printf("  \\\n");
  printf("   5\n");

  // 普通中序遍历
  in_order(root);

  // 线索化二叉树
  printf("\nThreading the binary tree...\n");
  in_thread(root);

  // 线索化后的中序遍历（非递归）
  in_order_thread(root);

  // 验证中序遍历序列
  printf("\nExpected in-order traversal: 4 5 2 1 6 3 7\n");

  // 销毁二叉树
  destory(root);
  root = NULL;
  printf("\nBinary tree destroyed.\n");

  return 0;
}
