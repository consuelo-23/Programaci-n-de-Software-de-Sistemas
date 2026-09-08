#include <stdio.h>
#include <stdlib.h>

/*funciones a ejecutar:
    - comprobar
    - largo
    
    #DEFINE MAX 64 --> reemplaza MAX en todo el código por 64
    */

#define MAX 64

char *xor(const char *x, const char *y, char *res) {
    int i;
    if (x == NULL || y == NULL || res == NULL) {
        return NULL;
    }

    for (i = 0; x[i] != '\0' && y[i] != '\0'; i++) {
        if (x[i] != '0' && x[i] != '1' || y[i] != '0' && y[i] != '1') {
            return NULL;
        }
        int a = x[i] - '0';
        int b = y[i] - '0';

        // falta definir el XOR

        int r = ((~a) & b) | (a & (~b)) &1;

        // condición ? valor : sino;
        res[i] = r ? '1': '0';

        if ((x[i] == '\0' && y[i] != '\0') || x[i] == '\0' && y[i] == '\0') {
            return NULL;
        }
        
    }
    res[i] = '\0';
    return res;
}

int main(void) {
    char a[MAX];
    char b[MAX];
    char resultado[MAX];

    printf("Ingrese la primera cadena binaria (sólo 0 y 1): ");
    scanf("%s", a);
    printf("Ingrese la segunda cadena binaria (sólo 0 y 1): ");
    scanf("%s", b);

    if (xor(a, b, resultado) == NULL) {
        printf("Entrada inválida: las cadenas deben tener el mismo largo y contener sólo 0s y 1s\n");
        return 1;
    }
    printf("xor = %s\n", resultado);
    return 0;
}
