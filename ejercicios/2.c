#include <stdio.h> //librería

int main(){
    unsigned char numero1 = 120;
    signed char numero2 = -10;

    unsigned char op_xor = numero1 ^ numero2;
    unsigned char op_not1 = ~numero1;
    unsigned char op_not2 = ~numero2;

    printf("el resultado del operador XOR es: %d\n", op_xor);
    printf("el negativo del numero1 es: %d\n", op_not1);
    printf("el negativo del numero2 es: %d\n", op_not2);
    return 0;
}