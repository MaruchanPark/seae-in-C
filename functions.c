#include <stdlib.h>
#include <stdio.h>
#include "header.h"


void preemph(float* preemph_input, int input_length ,float coeff){
// Only work with 1-d data
  float* diff;
  diff = malloc((input_length-1)*sizeof(float));

  for (int i = 0; i<input_length-1; i++){
    diff[i] = preemph_input[i+1]-coeff*preemph_input[i];
  }
  for (int i = 1; i<input_length-1; i++){
    preemph_input[i+1] = diff[i];
  }
  free(diff);
}

void deemph(float* deemph_input, int input_length, float coeff){
// Only work with 1-d data
  float* replace;
  replace = malloc(input_length*sizeof(float));
  
  replace[0] = deemph_input[0];

  for (int i = 1; i<input_length; i++){
    replace[i] = coeff * replace[i-1] + deemph_input[i];
  }

  for (int i = 0; i<input_length; i++){
    deemph_input[i] = replace[i];
  }
  free(replace);
}

void prelu(float* prelu_input, int input_channel, int input_length ,float* alpha){
  for (int i=0; i<input_channel; i++){
    for (int j=0; j<input_length; j++){
      if (prelu_input[i*input_length + j] > 0){
        prelu_input[i*input_length + j] = prelu_input[i*input_length +j];
      }
      else {
        prelu_input[i*input_length + j] = alpha[i] * prelu_input[i*input_length +j];
        
      }
    }
  }
}
