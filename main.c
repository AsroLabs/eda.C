#include "lib/arrays.h"

int main() {
    float myArray[] = {64, 34, 25, 12, 22, 11, 90, 5};
    int n = sizeof(myArray) / sizeof(myArray[0]);

    Reversalarray(myArray, 0, n - 1);

    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%.f ", myArray[i]);
    }
    return 0;
}


