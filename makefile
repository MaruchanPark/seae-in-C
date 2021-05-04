CC = gcc
CFLAGS = -lm

FUNCTIONS = conv_gcc.c deconv_gcc.c file_input.c functions.c skip_connection_2d.c

OUT :
	gcc $(FUNCTIONS) main.c $(CFLAGS) -o a.out

clean :
	rm -rf *.gch
