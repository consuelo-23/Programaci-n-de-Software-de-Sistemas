#include <stdio.h>

int main(){
    unsigned char numero1 = 45;
    unsigned char numero2 = 10; // dado que ambos son positivos

    unsigned char op_and = numero1 & numero2;
    unsigned char op_or = numero1 | numero2;

    printf("el resultado con operador AND es: %d\n", op_and);
    printf("el resultado con operador OR es: %d\n", op_or);
    return 0;
}