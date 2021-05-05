#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "header.h"
#include "var.h"

void main () {

// Filters for encoder
  ENC_F_0 =   malloc((OUTPUT_CHANNELS[0] * INPUT_CHANNELS[0] * FILTER_LENGTH) * sizeof(float));
  ENC_F_1 =   malloc((OUTPUT_CHANNELS[1] * INPUT_CHANNELS[1] * FILTER_LENGTH) * sizeof(float));
  ENC_F_2 =   malloc((OUTPUT_CHANNELS[2] * INPUT_CHANNELS[2] * FILTER_LENGTH) * sizeof(float));
  ENC_F_3 =   malloc((OUTPUT_CHANNELS[3] * INPUT_CHANNELS[3] * FILTER_LENGTH) * sizeof(float));
  ENC_F_4 =   malloc((OUTPUT_CHANNELS[4] * INPUT_CHANNELS[4] * FILTER_LENGTH) * sizeof(float));
  ENC_F_5 =   malloc((OUTPUT_CHANNELS[5] * INPUT_CHANNELS[5] * FILTER_LENGTH) * sizeof(float));
  ENC_F_6 =   malloc((OUTPUT_CHANNELS[6] * INPUT_CHANNELS[6] * FILTER_LENGTH) * sizeof(float));
  ENC_F_7 =   malloc((OUTPUT_CHANNELS[7] * INPUT_CHANNELS[7] * FILTER_LENGTH) * sizeof(float));
  ENC_F_8 =   malloc((OUTPUT_CHANNELS[8] * INPUT_CHANNELS[8] * FILTER_LENGTH) * sizeof(float));
  ENC_F_9 =   malloc((OUTPUT_CHANNELS[9] * INPUT_CHANNELS[9] * FILTER_LENGTH) * sizeof(float));
  ENC_F_10 = malloc((OUTPUT_CHANNELS[10]* INPUT_CHANNELS[10] * FILTER_LENGTH) * sizeof(float));

  read_txt("parameters/enc_filter_0",FILTER_LENGTH*OUTPUT_CHANNELS[0]*INPUT_CHANNELS[0],ENC_F_0);
  read_txt("parameters/enc_filter_1",FILTER_LENGTH*OUTPUT_CHANNELS[1]*INPUT_CHANNELS[1],ENC_F_1);
  read_txt("parameters/enc_filter_2",FILTER_LENGTH*OUTPUT_CHANNELS[2]*INPUT_CHANNELS[2],ENC_F_2);
  read_txt("parameters/enc_filter_3",FILTER_LENGTH*OUTPUT_CHANNELS[3]*INPUT_CHANNELS[3],ENC_F_3);
  read_txt("parameters/enc_filter_4",FILTER_LENGTH*OUTPUT_CHANNELS[4]*INPUT_CHANNELS[4],ENC_F_4);
  read_txt("parameters/enc_filter_5",FILTER_LENGTH*OUTPUT_CHANNELS[5]*INPUT_CHANNELS[5],ENC_F_5);
  read_txt("parameters/enc_filter_6",FILTER_LENGTH*OUTPUT_CHANNELS[6]*INPUT_CHANNELS[6],ENC_F_6);
  read_txt("parameters/enc_filter_7",FILTER_LENGTH*OUTPUT_CHANNELS[7]*INPUT_CHANNELS[7],ENC_F_7);
  read_txt("parameters/enc_filter_8",FILTER_LENGTH*OUTPUT_CHANNELS[8]*INPUT_CHANNELS[8],ENC_F_8);
  read_txt("parameters/enc_filter_9",FILTER_LENGTH*OUTPUT_CHANNELS[9]*INPUT_CHANNELS[9],ENC_F_9);
  read_txt("parameters/enc_filter_10",FILTER_LENGTH*OUTPUT_CHANNELS[10]*INPUT_CHANNELS[10],ENC_F_10);

  ENC_b_0 =   malloc((OUTPUT_CHANNELS[0]) * sizeof(float));
  ENC_b_1 =   malloc((OUTPUT_CHANNELS[1]) * sizeof(float));
  ENC_b_2 =   malloc((OUTPUT_CHANNELS[2]) * sizeof(float));
  ENC_b_3 =   malloc((OUTPUT_CHANNELS[3]) * sizeof(float));
  ENC_b_4 =   malloc((OUTPUT_CHANNELS[4]) * sizeof(float));
  ENC_b_5 =   malloc((OUTPUT_CHANNELS[5]) * sizeof(float));
  ENC_b_6 =   malloc((OUTPUT_CHANNELS[6]) * sizeof(float));
  ENC_b_7 =   malloc((OUTPUT_CHANNELS[7]) * sizeof(float));
  ENC_b_8 =   malloc((OUTPUT_CHANNELS[8]) * sizeof(float));
  ENC_b_9 =   malloc((OUTPUT_CHANNELS[9]) * sizeof(float));
  ENC_b_10 = malloc((OUTPUT_CHANNELS[10]) * sizeof(float));

  read_txt("parameters/enc_bias_0",OUTPUT_CHANNELS[0],ENC_b_0);
  read_txt("parameters/enc_bias_1",OUTPUT_CHANNELS[1],ENC_b_1);
  read_txt("parameters/enc_bias_2",OUTPUT_CHANNELS[2],ENC_b_2);
  read_txt("parameters/enc_bias_3",OUTPUT_CHANNELS[3],ENC_b_3);
  read_txt("parameters/enc_bias_4",OUTPUT_CHANNELS[4],ENC_b_4);
  read_txt("parameters/enc_bias_5",OUTPUT_CHANNELS[5],ENC_b_5);
  read_txt("parameters/enc_bias_6",OUTPUT_CHANNELS[6],ENC_b_6);
  read_txt("parameters/enc_bias_7",OUTPUT_CHANNELS[7],ENC_b_7);
  read_txt("parameters/enc_bias_8",OUTPUT_CHANNELS[8],ENC_b_8);
  read_txt("parameters/enc_bias_9",OUTPUT_CHANNELS[9],ENC_b_9);
  read_txt("parameters/enc_bias_10",OUTPUT_CHANNELS[10],ENC_b_10);

  ENC_alpha_0 =   malloc((OUTPUT_CHANNELS[0]) * sizeof(float));
  ENC_alpha_1 =   malloc((OUTPUT_CHANNELS[1]) * sizeof(float));
  ENC_alpha_2 =   malloc((OUTPUT_CHANNELS[2]) * sizeof(float));
  ENC_alpha_3 =   malloc((OUTPUT_CHANNELS[3]) * sizeof(float));
  ENC_alpha_4 =   malloc((OUTPUT_CHANNELS[4]) * sizeof(float));
  ENC_alpha_5 =   malloc((OUTPUT_CHANNELS[5]) * sizeof(float));
  ENC_alpha_6 =   malloc((OUTPUT_CHANNELS[6]) * sizeof(float));
  ENC_alpha_7 =   malloc((OUTPUT_CHANNELS[7]) * sizeof(float));
  ENC_alpha_8 =   malloc((OUTPUT_CHANNELS[8]) * sizeof(float));
  ENC_alpha_9 =   malloc((OUTPUT_CHANNELS[9]) * sizeof(float));
  ENC_alpha_10 = malloc((OUTPUT_CHANNELS[10]) * sizeof(float));

  read_txt("parameters/enc_alpha_0",OUTPUT_CHANNELS[0],ENC_alpha_0);
  read_txt("parameters/enc_alpha_1",OUTPUT_CHANNELS[1],ENC_alpha_1);
  read_txt("parameters/enc_alpha_2",OUTPUT_CHANNELS[2],ENC_alpha_2);
  read_txt("parameters/enc_alpha_3",OUTPUT_CHANNELS[3],ENC_alpha_3);
  read_txt("parameters/enc_alpha_4",OUTPUT_CHANNELS[4],ENC_alpha_4);
  read_txt("parameters/enc_alpha_5",OUTPUT_CHANNELS[5],ENC_alpha_5);
  read_txt("parameters/enc_alpha_6",OUTPUT_CHANNELS[6],ENC_alpha_6);
  read_txt("parameters/enc_alpha_7",OUTPUT_CHANNELS[7],ENC_alpha_7);
  read_txt("parameters/enc_alpha_8",OUTPUT_CHANNELS[8],ENC_alpha_8);
  read_txt("parameters/enc_alpha_9",OUTPUT_CHANNELS[9],ENC_alpha_9);
  read_txt("parameters/enc_alpha_10",OUTPUT_CHANNELS[10],ENC_alpha_10);

// Encoder
// Pre-emphasis & Layer 1
  LOOP = 0;
  x_in_0 = malloc((INPUT_CHANNELS[LOOP] * INPUT_LENGTH[LOOP]) * sizeof(float));
  read_txt("parameters/p232_010_noisy_1_txt", 16384, x_in_0);
  preemph(x_in_0, INPUT_CHANNELS[LOOP] * INPUT_LENGTH[LOOP], coeff_preemph);
  x_out_0 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  skip_0 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));


  one_d_conv(INPUT_LENGTH[LOOP], INPUT_CHANNELS[LOOP], x_in_0, FILTER_LENGTH, OUTPUT_CHANNELS[LOOP],\
		  ENC_F_0,STRIDE, ENC_b_0, OUTPUT_LENGTH[LOOP], x_out_0);
  memcpy(skip_0, x_out_0, (OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP])*sizeof(float));
  prelu(x_out_0, OUTPUT_CHANNELS[LOOP], OUTPUT_LENGTH[LOOP], ENC_alpha_0);

