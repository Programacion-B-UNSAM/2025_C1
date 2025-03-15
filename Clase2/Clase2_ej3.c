/*
  1) Pida al usuario ingresar un número entero decimal
  2) Convierta y muestre el número en sus representaciones:
        binaria
        hexadecimal
        BCD
*/

#include <stdio.h>
#include <string.h>

int main() {
    long numOriginal, aux;
    char numHex[16];
    int numBCD[164];

    printf("\n\nNúmero original: ");
    scanf("%ld", &numOriginal);
    while (getchar() != '\n')
        ; /* Limpia el buffer de entrada para evitar problemas con fgets */

    // Pasaje a binario
    printf("\nNúmero binario:\t\t");
    for (int i = 31; i >= 0; i--) {
        printf("%ld", (numOriginal >> i) & 1);
    }

    // Pasaje a hexadecimal
    aux = numOriginal;
    printf("\nNúmero hexadecimal:\t");
    if (aux == 0) {
        printf("0");
    } else {
        int i = 0;
        while (aux > 0) {
            if ((aux % 16) < 10) {
                numHex[i] = (aux % 16) + '0';
            } else {
                numHex[i] = (aux % 16) - 10 + 'A';
            }
            i++;
            aux /= 16;
        }
        for (i; i >= 0; i--) {
            printf("%c", numHex[i - 1]);
        }
    }

    // Pasaje a BCD
    printf("\nNúmero BCD:\t\t");
    aux = numOriginal;
    int i = 0, j = 0;

    while (aux > 0) {
        numBCD[j++] = aux % 10;
        aux /= 10;
    }
    for (j--; j >= 0; j--) {
        for (i = 3; i >= 0; i--) {
            printf("%d", (numBCD[j] >> i) & 1);
        }
        printf(" ");
    }

    return 0;
}
