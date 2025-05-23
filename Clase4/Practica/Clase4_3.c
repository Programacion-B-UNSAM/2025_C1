/*
1 - Implementar una función en C para imprimir los elementos de una lista de enteros.
2 - Implementar un algoritmo de ordenamiento simple en C.

Define una función llamada EasySort que reciba dos parámetros:
    Un puntero a un array de enteros (lista).
    Un entero que representa la longitud del array (longitud).

La función debe:
-Crear un array temporal para almacenar los elementos ordenados.
-Recorrer el array original y copiar los elementos en el array temporal en orden creciente.
es decir, iterativamente, encuentra el mínimo de los elementos restantes y se coloca en
la siguiente posición del array temporal.
-Finalmente, copiar los elementos del array temporal de vuelta al array original.
*/

#include <math.h>
#include <stdio.h>

#include "listas.h"

#define MAX_NUMBER 1000 /* Este valor debe ser actualizado de acuerdo al valor maximo de la lista que se quiera ordenar */

void mostrarLista(int *lista, int longitud);
void EasySort(int *lista, int longitud);
int main() {
    int size = sizeof(shortLista) / sizeof(shortLista)[0];

    printf("\nLista inicial: \n\t");
    mostrarLista(shortLista, size);

    printf("\nEasy Sort: \n\t");
    EasySort(shortLista, size);
    mostrarLista(shortLista, size);

    return 0;
}

void mostrarLista(int *lista, int longitud) {
    int i;

    for (i = 0; i < longitud; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void EasySort(int *lista, int longitud) {
    /* Atención! Este algoritmo no tiene en cuenta la posibilidad de que haya numeros repetidos */
    unsigned int i, j, temp[longitud], lastMin = 0, min = MAX_NUMBER;

    for (j = 0; j < longitud; j++) {
        min = MAX_NUMBER;
        for (i = 0; i < longitud; i++) {
            if ((lista[i] < min) && (lista[i] > lastMin))
                min = lista[i];
        }
        lastMin = min;
        temp[j] = min;
    }
    for (i = 0; i < longitud; i++) {
        lista[i] = temp[i];
    }
}