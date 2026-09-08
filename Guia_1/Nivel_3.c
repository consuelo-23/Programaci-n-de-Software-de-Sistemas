#include <stdio.h>

unsigned char a = 75;
unsigned char b = 43;
signed char c = -12;

int main() {
    int pos = 1;
    int mascara = 1<<pos;
    int light_1_c = c | mascara;
    printf("c: %d, y encendiendo el bit en la posición 1: %d\n", c, light_1_c);

    int pos2 = 5;
    int masc2 = ~(1<<pos2);
    int off = c & masc2;
    printf("c: %d, y encendiendo el bit en la posición 5: %d\n", c, off);

    int pos3 = 2;
    int consulta = (c>>pos3) & 1;
    printf("consultando el bit en la posición 2 de c: %d, estaba: %d\n", c, consulta);

    return 0;
}