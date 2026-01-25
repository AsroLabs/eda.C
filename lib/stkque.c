#include "stkque.h"

Stack NewStack()
{
    Stack newStack; 
    newStack.values = NULL;
    newStack.size = 0;
    newStack.peek = 0; 
    return newStack; 
}

void Push(Stack *stack, float value)
{
    stack->size++;
    stack->values = realloc(stack->values, sizeof(float) * stack->size);
    stack->values[stack->size - 1] = value;
    stack->peek = value;
}

void Pop(Stack *stack)
{
    stack->size--;
    stack->values = realloc(stack->values, sizeof(float) * stack->size);
    stack->peek = stack->values[stack->size - 1];
}