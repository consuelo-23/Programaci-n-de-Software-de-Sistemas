#include <stdio.h> // entrada y salida de datos

unsigned char encender_bit(unsigned char num, int pos) { //retorno positivo, char reune un byte; las llaves definen el scope
    return num | (1 << pos); //or pq quiero encender un bit
}

//consultar si un bit está encendido
int consultar_bit(unsigned char num, int pos) {
    return (num >> pos) & 1;
}

int main() {
    unsigned char valor = 0;
    
    unsigned char pos = 3;
    valor = encender_bit(valor, pos);
    printf("Nuevo valor: %d\n", valor); // porcentaje para llamar a la variable decimal

    printf("Bit en posición %d: %d\n", pos, consultar_bit(valor, pos));

    return 0;
}