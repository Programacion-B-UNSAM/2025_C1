/*
    Se quiere conocer el tamaño maximo para n, que se puede asignar dinamicamente a
    __uint32_t lista[n] 
    antes de obtener un error.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long long i = 1;
    __uint32_t* lista = malloc(sizeof(__uint32_t));

    if (lista == NULL) {
        perror("Error de asignación de memoria");
        return (1);
    }
    while (1) {
        lista = realloc(lista, sizeof(__uint32_t) * i);
        if (lista == NULL) {
            break;
        }
        i *= 2;
    }

    printf("\nTamaño final de la lista: %llu ", i / 2);

    return 0;
}