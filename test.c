#include <string.h>

#include "Headers/op.h"
#include "Headers/array.h"
#include "Headers/encode.h"
#include "Headers/decode.h"

#define BUFFER_SIZE 100


int main()
{
	struct gf_tables *gf_table = malloc(sizeof(struct gf_tables));
	gf_table->gf_exp = malloc(sizeof(struct Array));
	gf_table->gf_log = malloc(sizeof(struct Array));
	initArray(gf_table->gf_exp, 512);
	initArray(gf_table->gf_log, 256);
	gf_table = init_tables();
	
	printf("##### Reed-Solomon Error Correction #####\n");
	printf("Enter the string you want to test and press enter when you're done:\n");
	
	struct Array *msg_in = malloc(sizeof(struct Array));
	initArray(msg_in, 50);
	char my_msg[BUFFER_SIZE];
	
	fgets( my_msg, sizeof(my_msg), stdin );

	for (size_t i = 0; i < strlen(my_msg); i++) {
		msg_in->array[i] = (int)my_msg[i];
		insertArray(msg_in);
	}


	printf("Msg in: [");
	for (size_t i = 0; i < msg_in->used; i++) {
		printf("%u,",msg_in->array[i]);
	}
	printf("]\n");

	struct Array *msg = malloc(sizeof(struct Array));
	initArray(msg, 170);

	struct Array *err_loc = malloc(sizeof(struct Array));

	struct Array *synd = malloc(sizeof(struct Array));

	struct Array *pos = malloc(sizeof(struct Array));

	struct Array *rev_pos = malloc(sizeof(struct Array));

	msg = rs_encode_msg(msg_in, 14, gf_table);
	
	printf("Msg Encoded: [");
	for (size_t i = 0; i < msg->used; i++) {
		printf("%u,",msg->array[i]);
	}
	printf("]\n");
	
	
	//Tempering msg
	msg->array[0] = 0;
	msg->array[3] = 0;
	msg->array[10] = 0;
	
	printf("Msg Tempered: [");
	for (size_t i = 0; i < strlen(my_msg); i++) {
		printf("%u,",msg->array[i]);
	}
	printf("]\n");
	
	printf("Msg Tempered: ");
	for (size_t i = 0; i < strlen(my_msg); i++) {
		printf("%c",msg->array[i]);
	}
	printf("\n");
	printf("Msg Encoded: [");
	for (size_t i = 0; i < msg->used; i++) {
		printf("%u,",msg->array[i]);
	}
	printf("]\n");
	
	synd = rs_calc_syndromes(msg, 14, gf_table);
	printf("synd : ");
	for (size_t i = 0; i < synd->used; i++) {
		printf("%u, ",synd->array[i]);
	}
	printf("\n");
	err_loc = rs_find_error_locator(synd, 14, 0, gf_table);
	printf("err_loc : ");
	for (size_t i = 0; i < err_loc->used; i++) {
		printf("%u, ",err_loc->array[i]);
	}
	printf("\n");
	pos = rs_find_errors(reverse_arr(err_loc), msg->used, gf_table);
	printf("err_pos : ");
	for (size_t i = 0; i < pos->used; i++) {
		printf("%u, ",pos->array[i]);
	}
	printf("\n");
	rev_pos = reverse_arr(pos);
	
	printf("Error positions: [");
	for (size_t i = 0; i < rev_pos->used; i++) {
		printf("%u,", rev_pos->array[i]);
	}
	printf("]\n");
	
	struct Array *err_pos = malloc(sizeof(struct Array));
	initArray(err_pos, 3);
	err_pos->array[0] = 0;
	
	msg = rs_correct_msg(msg, 14, err_pos, gf_table);
	
	printf("Msg Corrected: [");
	for (size_t i = 0; i < msg->used; i++) {
		printf("%u,",msg->array[i]);
	}
	printf("]\n");
	
	printf("Msg Corrected: ");
	for (size_t i = 0; i < strlen(my_msg); i++) {
		printf("%c",msg->array[i]);
	}
	printf("\n");
	freeArray(gf_table->gf_exp);
	freeArray(gf_table->gf_log);
	freeArray(msg_in);
	freeArray(msg);
	freeArray(synd);
	freeArray(pos);
	freeArray(rev_pos);

	return 0;
}
