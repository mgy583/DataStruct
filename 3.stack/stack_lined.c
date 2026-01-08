#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct StackNode {
    int data;
    struct StackNode* next;
}StackNode;

void init_stack(StackNode **stack) {
    *stack = NULL;
}

bool is_empty(StackNode* stack) {
    return stack == NULL;
}

int push(StackNode** stack, int value) {
    StackNode* new_node= malloc(sizeof(StackNode));  
    if(!new_node) return -1;
    new_node->data = value;
    new_node->next = *stack;
    *stack = new_node;
    return 0;
}

int pop(StackNode** stack, int *value) {
    if(is_empty(*stack)) return -1;
    StackNode *tmp = *stack;
    *value = tmp->data;
    *stack = tmp->next;
    free(tmp);
    return 0;
}

int get_top(StackNode* stack){
    if(is_empty(stack)) return -1;
    return stack->data;
}

int main() {
    StackNode *s;
    init_stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 30);
    
    int x;
    pop(&s, &x);
    printf("%d\n", x);
    pop(&s, &x);
    int value = get_top(s);
    pop(&s, &x);
    printf("%d\n", value);
    
    return 0;
}



