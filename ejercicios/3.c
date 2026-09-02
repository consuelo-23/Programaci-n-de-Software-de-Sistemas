#include <stdio.h>

int main(){
    //Usamos unsigned char (1byte = 8bits)
    unsigned char estado = 40;  //binario 0010 1000
    int pos = 3;

    printf("Estado inicial: %d (Binario: 0010 1000)\n", estado);

    // Parte 1: desplazamiento a la izquierda
    printf("Parte 1: desplazamiento a la izquierda (<<) -> Modificar bits\n");


    // crear la máscara trasladando el 1 a la posiión 'pos'
    unsigned char mascara = (1 << pos); // Binario: 0000 1000
    printf("Máscara (1 << %d): %d\n", pos, mascara);


    printf("A. Encender el Bit (OR|)\n");
    unsigned char estado_encendido = estado | mascara;
    printf("Encender bit %d (|): %d\n", pos, estado_encendido);

    printf("B. Apagar el Bit (AND NOT & ~)\n");
    unsigned char estado_apagado = estado & ~mascara;
    printf("Apagar bit %d (& ~): %d\n", pos, estado_apagado);

    printf("C. Alternar / Invertir el Bit (XOR ^)\n");
    unsigned char estado_alternado = estado ^ mascara;
    printf("Alternar bit %d (^); %d\n\n", pos, estado_alternado);

    //Parte 2: desplazamiento a la derecha (>>) -> Extraer y leer bits
    printf("Parte 2: desplazamiento a la derecha (>>) -> Extraer y leer bits\n");

    printf("A. extraer el valor directo (0,1) trayendolo a la posición 0\n");
    int bit_extraido = (estado >> pos) & 1;
    printf("El valor del bit en la pos %d: %d\n", pos, bit_extraido);

    printf("B. Probar con otra posición que valga 0 (por ejemplo pos = 1)\n");
    int pos_cero = 1;
    int bit_cero = (estado >> pos_cero) & 1;
    printf("Valor del bit en la pos %d: %d\n", pos_cero, bit_cero);

    printf("C. uso matemático: división rápida entera entre 2^n\n");
    unsigned char division_por_2 = estado >> 1; //40/2^1 = 20
    unsigned char division_por_4 = estado >> 2; // 40/2^2 = 10
    printf("División rápida (%d >>1 = %d / 2): %d\n", estado, estado, division_por_2);
    printf("División rápida (%d >> 2 = %d / 4): %d\n", estado, estado, division_por_4);
    
    
    return 0;
}