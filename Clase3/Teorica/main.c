
/* Fecha 30/03/25
 * Autor : Felipe Soriano 
 * Este es el archivo principal donde escribiremos nuestro programa
 */


/* Includes */
#include <stdio.h>
#include "header.h"

/* Global variables */
int global_int = 100;


int main(void){

  long long result = 2;

  for (int i = 0; i < 11; ++i)
    result = power(result);

  printf("%lld <-- result\n", result);

  print_func2();

  printf("%d <-- this is global int", global_int);
  return 0;
}
