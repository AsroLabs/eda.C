// #include "lib/arrays.h"
#include "lib/stkque.h"

int main() {
  // float arrayTest[] = {49, 9, 7, 31, 36, 38, 35, 36, 15, 44};
  // int length = sizeof(arrayTest) / sizeof(arrayTest[0]);

  // InsertionSort(arrayTest, length);
  // MergeSort(arrayTest, 0, length - 1);

  // printf("\nArray ordenado: \n");
  // printArray(arrayTest, length);
  // printf("\n");

  Stack miStack = NewStack();
  
  Push(&miStack, 5);
  Push(&miStack, 6);
  Push(&miStack, 7);
  Push(&miStack, 8);
  Push(&miStack, 9);
  Push(&miStack, 10);

  printf("size: %lu\n", miStack.size);
  for(int i = 0; i < miStack.size; i++)
  {
    printf("%f ", miStack.values[i]);
  }
  printf("\n");

  Pop(&miStack);
  Pop(&miStack);
  printf("size: %lu\n", miStack.size);

  for(int i = 0; i < miStack.size; i++)
  {
    printf("%f ", miStack.values[i]);
  }
  printf("\n");
  
  return 0;
}
