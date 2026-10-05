#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: sólo se admiten dos argumentos");
        return 1;
    }

    char objetivo = argv[1][0];
    char reemplazo = argv[2][0];

    char palabra;
    printf("Introduzca una palabra o frase: ");
    scanf("%c", &palabra -1);
    
    int actual;

    while ((actual = getchar()) != EOF) {
        if (actual == objetivo) {
            putchar(reemplazo);
        }
        if (actual != objetivo) {
            putchar(actual);
        }
        
    }
    return 0;
}