#ifndef ARRAYS_H
#define ARRAYS_H
#include <stdio.h>

void printArray(float array[], size_t length);

void InsertionSort(float array[], size_t length);
void MergeSort(float array[], int begin, int end);
void Quicksort(float array[], int low, int high);

#endif