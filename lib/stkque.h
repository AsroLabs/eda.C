#ifndef STKQUE_H
#define STKQUE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack
typedef struct {
    float *values;
    float peek;
    size_t size;
} Stack;

// Stack functions
Stack NewStack();
void Push(Stack *stack, float value);
void Pop(Stack *stack);
bool isStackEmpty(Stack stack);

// Queue 
typedef struct{
    float *values;
    float front;
    size_t size;
} Queue;

// Queue functions
Queue NewQueue();
void enqueue(Queue *queue, float value);
void dequeue(Queue *queue);
void front(Queue *queue);
bool isQueueEmpty(Queue queue);
#endif