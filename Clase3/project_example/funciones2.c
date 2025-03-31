
#include <stdio.h>

extern int global_int;
void print_func2(){

  printf("\n\nEstoy en funciones 2 :happyFace:\n\n");

  global_int = 0;
  printf("\n Now global int is 0\n");
}