#include <stdio.h>
#include <stdlib.h>

void one_d_conv(int N,int D_INPUT,float* x,int F,int D ,float* W,int S,float* b, int O, float* out);
void one_d_deconv(int N,int D_INPUT,float* x,int F,int D ,float* W,int S,float* b, int O, float* out);
void read_txt(char *file_name, int length, float *arr);
void preemph(float* preemph_input, int input_length ,float coeff);
void deemph(float* deemph_input, int input_length, float coeff);
void prelu(float* prelu_input, int input_channel, int input_length ,float* alpha);
void skip_connection_2d(int dim1, int dim2, float *arr1, float *arr2, float *skip);

void *memcpy(void *str1, const void *str2, size_t n);
