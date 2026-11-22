#ifndef STKQUE_H
#define STKQUE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    float *values;
    size_t size;
} Stack;

// Stack functions
Stack NewStack();
void Push(Stack *stack, float value);
void Pop(Stack *stack);
float Peek(Stack *stack);
bool exists(Stack stack, float value);
bool isEmpty(Stack stack);


#endif