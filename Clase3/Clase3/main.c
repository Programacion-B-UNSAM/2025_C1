#include <stdio.h>
#include <string.h>
#include "header.h"

unsigned long long nroRecurrenciasFibonacci;

int main(void) {
#ifdef Ej1
    Saludo();
#endif
#ifdef Ej2
    int start, stop;
    printf("\nComienzo del intervalo: \t");
    scanf("%d", &start);
    printf("\nFin del intervalo: \t");
    scanf("%d", &stop);
    Armstrong(start, stop);
#endif
#ifdef Ej3
    nroRecurrenciasFibonacci = 0;
    int nroIter;
    printf("\nIngrese el numero de iteraciones: \t");
    scanf("%d", &nroIter);
    printf("El %d de la secuencia de Fibonacci es : \t%lld", nroIter, Fibonacci(nroIter));
    printf("\nPara esta sucecion se llamo a la funcion %lld veces", nroRecurrenciasFibonacci);
#endif
    printf("\n\n");
    return 0;
}