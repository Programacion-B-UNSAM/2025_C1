/*
  Gestión de Reservas de un Restaurante

  Escriba un programa que gestione las reservas de un restaurante.
  Los datos deben manejarse a través de archivos binarios.
  Este debe constar de las siguientes opciones:

  1) Agregar reserva:
  Pida al usuario el nombre del cliente, la cantidad de personas y la fecha/hora de la reserva.
  Guarde la reserva en un archivo reservas.bin como un registro único.

  2) Mostrar reservas:
  Lea todas las reservas del archivo y muéstrelas en un formato legible.

  3) Modificar reserva:
  Pida al usuario el nombre del cliente cuya reserva desea modificar.
  Permita cambiar la cantidad de personas y/o la fecha/hora de la reserva.

  4) Eliminar reserva:
  Pida al usuario el nombre del cliente cuya reserva desea eliminar.
  Elimine la reserva correspondiente del archivo.

  5) Buscar reserva por fecha:
  Pida al usuario una fecha específica.
  Muestre todas las reservas correspondientes a esa fecha.
*/

#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    const char *filename = "reservas.bin";
    long pos;

    char cliente[20], fecha[15], cantidad[10], reserva[50];
    int opcion;

    size_t result = 1;
    int encontrado = 0;

    file = fopen(filename, "rb+"); /* Lee el archivo */
    if (file == NULL)
        perror("Error al abrir el archivo");

    do {
        printf("\n\nSeleccione una opcion\n");
        printf("\t1: Agregar reserva\n");
        printf("\t2: Mostrar reservas\n");
        printf("\t3: Modificar reserva\n");
        printf("\t4: Eliminar reserva\n");
        printf("\t5: Buscar reserva por fecha\n");
        printf("\t0: Cerrar programa\n");

        printf("\nOpcion: ");
        scanf("%d", &opcion);
        while (getchar() != '\n'); /* Limpia el buffer de entrada para evitar problemas con fgets */

        switch (opcion) {
            case 0:
                printf("\nCerrando archivo....");
                break;

            case 1:
                printf("\nIngrese el nombre: ");
                fgets(cliente, sizeof(cliente), stdin);
                cliente[strcspn(cliente, "\n")] = 0;

                printf("Ingrese la fecha (dd/mm/aaaa): ");
                fgets(fecha, sizeof(fecha), stdin);
                fecha[strcspn(fecha, "\n")] = 0;

                printf("Ingrese la cantidad de personas: ");
                fgets(cantidad, sizeof(cantidad), stdin);
                cantidad[strcspn(cantidad, "\n")] = 0;

                snprintf(reserva, sizeof(reserva), "%s - %s - %s", cliente, fecha, cantidad);

                fseek(file, 0, SEEK_END); /* Mover el puntero al final del archivo */
                fwrite(&reserva, sizeof(reserva), 1, file);

                printf("Reserva agregada correctamente.\n");
                break;

            case 2:
                rewind(file);
                while (fread(&reserva, sizeof(reserva), 1, file)) {
                    printf("%s \n", reserva);
                };
                break;

            case 3:
                printf("\nIngrese el nombre: ");
                fgets(cliente, sizeof(cliente), stdin);
                cliente[strcspn(cliente, "\n")] = 0;

                rewind(file);
                encontrado = 0;
                while (fread(&reserva, sizeof(reserva), 1, file)) {
                    if (strstr(reserva, cliente) != NULL) {
                        encontrado = 1;
                        pos = ftell(file) - sizeof(reserva); /* Guardar la posición para sobrescribir */
                        break;
                    }
                };
                if (encontrado) {
                    printf("Reserva anterior: %s\n", reserva);

                    printf("Nueva fecha (dd/mm/aaaa): ");
                    fgets(fecha, sizeof(fecha), stdin);
                    fecha[strcspn(fecha, "\n")] = 0;

                    printf("Nueva cantidad: ");
                    fgets(cantidad, sizeof(cantidad), stdin);
                    cantidad[strcspn(cantidad, "\n")] = 0;

                    snprintf(reserva, sizeof(reserva), "%s - %s - %s", cliente, fecha, cantidad);
                    fseek(file, pos, SEEK_SET); /* Salto a la posición para sobrescribir */
                    fwrite(&reserva, sizeof(reserva), 1, file);

                    printf("Nueva reserva: %s\n", reserva);
                } else
                    printf("No se encontro la reserva\n");

                break;

            case 4:
                printf("\nIngrese el nombre: ");
                fgets(cliente, sizeof(cliente), stdin);
                cliente[strcspn(cliente, "\n")] = 0;

                FILE *file_temp;

                file_temp = fopen("temp_reservas.bin", "wb");
                if (file_temp == NULL) {
                    perror("Error al crear el archivo temporal");
                    return 1;
                }
                rewind(file);

                while (fread(reserva, sizeof(reserva), 1, file)) {
                    if (strstr(reserva, cliente) != NULL) {
                        encontrado = 1;
                    } else {
                        fwrite(reserva, sizeof(reserva), 1, file_temp);
                    }
                }
                fclose(file);
                fclose(file_temp);

                if (encontrado) {
                    if (remove("reservas.bin") != 0) {
                        perror("Error al eliminar el archivo original");
                        return 1;
                    }

                    if (rename("temp_reservas.bin", "reservas.bin") != 0) {
                        perror("Error al renombrar el archivo temporal");
                        return 1;
                    }
                    printf("Reserva eliminada correctamente.\n");
                } else {
                    if (remove("temp_reservas.bin") != 0) {
                        perror("Error al eliminar el archivo original");
                        return 1;
                    }
                    printf("No se encontró ninguna reserva con ese nombre.\n");
                }

                file = fopen(filename, "rb+"); /* Lee el archivo */
                if (file == NULL)
                    perror("Error al abrir el archivo");

                break;

            case 5:
                printf("\nIngrese la fecha: ");
                fgets(fecha, sizeof(fecha), stdin);
                fecha[strcspn(fecha, "\n")] = 0;

                rewind(file);
                encontrado = 0;

                while (fread(&reserva, sizeof(reserva), 1, file)) {
                    if (strstr(reserva, fecha) != NULL) {
                        printf("Reserva: %s\n", reserva);
                        encontrado = 1;
                    }
                };
                if (!encontrado)
                    printf("No se encontró ninguna reserva para esa fecha.\n");
                break;

            default:
                printf("\nOpcion invalida\n");
                break;
        }
    } while (opcion != 0);

    fclose(file);
    return 0;
}
