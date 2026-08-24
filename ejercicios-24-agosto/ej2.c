#include <stdio.h> //llamamos la librería para entradas y salidas

int main(){
    unsigned char numero1 = 45; //"si signo" es positivo
    signed char numero2 = -12; // "con signo" es negativo

        //char toma 1 byte, int toma 4 bytes
    unsigned char opr_and = numero1 & numero2;
    unsigned char opr_or = numero1 | numero2;
    printf("el valor de opr_and es : %d\n", opr_and); // %d dice dónde va el valor que va después de la coma
    printf("el valor de opr_or es : %d\n", opr_or);
}