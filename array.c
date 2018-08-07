#include "Headers/array.h"

//Initialize an empty array
void initArray(struct Array *A, size_t initialSize)
{
  A->array = malloc(sizeof(uint8_t) * initialSize);
  if(A->array == NULL){
    freeArray(A);
  }
  A->used = 0;
  A->size = initialSize;
}

//Initialize array filled with zeroes
void initZArray(struct Array *A, size_t initialSize)
{
  A->array = calloc(initialSize, sizeof(uint8_t));
  if(A->array == NULL){
    freeArray(A);
  }
  A->used = 0;
  A->size = initialSize;
}

//Increment the size of the array by one and double the size if in need
void insertArray(struct Array *A)
{
  if(A->used == A->size)
    {
      A->size *= 2;
      void *p = realloc(A->array, A->size * sizeof(uint8_t));
      if(p != NULL)
        A->array = p;
      else
        exit(EXIT_FAILURE);
    }
  A->used++;
}

//Decrement the size of the array by one
void deleteArray(struct Array *A)
{
  if(A->used-- == A->size >> 2){
    A->size >>= 2;
    void *p = realloc(A->array, A->size * sizeof(uint8_t));
    if(p != NULL)
      A->array = p;
    else
      exit(EXIT_FAILURE);
  }
  A->used++;

}

//Frees the array
void freeArray(struct Array *A)
{
  A->array = NULL;
  A->used = 0;
  A->size = 0;
  free(A->array);
}