// Layer 2
  LOOP = 1;
  x_out_1 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  skip_1 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  one_d_conv(INPUT_LENGTH[LOOP], INPUT_CHANNELS[LOOP], x_out_0, FILTER_LENGTH, OUTPUT_CHANNELS[LOOP],\
		  ENC_F_1,STRIDE, ENC_b_1, OUTPUT_LENGTH[LOOP], x_out_1);
  memcpy(skip_1, x_out_1, (OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP])*sizeof(float));
  prelu(x_out_1, OUTPUT_CHANNELS[LOOP], OUTPUT_LENGTH[LOOP], ENC_alpha_1);


// Layer 3
  LOOP = 2;
  x_out_2 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  skip_2 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  one_d_conv(INPUT_LENGTH[LOOP], INPUT_CHANNELS[LOOP], x_out_1, FILTER_LENGTH, OUTPUT_CHANNELS[LOOP],\
		  ENC_F_2,STRIDE, ENC_b_2, OUTPUT_LENGTH[LOOP], x_out_2);
  memcpy(skip_2, x_out_2, (OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP])*sizeof(float));
  prelu(x_out_2, OUTPUT_CHANNELS[LOOP], OUTPUT_LENGTH[LOOP], ENC_alpha_2);


// Layer 4
  LOOP = 3;
  x_out_3 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  skip_3 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  one_d_conv(INPUT_LENGTH[LOOP], INPUT_CHANNELS[LOOP], x_out_2, FILTER_LENGTH, OUTPUT_CHANNELS[LOOP],\
		  ENC_F_3,STRIDE, ENC_b_3, OUTPUT_LENGTH[LOOP], x_out_3);
  memcpy(skip_3, x_out_3, (OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP])*sizeof(float));
  prelu(x_out_3, OUTPUT_CHANNELS[LOOP], OUTPUT_LENGTH[LOOP], ENC_alpha_3);

