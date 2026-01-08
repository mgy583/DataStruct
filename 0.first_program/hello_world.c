#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float tusk_length;
    float weight;
} Walrus;

int main() {
    Walrus *w1 = malloc(sizeof(Walrus));

    if (w1 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    w1->tusk_length = 8.5f;
    w1->weight = 800.5f;

    Walrus *w2 = w1;
    w2->tusk_length = 9.0f;

    printf("walrus 1 - tusk length: %.2f, weight: %.2f\n", w1->tusk_length, w1->weight);
    printf("walrus 2 - tusk length: %.2f, weight: %.2f\n", w2->tusk_length, w2->weight);

    free(w1);

    return 0;
}