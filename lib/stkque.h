#ifndef SORTING_H
#define SORTING_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    float *values;
    float peek;
    size_t size;
} Stack;

// Stack functions
Stack NewStack();
void Push(Stack *stack, float value);
void Pop(Stack *stack);
bool isEmpty(Stack stack);


#endif