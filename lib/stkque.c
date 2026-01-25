#include "stkque.h"

Stack NewStack()
{
    Stack newStack; 
    newStack.values = malloc(sizeof(float));
    newStack.size = 0;
    return newStack; 
}


void Push(Stack *stack, float value)
{
    stack->values[stack->size] = value;
    stack->peek = value;
    stack->size++;
    stack->values = realloc(stack->values, sizeof(float) * stack->size);
}

void Pop(Stack *stack)
{
    stack->size--;
    stack->values = realloc(stack->values, sizeof(float) * stack->size);
}