//#include "lib/arrays.h"
#include "lib/stkque.h"

int main() {
    Stack mistack = NewStack();

    for(int i = 5; i >= 1; i--)
        Push(&mistack, i);


    printf("Está el stack vacío?: %d\n", isEmpty(mistack));
    printf("el número 6 existe?: %d\n", exists(mistack, 6));
    printf("el número 2 existe?: %d\n", exists(mistack, 2));

    for(int i = 0; i < 5; i++) {
        printf("%f ", Peek(&mistack));
        Pop(&mistack);
    }

    printf("\n");
    printf("Está el stack vacío?: %d\n", isEmpty(mistack));

    return 0;
}


