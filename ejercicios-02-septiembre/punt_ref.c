#include <stdio.h>

// vamos a crear una algoritmo que sólo sea una ejecución de pasos, no retorne nada
void swap(int *a, int *b) { // swap va a intercambiar los
    int temp = *a;
    *a = *b;
    *b = temp;
}

// acá definimos las variables que queremos intercambiar
int main() {
    int x = 10, y = 20;

    swap(&x, &y);

    printf("x: %d, y: %d\n", x, y);

    return 0;
}