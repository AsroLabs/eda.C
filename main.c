#include "./lib/arrays.h"
#include "./lib/stkque.h"

int main() {

  Stack miStack = NewStack();
  
  for(int i = 1; i <= 10; i++) //añadir 10 elementos
    Push(&miStack, i);

  printf("size: %lu\n", miStack.size);
  printf("peek: %f\n", miStack.peek);
  
  printArray(miStack.values, miStack.size);
  
  for(int i = 1; i <= 6; i++) //eliminar 6 elementos
    Pop(&miStack);
  printf("size: %lu\n", miStack.size);
  printf("peek: %f\n", miStack.peek);

  printArray(miStack.values, miStack.size);

  return 0;
}
