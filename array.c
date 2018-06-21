#include "Headers/array.h"

void initArray(struct Array *a, size_t initialSize)
{
  a->array = malloc(sizeof(uint8_t) * initialSize);
  if(a->array == NULL){
    free(a);
  }
  a->used = 0;
  a->size = initialSize;
}

void initZArray(struct Array *a, size_t initialSize)
{
  a->array = calloc(initialSize, sizeof(uint8_t));
  if(a->array == NULL){
    free(a);
  }
  a->used = 0;
  a->size = initialSize;
}

void insertArray(struct Array *a)
{
  if(a->used == a->size)
    {
      a->size *= 2;
      void *p = realloc(a->array, a->size * sizeof(uint8_t));
      if(p != NULL)
        a->array = p;
      else
        exit(EXIT_FAILURE);
    }
  a->used++;
}

void deleteArray(struct Array *a)
{
  a->used--;
}


void freeArray(struct Array *a)
{
  free(a->array);
  a->array = NULL;
  a->used = 0;
  a->size = 0;
}
