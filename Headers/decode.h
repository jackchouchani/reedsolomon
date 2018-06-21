//
//  decode.h
//  Epicode1
//
//  Created by Jack Chouchani on 15/03/2018.
//  Copyright © 2018 Not A Barcode. All rights reserved.
//

#ifndef decode_h
#define decode_h

#include <stdbool.h>

struct Array* rs_calc_syndromes(struct Array *msg, uint8_t nsym, struct gf_tables *gf_table);

bool rs_check(struct Array *msg, uint8_t nsym, struct gf_tables *gf_table);

struct Array* rs_find_errdata_locator(struct Array *e_pos, struct gf_tables *gf_table);

struct Array* rs_find_error_evaluator(struct Array *synd, struct Array *err_loc, uint8_t nsym, struct gf_tables *gf_table);

struct Array* rs_correct_errdata(struct Array *msg_in, struct Array *synd, struct Array *err_pos, struct gf_tables *gf_table);

struct Array* rs_find_errors(struct Array *err_loc, size_t nmess, struct gf_tables *gf_table);

struct Array* rs_find_error_locator(struct Array* synd, uint8_t nsym, uint8_t erase_count, struct gf_tables *gf_table);

struct Array* rs_correct_msg(struct Array *msg_in, uint8_t nsym, struct Array *erase_pos, struct gf_tables *gf_table);

struct Array* rs_forney_syndromes(struct Array *synd, struct Array *pos, uint8_t nmess, struct gf_tables *gf_table);

#endif /* decode_h */
