/*
    Se quiere leer un archivo con n numeros para luego guardarlos en un vector, este debe modificar su tamaño en cada lectura.
    Imprima el tamaño final de la lista.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file;
    int i = 0, temp;

    file = fopen("lista.bin", "rb+");
    if (file == NULL) {
        perror("Error al abrir el archivo");
    }

    while (fread(&temp, sizeof(int), 1, file)) {
        i++;
    }

    rewind(file);
    int* lista = malloc(sizeof(int) * i);

    if (lista == NULL) {
        perror("Error de asignación de memoria");
    }
    i = 0;

    while (fread(&lista[i], sizeof(int), 1, file)) {
        i++;
    }

    printf("\nTamaño de la lista: %d ", i);
    fclose(file);
    free(lista);

    return 0;
}

int main() {
    FILE* file;
    int i = 0;

    file = fopen("lista.bin", "rb+");
    if (file == NULL) {
        perror("Error al abrir el archivo");
    }

    int* lista = malloc(sizeof(int));
    if (lista == NULL) {
        perror("Error de asignación de memoria");
    }

    while (fread(&lista[i], sizeof(int), 1, file)) {
        i++;
        lista = realloc(lista, (i + 1) * sizeof(int));
    }

    printf("\nTamaño de la lista: %d ", i);
    fclose(file);
    free(lista);

    return 0;
}
