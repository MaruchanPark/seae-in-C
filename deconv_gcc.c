// 1-d fractional strided convolution
// Coded 2018.2.1 by Maruchan Park
// Only works at STRIDE = 2 , outputlength = inputlength/STRIDE, F>2

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "header.h"

void one_d_deconv(int N,int D_INPUT,float* x,int F,int D ,float* W,int S,float* b, int O, float* out){
  // FRACTIONAL STRIDED CONVOLUTION RETURNS DECONVED

  printf("%i INPUT LENGTH, %i INPUT CHANNELS \n", N, D_INPUT);
  float* deconved;
  deconved = malloc((D*(F+(N-1)*S))*sizeof(float));
  for (int i = 0; i<D; i++){
    for (int j = 0; j<D_INPUT; j++){
      for (int k = 0; k<N; k++){
        for (int u = 0; u<F; u++){ // FILTER LOOP
          deconved[i*(F+(N-1)*S) + (k*S) + u] = deconved[i*(F+(N-1)*S) + (k*S)+u] + x[j*N + k]*W[i*D_INPUT*F + j*F + u];
        }
      }
    }
  }
  
  if (F-S < 2){
    for (int i =0; i<D; i++){
      for (int j =0; j<N*S; j++){
        out[i*(N*S) + j] = deconved[i*(F+(N-1)*S) + j ]+b[i];
      }
    }
  }
    
  else {
    for (int i =0; i<D; i++){
      for (int j =0; j<N*S; j++){
        out[i*(N*S) + j] = deconved[i*(F+(N-1)*S) + (j + ((F-S)/2))]+b[i];
      }
    }
  }

}


