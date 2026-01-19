#include "stack_array.h"
#include<stdio.h>
#include<stdlib.h>

/* #define MAXSIZE 100

typedef struct StackNode {
    int data[MAXSIZE];
    int top;
} StackNode;
 */
void initStack(StackNode* stack) {
    stack->top = -1;
}

int isFull(StackNode* stack) {
    return stack->top == MAXSIZE - 1;
}

int isEmpty(StackNode* stack) {
    return stack->top == -1;
}

int push(StackNode* stack, int value) {
    if (isFull(stack)) {
        return -1; // Stack overflow
    }
    stack->data[++(stack->top)] = value;
    return 0; // Success
}

int pop(StackNode* stack, int* value) {
    if (isEmpty(stack)) {
        return -1; // Stack underflow
    }
    if (value) { *value = stack->data[stack->top]; }
    stack->top--;
    return 0; // Success
}

int peek(StackNode stack, int* value) {
    if (isEmpty(&stack)) {
        return -1; // Stack is empty
    }
    *value = stack.data[stack.top];
    return 0; // Success
}

int get_top(StackNode* stack) {
    if (isEmpty(stack)) {
        return -1; // Stack is empty
    }
    // pop(stack, NULL);
    return stack->data[stack->top];
}


/* int main() {
    StackNode stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    int topValue;
    peek(stack, &topValue);
    printf("Top value: %d\n", topValue); // Should print 30

    while (!isEmpty(&stack)) {
        int value;
        pop(&stack, &value);
        printf("Popped value: %d\n", value);
    }

    return 0;
} */