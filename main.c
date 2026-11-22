#include "lib/stkque.h"


int main() {
    Queue queue = NewQueue();

    enqueue(&queue, 2);
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    float current = Front(&queue);
    printf("Front Queue: %f\n", current);
    dequeue(&queue);
    dequeue(&queue);
    current = Front(&queue);
    printf("Front Queue after dequeue: %f\n", current);

    return 0;
}


