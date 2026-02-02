#ifndef HSHTBL_H
#define HSHTBL_H
#include <stdio.h>


typedef struct {
    size_t size;
    char ***elements;
} HashSet;

HashSet newHashSet();

#endif