// Layer 5
  LOOP = 4;
  x_out_4 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  skip_4 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  one_d_conv(INPUT_LENGTH[LOOP], INPUT_CHANNELS[LOOP], x_out_3, FILTER_LENGTH, OUTPUT_CHANNELS[LOOP],\
		  ENC_F_4,STRIDE, ENC_b_4, OUTPUT_LENGTH[LOOP], x_out_4);
  memcpy(skip_4, x_out_4, (OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP])*sizeof(float));
  prelu(x_out_4, OUTPUT_CHANNELS[LOOP], OUTPUT_LENGTH[LOOP], ENC_alpha_4);

// Layer 6
  LOOP = 5;
  x_out_5 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  skip_5 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  one_d_conv(INPUT_LENGTH[LOOP], INPUT_CHANNELS[LOOP], x_out_4, FILTER_LENGTH, OUTPUT_CHANNELS[LOOP],\
		  ENC_F_5,STRIDE, ENC_b_5, OUTPUT_LENGTH[LOOP], x_out_5);
  memcpy(skip_5, x_out_5, (OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP])*sizeof(float));
  prelu(x_out_5, OUTPUT_CHANNELS[LOOP], OUTPUT_LENGTH[LOOP], ENC_alpha_5);

// Layer 7
  LOOP = 6;
  x_out_6 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  skip_6 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  one_d_conv(INPUT_LENGTH[LOOP], INPUT_CHANNELS[LOOP], x_out_5, FILTER_LENGTH, OUTPUT_CHANNELS[LOOP],\
		  ENC_F_6,STRIDE, ENC_b_6, OUTPUT_LENGTH[LOOP], x_out_6);
  memcpy(skip_6, x_out_6, (OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP])*sizeof(float));
  prelu(x_out_6, OUTPUT_CHANNELS[LOOP], OUTPUT_LENGTH[LOOP], ENC_alpha_6);

