#include "lib/sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  const size_t ARR_SIZE = 10;
  const int N_MAX = 100;
  clock_t start_t, end_t;
  double total_t;

  float *array = malloc(sizeof(float) * ARR_SIZE);

  for (size_t i = 0; i < ARR_SIZE; i++) {
    array[i] = rand() % (N_MAX + 1); // closed interval of random nums [0, N_MAX]
  }

  start_t = clock();

  InsertionSort(array, ARR_SIZE);
  // MergeSort(array, 0, ARR_SIZE - 1);

  end_t = clock();

  printArray(array, ARR_SIZE);

  total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  printf("\nTotal time taken by CPU: %f\n", total_t);

  return 0;
}