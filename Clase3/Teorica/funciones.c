/* En este archivo colocaremos todas las definiciones de nuestras funciones */
#include "header.h"
#include <stdio.h>
long long power(long long a){
  static int how_many_times = 0;
  long long pow = 1;
  for (int i = 0; i < POW; ++i){
    pow *=a;
  }
  how_many_times +=1;
  if (how_many_times > 10){
    printf("You are using this function a lot!\n");
  }
  return pow;
}