// Layer 8
  LOOP = 7;
  x_out_7 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  skip_7 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  one_d_conv(INPUT_LENGTH[LOOP], INPUT_CHANNELS[LOOP], x_out_6, FILTER_LENGTH, OUTPUT_CHANNELS[LOOP],\
		  ENC_F_7,STRIDE, ENC_b_7, OUTPUT_LENGTH[LOOP], x_out_7);
  memcpy(skip_7, x_out_7, (OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP])*sizeof(float));
  prelu(x_out_7, OUTPUT_CHANNELS[LOOP], OUTPUT_LENGTH[LOOP], ENC_alpha_7);

// Layer 9
  LOOP = 8;
  x_out_8 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  skip_8 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  one_d_conv(INPUT_LENGTH[LOOP], INPUT_CHANNELS[LOOP], x_out_7, FILTER_LENGTH, OUTPUT_CHANNELS[LOOP],\
		  ENC_F_8,STRIDE, ENC_b_8, OUTPUT_LENGTH[LOOP], x_out_8);
  memcpy(skip_8, x_out_8, (OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP])*sizeof(float));
  prelu(x_out_8, OUTPUT_CHANNELS[LOOP], OUTPUT_LENGTH[LOOP], ENC_alpha_8);

// Layer 10
  LOOP = 9;
  x_out_9 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  skip_9 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  one_d_conv(INPUT_LENGTH[LOOP], INPUT_CHANNELS[LOOP], x_out_8, FILTER_LENGTH, OUTPUT_CHANNELS[LOOP],\
		  ENC_F_9,STRIDE, ENC_b_9, OUTPUT_LENGTH[LOOP], x_out_9);
  memcpy(skip_9, x_out_9, (OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP])*sizeof(float));
  prelu(x_out_9, OUTPUT_CHANNELS[LOOP], OUTPUT_LENGTH[LOOP], ENC_alpha_9);

// Layer 11
  LOOP = 10;
  x_out_10 = malloc((OUTPUT_CHANNELS[LOOP] * OUTPUT_LENGTH[LOOP]) * sizeof(float));
  one_d_conv(INPUT_LENGTH[LOOP], INPUT_CHANNELS[LOOP], x_out_9, FILTER_LENGTH, OUTPUT_CHANNELS[LOOP],\
		  ENC_F_10, STRIDE, ENC_b_10, OUTPUT_LENGTH[LOOP], x_out_10);
  prelu(x_out_10, OUTPUT_CHANNELS[LOOP], OUTPUT_LENGTH[LOOP], ENC_alpha_10);


