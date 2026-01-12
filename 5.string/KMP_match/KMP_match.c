#include "./KMP_match.h"
#include <stdio.h>

void find_next(SString T, int *next) {
  // i 为当前匹配的字符串下标
  // j 为失败的长度
  int i = 0, j = -1;
  next[0] = -1;
  while (i < T.length - 1) {
    if (j == -1 || T.ch[i] == T.ch[j]) {
      i++, j++;
      next[i] = j;
    } else {
      j = next[j];
    }
  }
}

int kmp_match(SString S1, SString S2, int *next) {
  int i = 1, j = 1;
  while (i <= S1.length && j <= S2.length) {
    if (j == 0 || S1.ch[i] == S2.ch[j]) {
      ++i, ++j;
    } else {
      j = next[j];
    }
  }

  if (j > S2.length) {
    return i - S2.length;
  } else {
    return -1;
  }
}

int main() {
  SString S1;
  str_assign(&S1, "ababaeababacababac");

  SString S2;
  str_assign(&S2, "ababac");

  printf("S2.length = %d\n", S2.length);

  int next[S2.length + 1];
  find_next(S2, next);

  printf("next : ");
  for (int i = 0; i < S2.length; ++i) {
    printf("%c ", S2.ch[i]);
  }
  printf("\n");

  printf("next : ");
  for (int i = 0; i < S2.length; ++i) {
    printf("%d ", next[i]);
  }
  printf("\n");

  int match_res = kmp_match(S1, S2, next);

  printf("res: %d", match_res);

  return 0;
}
