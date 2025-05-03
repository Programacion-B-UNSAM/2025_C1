#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include.h"
#include "lista.h"

void GetAverage(FILE* file, unsigned long* promedio);
void GetClosest(FILE* file, unsigned long promedio);

uint8_t SearchType = NoDocente;
uint8_t SearchStatus = Expirado;

int main() {
    FILE* file;
    unsigned long promedio;

    const char* filename = "credenciales.bin";
    file = fopen(filename, "rb+");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    GetAverage(file, &promedio);
    GetClosest(file, promedio);

    fclose(file);
    return (0);
}

void GetAverage(FILE* file, unsigned long* promedio) {
    Usuario_t user;
    unsigned int cantidad = 0;

    rewind(file);
    for (int i = 0; i < 1000; i++) {
        fread(&user, sizeof(Usuario_t), 1, file);
        if (user.TipoStatus != ((SearchType << 4) | SearchStatus)) {
            continue;
        }
        *promedio += user.DNI;
        cantidad++;
    }

    *promedio /= cantidad;
    printf("\nDni promedio: %lu", *promedio);
    printf("\nCantidad:     %u", cantidad);
}

void GetClosest(FILE* file, unsigned long promedio) {
    Usuario_t user, tempUser;
    unsigned int distancia = UINT32_MAX;

    rewind(file);
    for (int i = 0; i < 1000; i++) {
        fread(&user, sizeof(Usuario_t), 1, file);
        if (user.TipoStatus != ((SearchType << 4) | SearchStatus)) {
            continue;
        }

        if (user.DNI > promedio) {
            if (distancia > (user.DNI - promedio)) {
                distancia = (user.DNI - promedio);
                tempUser = user;
            }
        } else {
            if (distancia > (promedio - user.DNI)) {
                distancia = (promedio - user.DNI);
                tempUser = user;
            }
        }
    }
    printf("\n\n%s, DNI: %d\n\n", tempUser.Name, tempUser.DNI);
}
