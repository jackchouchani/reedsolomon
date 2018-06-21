# ifndef ENCODING_H
# define ENCODING_H


struct Array* rs_encode_msg(struct Array *msg_in, uint8_t nsym, struct gf_tables *gf_tables);

#endif
