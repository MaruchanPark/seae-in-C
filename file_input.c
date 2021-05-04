#include <stdlib.h>
#include <stdio.h>
#include "header.h"

void read_txt(char *file_name, int length, float *arr){
  FILE *f;
  float read;

  f = fopen(file_name, "r");

  for (int i = 0; i < length; i++){
    fscanf(f, "%f", &arr[i]);
  }
}

