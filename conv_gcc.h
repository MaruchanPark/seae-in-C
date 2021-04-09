// 1-d convolution
// Coded 2017.12.18 by Maruchan Park
// Only works at PADDING = SAME, STRIDE = 2
// THIS PROGRAM DOES NOT ROUND OUTPUT WHEN (INPUT LENGTH)/(STRIDE) IS ODD NUMBER

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void one_d_conv(int N,int D_INPUT,float* x,int F,int D ,float* W,int S,float* b, int O, float* out){
  int N_pad = N+F-S;
  int pad_occur;

  float* x_pad;
  float* par_out;


  x_pad = malloc((D_INPUT*N_pad)*sizeof(float));
  par_out = malloc((D*O)*sizeof(float));

  printf("%i OUT LENGTH\n", O);

  //PADDING ON INPUT
  printf("%i PADDING NUMBER \n", N_pad - N);

  if (N != N_pad){
    printf("PADDING APPLiED\n");
    pad_occur = 1;
    if ((N_pad - N) == 1){
      printf("ONE NUMBER PADDED\n");
      for (int i=0; i<D_INPUT; i++){
        x_pad[i*N_pad + N_pad-1] = 0.;
      }
      for (int i=0; i<D_INPUT; ++i){
        for (int j=0; j<N;j++){
          x_pad[i*N_pad + j] = x[i*N + j];
        }
      }
    }
    else{
      if ((N_pad - N) % 2 !=0){
        printf("ODD NUMBER PADDED\n");
        for (int i=0; i<D_INPUT; ++i){
          for (int j=0; j<(N_pad-N-1)/2; ++j){
            x_pad[i*N_pad + j] =0.; 
          }
        }

        for (int i=0; i<D_INPUT; ++i){
          for (int j=N_pad-1-(N_pad-N-1)/2; j<N_pad; ++j){
            x_pad[i*N_pad + j] = 0.;
          }
        }

        for (int i=0; i<D_INPUT; ++i){
          for (int j=0; j<N; ++j){
            x_pad[i*N_pad + (j+(N_pad-N-1)/2)] = x[i*N + j];
          }
        }
      }
      else{
        printf("EVEN NUMBER PADDED\n");

        for (int i=0; i<D_INPUT; ++i){
          for (int j=0; j<(N_pad-N)/2; ++j){
            x_pad[i*N_pad + j] = 0.;
          }
        }

        for (int i=0; i<D_INPUT; ++i){
          for (int j=N_pad-1-((N_pad-N)/2-1); j<N_pad; ++j){
            x_pad[i*N_pad + j] = 0.;
          }
        }

        for (int i=0; i<D_INPUT; ++i){
          for (int j=0; j<N; ++j){
            x_pad[i*N_pad + (j+(N_pad-N)/2)] = x[i*N + j];
          }
        }
      }
    }
  }
  else{
    pad_occur = 0;
    printf("NO PADDING\n");
  }

  int N_INPUT;
  if (pad_occur == 1){
    N_INPUT = N_pad;
  }
  else {
    N_INPUT = N;
  }

  float* INPUT;
  if (pad_occur == 1){
    INPUT = x_pad;
  }
  else {
    INPUT = x;
  }
  printf("INPUT\n");
  
  //PADDING DONE RETURN INPUT AND N_INPUT
  //Convolution
  int idx_start;
  idx_start = 0;

  for (int i = 0; i<D; ++i){
    for (int j = 0; j<D_INPUT; ++j){
      for (int k =0; k<O; ++k){
        idx_start = k*S;
        for (int u =0; u<F; ++u){
          par_out[i*O + k] = par_out[i*O +k] + INPUT[j*N_INPUT + (u+idx_start)]*W[i*D_INPUT*F + j*F + u];
        }
      }
    }
  }

  for (int i=0; i<D; ++i){
    for (int j=0; j<O; ++j){
      par_out[i*O + j] = par_out[i*O + j] + b[i];
      out[i*O + j] = par_out[i*O + j];
    }
  }
}


