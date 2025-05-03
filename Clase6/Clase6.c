#include <stdio.h>
#include <stdlib.h>

#include "definitions.h"

int main() {
    Nodo* PrimerNodo = NULL;

    insFirst(&PrimerNodo, 10);
    insFirst(&PrimerNodo, 20);
    insFirst(&PrimerNodo, 30);
    insFirst(&PrimerNodo, 40);
    insFirst(&PrimerNodo, 50);
    insFirst(&PrimerNodo, 60);
    insFirst(&PrimerNodo, 70);
    insFirst(&PrimerNodo, 80);

    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);

    delLast(&PrimerNodo);
    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);

    delLast(&PrimerNodo);
    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);

    delLast(&PrimerNodo);
    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);

    freeList(&PrimerNodo);

    printf("\nLista enlazada: \n\t");
    showFull(PrimerNodo);
    return 0;
}

Nodo* createNodo(int nuevoDato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("Error en la creacion del nodo\n");
        exit(1);
    }
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->next = NULL;
    return nuevoNodo;
}

void insFirst(Nodo** PrimerNodo, int nuevoDato) {
    Nodo* nuevoNodo = createNodo(nuevoDato);

    if (*PrimerNodo == NULL) {
        *PrimerNodo = nuevoNodo;
        return;
    }

    nuevoNodo->next = *PrimerNodo;
    *PrimerNodo = nuevoNodo;
}

void delLast(Nodo** PrimerNodo) {
    if (*PrimerNodo == NULL) {
        printf("La lista esta vacia");
        return;
    }
    if ((*PrimerNodo)->next == NULL) {
        free(*PrimerNodo);
        *PrimerNodo = NULL;
    }
    Nodo* actual = *PrimerNodo;
    Nodo* previo;

    while (actual->next != NULL) {
        previo = actual;
        actual = actual->next;
    }
    previo->next = NULL;
    free(actual);
}

void showFull(Nodo* PrimerNodo) {
    Nodo* actual = PrimerNodo;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->next;
    }
    printf("NULL\n");
}

void freeList(Nodo** PrimerNodo) {
    Nodo* current = *PrimerNodo;
    Nodo* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *PrimerNodo = NULL;
}
