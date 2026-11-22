#include "stkque.h"

Stack NewStack() {
  Stack newStack;
  newStack.values = NULL;
  newStack.size = 0;
  return newStack;
}

void Push(Stack *stack, float value) {
  stack->size++;
  stack->values = realloc(stack->values, sizeof(float) * stack->size);
  stack->values[stack->size - 1] = value;
}

void Pop(Stack *stack) {
  if (stack->size == 0)
    return;

  stack->size--;
  stack->values = realloc(stack->values, sizeof(float) * stack->size);

}

float Peek(Stack *stack) {
  return stack->values[stack->size - 1];
}

bool isEmpty(Stack stack) { return stack.size <= 0; }