// Filters for decoder

  DEC_in = malloc((DEC_INPUT_CHANNELS[0]*DEC_INPUT_LENGTH[0])*sizeof(float));
  DEC_out_0 = malloc((DEC_OUTPUT_LENGTH[0]*DEC_OUTPUT_CHANNELS[0])*sizeof(float));
  DEC_out_1 = malloc((DEC_OUTPUT_LENGTH[1]*DEC_OUTPUT_CHANNELS[1])*sizeof(float));
  DEC_out_2 = malloc((DEC_OUTPUT_LENGTH[2]*DEC_OUTPUT_CHANNELS[2])*sizeof(float));
  DEC_out_3 = malloc((DEC_OUTPUT_LENGTH[3]*DEC_OUTPUT_CHANNELS[3])*sizeof(float));
  DEC_out_4 = malloc((DEC_OUTPUT_LENGTH[4]*DEC_OUTPUT_CHANNELS[4])*sizeof(float));
  DEC_out_5 = malloc((DEC_OUTPUT_LENGTH[5]*DEC_OUTPUT_CHANNELS[5])*sizeof(float));
  DEC_out_6 = malloc((DEC_OUTPUT_LENGTH[6]*DEC_OUTPUT_CHANNELS[6])*sizeof(float));
  DEC_out_7 = malloc((DEC_OUTPUT_LENGTH[7]*DEC_OUTPUT_CHANNELS[7])*sizeof(float));
  DEC_out_8 = malloc((DEC_OUTPUT_LENGTH[8]*DEC_OUTPUT_CHANNELS[8])*sizeof(float));
  DEC_out_9 = malloc((DEC_OUTPUT_LENGTH[9]*DEC_OUTPUT_CHANNELS[9])*sizeof(float));
  DEC_out_10 = malloc((DEC_OUTPUT_LENGTH[10]*DEC_OUTPUT_CHANNELS[10])*sizeof(float));

  skipped_0 = malloc((DEC_OUTPUT_LENGTH[0]*2*DEC_OUTPUT_CHANNELS[0])*sizeof(float));
  skipped_1 = malloc((DEC_OUTPUT_LENGTH[1]*2*DEC_OUTPUT_CHANNELS[1])*sizeof(float));
  skipped_2 = malloc((DEC_OUTPUT_LENGTH[2]*2*DEC_OUTPUT_CHANNELS[2])*sizeof(float));
  skipped_3 = malloc((DEC_OUTPUT_LENGTH[3]*2*DEC_OUTPUT_CHANNELS[3])*sizeof(float));
  skipped_4 = malloc((DEC_OUTPUT_LENGTH[4]*2*DEC_OUTPUT_CHANNELS[4])*sizeof(float));
  skipped_5 = malloc((DEC_OUTPUT_LENGTH[5]*2*DEC_OUTPUT_CHANNELS[5])*sizeof(float));
  skipped_6 = malloc((DEC_OUTPUT_LENGTH[6]*2*DEC_OUTPUT_CHANNELS[6])*sizeof(float));
  skipped_7 = malloc((DEC_OUTPUT_LENGTH[7]*2*DEC_OUTPUT_CHANNELS[7])*sizeof(float));
  skipped_8 = malloc((DEC_OUTPUT_LENGTH[8]*2*DEC_OUTPUT_CHANNELS[8])*sizeof(float));
  skipped_9 = malloc((DEC_OUTPUT_LENGTH[9]*2*DEC_OUTPUT_CHANNELS[9])*sizeof(float));
  
  DEC_F_0 = malloc((DEC_OUTPUT_CHANNELS[0]*DEC_INPUT_CHANNELS[0]*FILTER_LENGTH)*sizeof(float));
  DEC_F_1 = malloc((DEC_OUTPUT_CHANNELS[1]*(2*DEC_INPUT_CHANNELS[1])*FILTER_LENGTH)*sizeof(float));
  DEC_F_2 = malloc((DEC_OUTPUT_CHANNELS[2]*(2*DEC_INPUT_CHANNELS[2])*FILTER_LENGTH)*sizeof(float));
  DEC_F_3 = malloc((DEC_OUTPUT_CHANNELS[3]*(2*DEC_INPUT_CHANNELS[3])*FILTER_LENGTH)*sizeof(float));
  DEC_F_4 = malloc((DEC_OUTPUT_CHANNELS[4]*(2*DEC_INPUT_CHANNELS[4])*FILTER_LENGTH)*sizeof(float));
  DEC_F_5 = malloc((DEC_OUTPUT_CHANNELS[5]*(2*DEC_INPUT_CHANNELS[5])*FILTER_LENGTH)*sizeof(float));
  DEC_F_6 = malloc((DEC_OUTPUT_CHANNELS[6]*(2*DEC_INPUT_CHANNELS[6])*FILTER_LENGTH)*sizeof(float));
  DEC_F_7 = malloc((DEC_OUTPUT_CHANNELS[7]*(2*DEC_INPUT_CHANNELS[7])*FILTER_LENGTH)*sizeof(float));
  DEC_F_8 = malloc((DEC_OUTPUT_CHANNELS[8]*(2*DEC_INPUT_CHANNELS[8])*FILTER_LENGTH)*sizeof(float));
  DEC_F_9 = malloc((DEC_OUTPUT_CHANNELS[9]*(2*DEC_INPUT_CHANNELS[9])*FILTER_LENGTH)*sizeof(float));
  DEC_F_10 = malloc((DEC_OUTPUT_CHANNELS[10]*(2*DEC_INPUT_CHANNELS[10])*FILTER_LENGTH)*sizeof(float));

  read_txt("parameters/dec_filter_0",FILTER_LENGTH*DEC_OUTPUT_CHANNELS[0]*DEC_INPUT_CHANNELS[0],DEC_F_0);
  read_txt("parameters/dec_filter_1",FILTER_LENGTH*DEC_OUTPUT_CHANNELS[1]*(2*DEC_INPUT_CHANNELS[1]),DEC_F_1);
  read_txt("parameters/dec_filter_2",FILTER_LENGTH*DEC_OUTPUT_CHANNELS[2]*(2*DEC_INPUT_CHANNELS[2]),DEC_F_2);
  read_txt("parameters/dec_filter_3",FILTER_LENGTH*DEC_OUTPUT_CHANNELS[3]*(2*DEC_INPUT_CHANNELS[3]),DEC_F_3);
  read_txt("parameters/dec_filter_4",FILTER_LENGTH*DEC_OUTPUT_CHANNELS[4]*(2*DEC_INPUT_CHANNELS[4]),DEC_F_4);
  read_txt("parameters/dec_filter_5",FILTER_LENGTH*DEC_OUTPUT_CHANNELS[5]*(2*DEC_INPUT_CHANNELS[5]),DEC_F_5);
  read_txt("parameters/dec_filter_6",FILTER_LENGTH*DEC_OUTPUT_CHANNELS[6]*(2*DEC_INPUT_CHANNELS[6]),DEC_F_6);
  read_txt("parameters/dec_filter_7",FILTER_LENGTH*DEC_OUTPUT_CHANNELS[7]*(2*DEC_INPUT_CHANNELS[7]),DEC_F_7);
  read_txt("parameters/dec_filter_8",FILTER_LENGTH*DEC_OUTPUT_CHANNELS[8]*(2*DEC_INPUT_CHANNELS[8]),DEC_F_8);
  read_txt("parameters/dec_filter_9",FILTER_LENGTH*DEC_OUTPUT_CHANNELS[9]*(2*DEC_INPUT_CHANNELS[9]),DEC_F_9);
  read_txt("parameters/dec_filter_10",FILTER_LENGTH*DEC_OUTPUT_CHANNELS[10]*(2*DEC_INPUT_CHANNELS[10]),DEC_F_10);

  DEC_b_0 = malloc(DEC_OUTPUT_CHANNELS[0]*sizeof(float));
  DEC_b_1 = malloc(DEC_OUTPUT_CHANNELS[1]*sizeof(float));
  DEC_b_2 = malloc(DEC_OUTPUT_CHANNELS[2]*sizeof(float));
  DEC_b_3 = malloc(DEC_OUTPUT_CHANNELS[3]*sizeof(float));
  DEC_b_4 = malloc(DEC_OUTPUT_CHANNELS[4]*sizeof(float));
  DEC_b_5 = malloc(DEC_OUTPUT_CHANNELS[5]*sizeof(float));
  DEC_b_6 = malloc(DEC_OUTPUT_CHANNELS[6]*sizeof(float));
  DEC_b_7 = malloc(DEC_OUTPUT_CHANNELS[7]*sizeof(float));
  DEC_b_8 = malloc(DEC_OUTPUT_CHANNELS[8]*sizeof(float));
  DEC_b_9 = malloc(DEC_OUTPUT_CHANNELS[9]*sizeof(float));
  DEC_b_10 = malloc(DEC_OUTPUT_CHANNELS[10]*sizeof(float));

  read_txt("parameters/dec_bias_0",DEC_OUTPUT_CHANNELS[0],DEC_b_0);
  read_txt("parameters/dec_bias_1",DEC_OUTPUT_CHANNELS[1],DEC_b_1);
  read_txt("parameters/dec_bias_2",DEC_OUTPUT_CHANNELS[2],DEC_b_2);
  read_txt("parameters/dec_bias_3",DEC_OUTPUT_CHANNELS[3],DEC_b_3);
  read_txt("parameters/dec_bias_4",DEC_OUTPUT_CHANNELS[4],DEC_b_4);
  read_txt("parameters/dec_bias_5",DEC_OUTPUT_CHANNELS[5],DEC_b_5);
  read_txt("parameters/dec_bias_6",DEC_OUTPUT_CHANNELS[6],DEC_b_6);
  read_txt("parameters/dec_bias_7",DEC_OUTPUT_CHANNELS[7],DEC_b_7);
  read_txt("parameters/dec_bias_8",DEC_OUTPUT_CHANNELS[8],DEC_b_8);
  read_txt("parameters/dec_bias_9",DEC_OUTPUT_CHANNELS[9],DEC_b_9);
  read_txt("parameters/dec_bias_10",DEC_OUTPUT_CHANNELS[10],DEC_b_10);

  DEC_alpha_0 = malloc(DEC_OUTPUT_CHANNELS[0]*sizeof(float));
  DEC_alpha_1 = malloc(DEC_OUTPUT_CHANNELS[1]*sizeof(float));
  DEC_alpha_2 = malloc(DEC_OUTPUT_CHANNELS[2]*sizeof(float));
  DEC_alpha_3 = malloc(DEC_OUTPUT_CHANNELS[3]*sizeof(float));
  DEC_alpha_4 = malloc(DEC_OUTPUT_CHANNELS[4]*sizeof(float));
  DEC_alpha_5 = malloc(DEC_OUTPUT_CHANNELS[5]*sizeof(float));
  DEC_alpha_6 = malloc(DEC_OUTPUT_CHANNELS[6]*sizeof(float));
  DEC_alpha_7 = malloc(DEC_OUTPUT_CHANNELS[7]*sizeof(float));
  DEC_alpha_8 = malloc(DEC_OUTPUT_CHANNELS[8]*sizeof(float));
  DEC_alpha_9 = malloc(DEC_OUTPUT_CHANNELS[9]*sizeof(float));
  DEC_alpha_10 = malloc(DEC_OUTPUT_CHANNELS[10]*sizeof(float));

  read_txt("parameters/dec_alpha_0",DEC_OUTPUT_CHANNELS[0],DEC_alpha_0);
  read_txt("parameters/dec_alpha_1",DEC_OUTPUT_CHANNELS[1],DEC_alpha_1);
  read_txt("parameters/dec_alpha_2",DEC_OUTPUT_CHANNELS[2],DEC_alpha_2);
  read_txt("parameters/dec_alpha_3",DEC_OUTPUT_CHANNELS[3],DEC_alpha_3);
  read_txt("parameters/dec_alpha_4",DEC_OUTPUT_CHANNELS[4],DEC_alpha_4);
  read_txt("parameters/dec_alpha_5",DEC_OUTPUT_CHANNELS[5],DEC_alpha_5);
  read_txt("parameters/dec_alpha_6",DEC_OUTPUT_CHANNELS[6],DEC_alpha_6);
  read_txt("parameters/dec_alpha_7",DEC_OUTPUT_CHANNELS[7],DEC_alpha_7);
  read_txt("parameters/dec_alpha_8",DEC_OUTPUT_CHANNELS[8],DEC_alpha_8);
  read_txt("parameters/dec_alpha_9",DEC_OUTPUT_CHANNELS[9],DEC_alpha_9);

