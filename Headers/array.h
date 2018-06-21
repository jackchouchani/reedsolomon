# ifndef ARRAY_H
# define ARRAY_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "array.h"


struct Array{
  uint8_t *array;
  size_t used;
  size_t size;
};

void initArray(struct Array *a, size_t initialSize);

void initZArray(struct Array *a, size_t initialSize);

void insertArray(struct Array *a);

void deleteArray(struct Array *a);

void freeArray(struct Array *a);

#endif
