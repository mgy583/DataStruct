#include "sstring.h"
#include <stdlib.h>

void str_assign(SString *T, char *chars) {
  int i = 0;
  while (chars[i] != '\0' && i < MAXSIZE) {
    T->ch[i] = chars[i];
    i++;
  }
  T->length = i;
  T->ch[i] = '\0';
}

void str_copy(SString *T, SString *S) {
  S->length = T->length;
  for (int i = 0; i < T->length; i++) {
    S->ch[i] = T->ch[i];
  }
}

bool str_empty(SString *T) { return T->length == 0; }

void str_clear(SString *T) {
  T->ch[0] = '\0';
  T->length = 0;
}

void str_concat(SString *T, SString *S) {
  if (T->length + S->length >= MAXSIZE) {
    return;
  }
  int i = T->length;
  int total_length = T->length + S->length;
  for (; i < total_length; i++) {
    T->ch[i] = S->ch[i - T->length];
  }

  T->length = total_length;
  T->ch[T->length] = '\0';
}
