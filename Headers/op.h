# ifndef OP_H
# define OP_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <err.h>

#include "array.h"

/*Struct containing the exponential and logarithmic tables for faster computations*/
struct gf_tables {
  struct Array *gf_exp;
  struct Array *gf_log;
};

/*Struct used to store two numbers in a struct.*/
struct Tuple {
  struct Array *x;
  struct Array *y;
};

struct gf_tables* init_tables();

struct Array* merge(struct Array *l1, struct Array *l2);

struct Array* copy_arr(struct Array *l1, struct Array *l2);

struct Array* pop_arr(struct Array *l);

struct Array* reverse_arr(struct Array *l);

uint8_t gf_add(uint8_t x, uint8_t y);

uint8_t gf_sub(uint8_t x, uint8_t y);

uint8_t gf_pow(uint8_t x, uint16_t power, struct gf_tables *gf_table);

uint8_t gf_mul(uint8_t x, uint8_t y, struct gf_tables *gf_table);

uint8_t gf_inverse(uint8_t x, struct gf_tables *gf_table);

uint8_t gf_div(uint8_t x, uint8_t y, struct gf_tables *gf_table);

struct Array* gf_poly_scale(struct Array *p, uint8_t x, struct gf_tables *gf_table);

struct Array* gf_poly_add(struct Array *p, struct Array *q);

struct Array* gf_poly_mul(struct Array *p, struct Array *q, struct gf_tables *gf_table);

uint8_t gf_poly_eval(struct Array *p, uint8_t x, struct gf_tables *gf_table);

struct Tuple* gf_poly_div(struct Array *dividend, struct Array *divisor, struct gf_tables *gf_table);

#endif
