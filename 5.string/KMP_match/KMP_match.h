#ifndef KMP_MATCH_H

#include "../sequence_string/sstring.h"

void find_next(SString S2, int *next);

int kmp_match(SString S1, SString S2, int *next);

#endif // !KMP_MATCH_H
