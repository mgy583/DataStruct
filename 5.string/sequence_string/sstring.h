#ifndef SSTRING_H
#define SSTRING_H

#include <stdbool.h>
#define MAXSIZE 100

typedef struct SString {
  char ch[MAXSIZE];
  int length;
} SString;

void str_assign(SString *T, char *chars);

void str_copy(SString *T, SString *S);

bool str_empty(SString *T);

int str_length(SString *T);

void str_clear(SString *T);

void str_concat(SString *T, SString *S);

#endif // !SSTRING_H
