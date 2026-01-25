#include "./lib/arrays.h"
#include "./lib/stkque.h"

int main() {
  // float arrayTest[] = {49, 9, 7, 31, 36, 38, 35, 36, 15, 44};
  // int length = sizeof(arrayTest) / sizeof(arrayTest[0]);

  // InsertionSort(arrayTest, length);
  // MergeSort(arrayTest, 0, length - 1);

  // printf("\nArray ordenado: \n");
  // printArray(arrayTest, length);
  // printf("\n");

  Stack miStack = NewStack();
  
  for(int i = 1; i <= 10; i++)
    Push(&miStack, i);
  
  printf("size: %lu\n", miStack.size);
  printf("peek: %f\n", miStack.peek);
  
  printArray(miStack.values, miStack.size);
  

  
  return 0;
}
