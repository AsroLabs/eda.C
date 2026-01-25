#include "sorting.h"

void printArray(float array[], size_t length) {
  for (int i = 0; i < length; i++) {
    printf("%.0f ", array[i]);
  }
  printf("\n");
}

void swapNums(float *a, float *b) {
  float temp = *a;
  *a = *b;
  *b = temp;
}

// We use a double for loop for doing these two things:
//  1. (marking the first element as sorted) we iterate over each element of the
//  array
//  2. Each iterated element is moved to the left until there's no bigger
//  element before its position

void InsertionSort(float array[], size_t length) {
  for (size_t i = 1; i < length; i++) {
    for (int j = i; j > 0; j--) {
      if (array[j] < array[(j - 1)]) //
        swapNums(&array[j], &array[j - 1]);
      else
        break;
    }
  }
}

/*
             start point (i)
                  |
                  |
                  V
    /-----\    /-----\    /-----\    /-----\    /-----\
    |     |    |     |    |     |    |     |    |     |
    |  5  |    |  3  |    |  2  |    |  1  |    |  4  |
    |     |    |     |    |     |    |     |    |     |
    \-----/    \-----/    \-----/    \-----/    \-----/
                j = 1

    we iterate from the start point to 0 [for (int j = i; j > 0; j--))]
    if the 'j' position item is smaller than its left, then swap their values
*/

/*
        SWAP THEM [swap(array[j], array[j - 1])]
       ____________
       |          |
       |          |
       V          V
    /-----\    /-----\    /-----\    /-----\    /-----\
    |     |    |     |    |     |    |     |    |     |
    |  3  |    |  5  |    |  2  |    |  1  |    |  4  |
    |     |    |     |    |     |    |     |    |     |
    \-----/    \-----/    \-----/    \-----/    \-----/
                j = 1
    */
/*
                        New Start Point (i)
                             |
                             |
                             V
    /-----\    /-----\    /-----\    /-----\    /-----\
    |     |    |     |    |     |    |     |    |     |
    |  3  |    |  5  |    |  2  |    |  1  |    |  4  |
    |     |    |     |    |     |    |     |    |     |
    \-----/    \-----/    \-----/    \-----/    \-----/
                           j = 2
*/
/*
                   SWAP THEM [swap(array[j], array[j - 1])]
                  ____________
                  |          |
                  |          |
                  V          V
    /-----\    /-----\    /-----\    /-----\    /-----\
    |     |    |     |    |     |    |     |    |     |
    |  3  |    |  2  |    |  5  |    |  1  |    |  4  |
    |     |    |     |    |     |    |     |    |     |
    \-----/    \-----/    \-----/    \-----/    \-----/
                           j = 2
*/
/*
        SWAP THEM [swap(array[j], array[j - 1])]
       ____________
       |          |
       |          |
       V          V
    /-----\    /-----\    /-----\    /-----\    /-----\
    |     |    |     |    |     |    |     |    |     |
    |  2  |    |  3  |    |  5  |    |  1  |    |  4  |
    |     |    |     |    |     |    |     |    |     |
    \-----/    \-----/    \-----/    \-----/    \-----/
                j = 1
*/

void merge(float array[], int left, int middle, int right) {
  // for example: array of 5 elements (from pos 0 to 4)
  // middle element: 2

  int leftSize = middle - left + 1; // 2 - 0 + 1 = 3 elements
  int rightSize = right - middle;   // 4 - 2 = 2 elements

  float Left[leftSize], Right[rightSize];

  for (int i = 0; i < leftSize; i++)
    Left[i] = array[left + i]; // creates the left array from the initial one


  for (int j = 0; j < rightSize; j++)
    Right[j] =
        array[(middle + 1) + j]; // creates the right array from the initial one


  int i = 0 /* left iterator */, 
  	j = 0 /* right iterator */,
    k = left /* final array length (from left (0)) */; // iterators for the final
                                                   // array

  while (i < leftSize && j < rightSize) {
    if (Left[i] <= Right[j]) {
      array[k] = Left[i];
      i++;
    } else {
      array[k] = Right[j];
      j++;
    }
    k++;
  }

  while (i < leftSize) {
    array[k] = Left[i];
    i++;
    k++;
  }

  while (j < rightSize) {
    array[k] = Right[j];
    j++;
    k++;
  }

  //results on the final array of size k
}

void MergeSort(float array[], int begin, int end) {
  if (begin < end) {
    int mid = begin + (end - begin) / 2;

    MergeSort(array, begin, mid);

    MergeSort(array, mid + 1, end);

    merge(array, begin, mid, end);
  }
}
