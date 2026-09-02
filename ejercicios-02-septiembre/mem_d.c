#include <stdio.h>
#include <stdlib.h> // es el que trae malloc() y free()

// arreglo de 4 posiciones con valores de 10 en 10
int *arreglo_dinamico(int size) {
    int *arr = (int *)malloc(size * sizeof(int)); //va a calcular el tamaño que vamos a ocupar de memoria, int -> 4 bytes

    if (arr == NULL) {
        printf("no tení memoria");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1) * 10;
    }

    return arr;
}

int main() {
    int n = 4;
    int *mi_arreglo = arreglo_dinamico(n);

    if (mi_arreglo != NULL) {
        for (int i = 0; i < n; i++) {
            printf("%d, ", mi_arreglo[i]);
        }
        printf("\n");

        //falta liberar memoria
        free(mi_arreglo);
    }
    return 0;
}