#include <stdio.h>

#define max 10
int indices[max] = {0};

int comprobacion(char *cadena);

comprobacion(char *cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        i++;
        printf("El valor del puntero es: %c\n", *cadena);
        if (*cadena != 'A' || *cadena != 'G' || *cadena != 'C' || *cadena != 'T') {
            return 1;
        }
        cadena++;
    }
    if (!i) {
        return 1;
    }
    return 0;
}

int iguales(char *cadena, char *comp) {
    while (*cadena == *comp) {
        if (*cadena == '\0' || *comp == '\0') {
            return 1;
        }
        cadena++;
        comp++;
    }
    return 1;
}

