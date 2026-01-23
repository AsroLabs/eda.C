#include "lib.h"

void printArray(float array[], size_t length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%.0f ", array[i]);
    }
    printf("\n");
}

void swapNums(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}


// We use a double for loop for doing these two things:
//  1. (marking the first element as sorted) we iterate over each element of the array
//  2. Each iterated element is moved to the left until there's no bigger element before its position

void InsertionSort(float array[], size_t length)
{
    for (size_t i = 1; i < length; i++) {
        for (int j = i; j > 0; j--) {
            if(array[j] < array[(j - 1)]) //
                swapNums(&array[j], &array[j - 1]);
            else
                break;
        }
        printArray(array, length);

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


void merge(float array[], int left, int middle, int right){
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];

    
    for (int j = 0; j < n2; j++)
        R[j] = array[middle + 1 + j];

    int i = 0, j = 0, k = left; 
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(float array[], int begin, int end)
{
  if(begin < end)
  {
    int mid = begin + (end - begin) / 2;

    // printArray(array, end);
    MergeSort(array, begin, mid);
    
    // printArray(array, end);
    MergeSort(array, mid + 1, end);
    
    merge(array, begin, mid, end);
    // printArray(array, end);

  }
}
