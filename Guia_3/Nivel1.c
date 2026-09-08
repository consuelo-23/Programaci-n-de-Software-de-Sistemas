#include <stdio.h>
#include <stdlib.h>

int binary_rep( unsigned int number) {
    int contador = 0;
    for (int i = 0; i < sizeof(number)*8; i++){
        unsigned char bit = (number >> i) & 1;
        if (bit==1){
            contador +=1;
        }
    }
    printf("%d, tiene %d unos\n", number, contador);
    return 0;
}


int low_high(int numbers[10], int *menor, int *mayor) {
    *menor = numbers[0];
    *mayor = numbers[0];

    for (int i=0; i<= 10; i++) {
        if (numbers[i] < *menor) {
            *menor = numbers[i];
        }
        if (numbers[i] > *mayor) {
            *mayor = numbers[i];
        }
    }
    printf("En el array, el menor valor es: %d, y el mayor valor es: %d\n", *menor, *mayor);

    return 0;
}

int main() {
    binary_rep(257);

    int mi_menor = 2147483647 ;
    int mi_mayor = -2147483648 ;

    int array1[10] = {1,3,22,4,566,3,-9, 223, 43, 10};
    low_high(array1, &mi_menor, &mi_mayor);
    return 0;
}