/*
Se tiene un sensor que mide temperatura y humedad

    int datosSensor = 0b1001010111100010;
    los primeros 8 bits corresponden a los datos de temperatura
    los ultimos 8 bits corresponden a los datos de humedad

    Imprima los datos en pantalla

 */
#include <stdio.h>

int main() {
    int Humedad, Temperatura;
    int datosSensor = 0b1001010111100010;

    Humedad = datosSensor >> 8;
    Temperatura = datosSensor & 0b0000000011111111;

    printf("Temperatura : \t %d\n", Temperatura);
    printf("Humedad : \t %d\n", Humedad);

    return 0;
}