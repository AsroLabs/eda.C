#include "stkque.h"
#include <stdio.h>
#include <stdlib.h>

// Stack

Stack NewStack() {
  Stack newStack;
  newStack.values = NULL;
  newStack.size = 0;
  newStack.peek = 0;
  return newStack;
}

void Push(Stack *stack, float value) {
  stack->size++;
  stack->values = realloc(stack->values, sizeof(float) * stack->size);
  stack->values[stack->size - 1] = value;
  stack->peek = value;
}

void Pop(Stack *stack) {
  if (stack->size == 0)
    return;

  stack->size--;
  stack->values = realloc(stack->values, sizeof(float) * stack->size);

  if (stack->size > 0)
    stack->peek = stack->values[stack->size - 1];
}

bool isStackEmpty(Stack stack) { return stack.size <= 0; }

// Queue

Queue NewQueue() {
  Queue newQueue;
  newQueue.values = NULL;
  newQueue.size = 0;
  newQueue.front = 0;
  return newQueue;
}

void enqueue(Queue *queue, float value) {
  queue->size++;
  queue->values = realloc(queue->values, sizeof(float) * queue->size);
  queue->values[queue->size - 1] = value;
  queue->front = value;
}

void dequeue(Queue *queue) {
  if (queue->size == 0)
    return;

  queue->size--;
  queue->values = realloc(queue->values,  sizeof(float) * queue->size);
  
  if (queue->size > 0)
    queue->front = queue->values[queue->size - 1];
}

void front(Queue *queue) {
  if (queue->size == 0)
    return;

  printf("%f", queue->values[0]);
}

bool isQueueEmpty(Queue queue) { return queue.size <= 0; }