#include "stkque.h"
#include <stdlib.h>

// Stack

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

bool exists(Stack stack, float value) {
  bool result = false;
  for(int i = 0; i < stack.size; i++) {
    if(stack.values[i] == value)
      result = true;
  }

  return result;

}

bool isStackEmpty(Stack stack) { return stack.size <= 0; }

// Queue

Queue NewQueue() {
  Queue newQueue;
  newQueue.values = NULL;
  newQueue.size = 0;
  return newQueue;
}

void enqueue(Queue *queue, float value) {
  queue->size++;
  queue->values = realloc(queue->values, sizeof(float) * queue->size);
  queue->values[queue->size - 1] = value;
}

void dequeue(Queue *queue) {
  if (queue->size == 0)
    return;

  queue->size--;
  queue->values = realloc(queue->values,  sizeof(float) * queue->size);
}

float Front(Queue *queue) {
  if (queue->size == 0)
    return -1;

  return queue->values[0];
}

bool isQueueEmpty(Queue queue) { return queue.size <= 0; }