// Decoder
// Layer 1
  DEC_LOOP = 0;
  one_d_deconv(DEC_INPUT_LENGTH[DEC_LOOP], DEC_INPUT_CHANNELS[DEC_LOOP], x_out_10, FILTER_LENGTH,\
		  DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_F_0,STRIDE, DEC_b_0, DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_0);
  prelu(DEC_out_0, DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_alpha_0);
  skip_connection_2d(DEC_OUTPUT_CHANNELS[DEC_LOOP],DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_0, skip_9, skipped_0);

// Layer 2
  DEC_LOOP = 1;
  one_d_deconv(DEC_INPUT_LENGTH[DEC_LOOP], 2*DEC_INPUT_CHANNELS[DEC_LOOP], skipped_0, FILTER_LENGTH,\
		  DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_F_1, STRIDE,DEC_b_1, DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_1);
  prelu(DEC_out_1, DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_alpha_1);
  skip_connection_2d(DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_1, skip_8, skipped_1);

// Layer 3
  DEC_LOOP = 2;
  one_d_deconv(DEC_INPUT_LENGTH[DEC_LOOP], 2*DEC_INPUT_CHANNELS[DEC_LOOP], skipped_1, FILTER_LENGTH,\
		  DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_F_2, STRIDE,DEC_b_2, DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_2);
  prelu(DEC_out_2, DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_alpha_2);
  skip_connection_2d(DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_2, skip_7, skipped_2);

