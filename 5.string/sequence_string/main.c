#include "sstring.h"
#include <stdio.h>

int main() {
  SString s1, s2;
  char text1[] = "Hello";
  char text2[] = " World";

  // 初始化字符串
  str_assign(&s1, text1);
  str_assign(&s2, text2);

  printf("Before concat: %s (length: %d)\n", s1.ch, s1.length);

  // 拼接s2到s1后面
  str_concat(&s1, &s2);

  printf("After concat: %s (length: %d)\n", s1.ch, s1.length);

  return 0;
}
