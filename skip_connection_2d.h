#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void skip_connection_2d(int dim1, int dim2, float *arr1, float *arr2, float *skip){
/*
  for (int i = 0; i<dim1; i++){
    for (int j = 0; j<dim2; j++){
      skip[dim2*2*i + j] = arr1[dim2*i + j];
      skip[dim2*2*i + j + dim2] = arr2[dim2*i + j]; 
    }
  }
*/
  for (int i = 0; i<dim1*2; i++){
    for (int j = 0; j<dim2; j++){
      if (i<dim1){
        skip[dim2*i + j] = arr1[dim2*i + j];
      }
      else{
        skip[dim2*i + j] = arr2[dim2*(i-dim1) + j]; 
      }
    }
  }
}