// Layer 4
  DEC_LOOP = 3;

  one_d_deconv(DEC_INPUT_LENGTH[DEC_LOOP], 2*DEC_INPUT_CHANNELS[DEC_LOOP], skipped_2, FILTER_LENGTH,\
		  DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_F_3,STRIDE,DEC_b_3, DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_3);
  prelu(DEC_out_3, DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_alpha_3);
  skip_connection_2d(DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_3, skip_6, skipped_3);

// Layer 5
  DEC_LOOP = 4;
  one_d_deconv(DEC_INPUT_LENGTH[DEC_LOOP],2*DEC_INPUT_CHANNELS[DEC_LOOP],skipped_3,FILTER_LENGTH,\
		  DEC_OUTPUT_CHANNELS[DEC_LOOP],DEC_F_4,STRIDE,DEC_b_4,DEC_OUTPUT_LENGTH[DEC_LOOP],DEC_out_4);
  prelu(DEC_out_4, DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_alpha_4);
  skip_connection_2d(DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_4, skip_5, skipped_4);

// Layer 6
  DEC_LOOP = 5;
  one_d_deconv(DEC_INPUT_LENGTH[DEC_LOOP],2*DEC_INPUT_CHANNELS[DEC_LOOP],skipped_4,FILTER_LENGTH,\
		  DEC_OUTPUT_CHANNELS[DEC_LOOP],DEC_F_5,STRIDE,DEC_b_5,DEC_OUTPUT_LENGTH[DEC_LOOP],DEC_out_5);
  prelu(DEC_out_5, DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_alpha_5);
  skip_connection_2d(DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_5, skip_4, skipped_5);

