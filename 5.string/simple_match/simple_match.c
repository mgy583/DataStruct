#include "simple_match.h"

int match(SString *S1, SString *S2) {
  int i = 0, j = 0;
  while (i < S1->length && j < S2->length) {
    if (S1->ch[i] == S2->ch[j]) {
      ++i, ++j;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }
  if (j == S2->length) {
    return i - S2->length;
  } else {
    return 0;
  }
}
