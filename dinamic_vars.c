#include <stdio.h>
#include <stdlib.h>

int main() {
    int *puntero = (int *)malloc(sizeof(int));

    *puntero = 42;
    printf("EL valor dinámico es %d\n", *puntero);
    free(puntero);
    return 0;
}