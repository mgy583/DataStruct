#ifndef STACK_H
#define SRACK_H

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct StackNode {
    int data[MAXSIZE];
    int top;
} StackNode;

void initStack(StackNode* stack);

int isFull(StackNode* stack);

int isEmpty(StackNode* stack);


int push(StackNode* stack, int value); 

int pop(StackNode* stack, int* value); 

int peek(StackNode stack, int* value);

int get_top(StackNode* stack);

#endif // STACK_H