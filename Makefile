CC= gcc
CFLAGS= -g -Wall -Wextra -std=c99 -O2

SRC= ./op.c ./decode.c ./encode.c ./test.c ./array.c
OBJ=${SRC:.c=.o}
DEP=${SRC:.c=.d}

all:test

test: ${OBJ}
.PHONY: clean

clean:
	${RM} ${OBJ}
	${RM} ${DEP}
	${RM} test

-include ${DEP}
