#include "lib.h"

int main() {
  float arrayTest[] = {49, 9, 7, 31, 36, 38, 35, 36, 15, 44};
  int length = sizeof(arrayTest) / sizeof(arrayTest[0]);
  InsertionSort(arrayTest, length);

  for (int i = 0; i < length; i++) {
	printf("%.0f\n", arrayTest[i]);
  }

  return 0;
}
