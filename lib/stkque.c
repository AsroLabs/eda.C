#include "stkque.h"
#include <stdlib.h>
#include <string.h>

// Stack

Stack NewStack() {
  Stack newStack;
  newStack.values = NULL;
  newStack.size = 0;
  return newStack;
}

void Push(Stack *stack, float value) {
  if (stack == NULL)
    return;

  size_t newSize = stack->size + 1;
  float *resized = realloc(stack->values, sizeof(float) * newSize);
  if (resized == NULL)
    return;

  stack->values = resized;
  stack->size = newSize;
  stack->values[stack->size - 1] = value;
}

void Pop(Stack *stack) {
  if (stack == NULL || stack->size == 0)
    return;

  stack->size--;

  if (stack->size == 0) {
    free(stack->values);
    stack->values = NULL;
    return;
  }

  float *resized = realloc(stack->values, sizeof(float) * stack->size);
  if (resized != NULL) {
    stack->values = resized;
  }
}

float Peek(Stack *stack) {
  if (stack == NULL || stack->size == 0)
    return -1.0f;

  return stack->values[stack->size - 1];
}

bool exists(Stack stack, float value) {
  for (size_t i = 0; i < stack.size; i++) {
    if (stack.values[i] == value)
      return true;
  }

  return false;
}

bool isStackEmpty(Stack stack) { return stack.size == 0; }

// Queue

Queue NewQueue() {
  Queue newQueue;
  newQueue.values = NULL;
  newQueue.size = 0;
  return newQueue;
}

void enqueue(Queue *queue, float value) {
  if (queue == NULL)
    return;

  size_t newSize = queue->size + 1;
  float *resized = realloc(queue->values, sizeof(float) * newSize);
  if (resized == NULL)
    return;

  queue->values = resized;
  queue->size = newSize;
  queue->values[queue->size - 1] = value;
}

void dequeue(Queue *queue) {
  if (queue == NULL || queue->size == 0)
    return;

  queue->size--;

  if (queue->size == 0) {
    free(queue->values);
    queue->values = NULL;
    return;
  }

  memmove(queue->values, queue->values + 1, sizeof(float) * queue->size);

  float *resized = realloc(queue->values, sizeof(float) * queue->size);
  if (resized != NULL) {
    queue->values = resized;
  }
}

float Front(Queue *queue) {
  if (queue == NULL || queue->size == 0)
    return -1.0f;

  return queue->values[0];
}

bool isQueueEmpty(Queue queue) { return queue.size == 0; }