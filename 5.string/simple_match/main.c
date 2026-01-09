#include "../sequence_string/sstring.h"
#include "simple_match.h"
#include <stdio.h>

int main() {
  SString S1;
  str_assign(&S1,
             "it's a test string to test this function about match string");

  SString S2;
  str_assign(&S2, "tion");

  int index = match(&S1, &S2);

  for (int i = 0; i < S1.length; i++) {
    printf("%c", S1.ch[i]);
  }
  printf("\n");

  for (int i = 0; i < S2.length; i++) {
    printf("%c", S2.ch[i]);
  }
  printf("\n");

  printf("match index: %d\n", index);

  return 0;
}
