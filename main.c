#include "lib/arrays.h"
#include "lib/stkque.h"


int main() {
    Queue queue = NewQueue();

    enqueue(&queue, 2);
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    dequeue(&queue);
    front(&queue);

    return 0;
}