// Layer 7
  DEC_LOOP = 6;
  one_d_deconv(DEC_INPUT_LENGTH[DEC_LOOP],2*DEC_INPUT_CHANNELS[DEC_LOOP],skipped_5,FILTER_LENGTH,\
		  DEC_OUTPUT_CHANNELS[DEC_LOOP],DEC_F_6,STRIDE,DEC_b_6,DEC_OUTPUT_LENGTH[DEC_LOOP],DEC_out_6);
  prelu(DEC_out_6, DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_alpha_6);
  skip_connection_2d(DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_6, skip_3, skipped_6);

// Layer 8
  DEC_LOOP = 7;
  one_d_deconv(DEC_INPUT_LENGTH[DEC_LOOP],2*DEC_INPUT_CHANNELS[DEC_LOOP],skipped_6,FILTER_LENGTH,\
		  DEC_OUTPUT_CHANNELS[DEC_LOOP],DEC_F_7,STRIDE,DEC_b_7,DEC_OUTPUT_LENGTH[DEC_LOOP],DEC_out_7);
  prelu(DEC_out_7, DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_alpha_7);
  skip_connection_2d(DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_7, skip_2, skipped_7);

// Layer 9
  DEC_LOOP = 8;
  one_d_deconv(DEC_INPUT_LENGTH[DEC_LOOP],2*DEC_INPUT_CHANNELS[DEC_LOOP],skipped_7,FILTER_LENGTH,\
		  DEC_OUTPUT_CHANNELS[DEC_LOOP],DEC_F_8,STRIDE,DEC_b_8,DEC_OUTPUT_LENGTH[DEC_LOOP],DEC_out_8);
  prelu(DEC_out_8, DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_alpha_8);
  skip_connection_2d(DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_8, skip_1, skipped_8);

// Layer 10
  DEC_LOOP = 9;
  one_d_deconv(DEC_INPUT_LENGTH[DEC_LOOP],2*DEC_INPUT_CHANNELS[DEC_LOOP],skipped_8,FILTER_LENGTH,\
		  DEC_OUTPUT_CHANNELS[DEC_LOOP],DEC_F_9,STRIDE,DEC_b_9,DEC_OUTPUT_LENGTH[DEC_LOOP],DEC_out_9);
  prelu(DEC_out_9, DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_alpha_9);
  skip_connection_2d(DEC_OUTPUT_CHANNELS[DEC_LOOP], DEC_OUTPUT_LENGTH[DEC_LOOP], DEC_out_9, skip_0, skipped_9);

// Layer 11
  DEC_LOOP = 10;
  one_d_deconv(DEC_INPUT_LENGTH[DEC_LOOP],2*DEC_INPUT_CHANNELS[DEC_LOOP],skipped_9,FILTER_LENGTH,\
		  DEC_OUTPUT_CHANNELS[DEC_LOOP],DEC_F_10,STRIDE,DEC_b_10,DEC_OUTPUT_LENGTH[DEC_LOOP],DEC_out_10);

// Output activation (tanh)
  for (int i = 0; i<DEC_OUTPUT_CHANNELS[DEC_LOOP]*DEC_OUTPUT_LENGTH[DEC_LOOP]; i++){
    DEC_out_10[i] = tanh(DEC_out_10[i]);
  }

// De-emphasis
  deemph(DEC_out_10, DEC_OUTPUT_CHANNELS[DEC_LOOP]*DEC_OUTPUT_LENGTH[DEC_LOOP], coeff_preemph);

  for (int i = 0; i<DEC_OUTPUT_CHANNELS[DEC_LOOP]*DEC_OUTPUT_LENGTH[DEC_LOOP]; i++){
    printf("%5.18f\n", DEC_out_10[i]);
  }
}
