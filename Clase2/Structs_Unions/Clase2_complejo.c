#include <stdint.h>
#include <stdio.h>

/*
1- Piense una estructura para guardar los datos bancarios de una persona, estos son:
    - Nombre (max 20 caracteres)
    - nroCuenta
    - En caso de ser Argentino D.N.I. (10 digitos)
    - En caso de no ser Argentino Pasaporte (12 digitos)
Utilize la menor cantidad de memoria posible

2- Inicalize los datos e imprima los valores

*/
typedef struct {
    char nombre[20];
    int nroCuenta;
    short esArg;

    union id {
        long pasaporte;
        int dni;
    } id;
} datos_bancarios_t;

int main() {
    datos_bancarios_t persona1 = {
        .nombre = "Juan",
        .nroCuenta = 1230,
        .esArg = 1,
        .id.dni = 40085741,
    };

    printf("\n\n");

    printf("Nombre:           %s\n", persona1.nombre);
    printf("Numero de Cuenta: %d\n", persona1.nroCuenta);
    printf("DNI:              %d\n", persona1.id.dni);

    persona1.id.pasaporte = 12345678901234;

    printf("Pasaporte:        %lu \n", persona1.id.pasaporte);
    printf("DNI:              %d  \n", persona1.id.dni);

    printf("\n\n");
    return 0;
}