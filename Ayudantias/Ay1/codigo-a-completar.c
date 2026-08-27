#include <stdio.h>

int main(){
    int c, ele;

    printf("Ingresa una opción (1-4) y luego presiona ENTER: ");
    ele = getchar() -'0';
    getchar();

    printf("Ingresa un número: ");
    if((c = getchar()) != EOF) {
        printf("El valor antes de operar es: %d\n", c);
    }

    if (ele == 1) {
        c = c+2;
    }
    if (ele == 2) {
        c = c-2;
    }
    if (ele == 3) {
        c = c>>1;
    }
    if (ele == 4) {
        c = c-'a';
    }
    if (ele == 5) {
        c ^ 0b01010101;
    }

    printf("El valor final es: ");
    if (ele == 4 || ele == 5) {
        printf("%d\n", c); // imprime el valor numérico
    } else {
        printf("%c (ASCII: %d)\n", c, c);
    }
    return 0;
}