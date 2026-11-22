//#include "lib/arrays.h"
#include "lib/stkque.h"

int main() {
    Stack mistack = NewStack();

    for(int i = 5; i >= 1; i--)
        Push(&mistack, i);

    for(int i = 0; i < 5; i++) {
        printf("%f ", Peek(&mistack));
        Pop(&mistack);
    }
    return 0;
}


