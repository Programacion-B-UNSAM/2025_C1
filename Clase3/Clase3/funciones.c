#include <math.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

void Saludo() {
    char nombre[20];

    printf("\nIngrese el nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    printf("\nHola, %s! ", nombre);
}

void Armstrong(int Start, int Stop) {
    int i, aux, suma, nrDigitos;

    for (i = Start; i <= Stop; i++) {
        suma = 0;
        aux = i;
        nrDigitos = 0;
        while (aux > 0) {
            aux /= 10;
            nrDigitos++;
        }
        aux = i;
        // nrDigitos = log10(i) + 1;
        while (aux > 0) {
            suma += pow(aux % 10, nrDigitos);
            aux /= 10;
        }
        if (suma == i) {
            printf("%d\n", i);
        }
    }
}

unsigned long long Fibonacci(int num) {
    nroRecurrenciasFibonacci++;

    if (num == 0) {
        return 0;
    } else if (num == 1) {
        return 1;
    } else {
        return Fibonacci(num - 1) + Fibonacci(num - 2);
    }
}
