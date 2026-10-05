#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Se admiten dos argumentos, ni más ni menos");
        return 1;
    }

    if (argv[1][0] == '\0' || argv[2][0] == '\0') {
        printf("Debe ingresar dos caracteres");
        return 1;
    }

    if (argv[1][1] != '\0' || argv[2][1] != '\0') {
        printf("Debe ingresar caracteres unitarios, no palabras o frases");
        return 1;
    }


    char objetivo = argv[1][0];
    char reemplazo = argv[2][0];


    printf("Ahora, introduzca una palabra o frase: ");
    
    
    int actual;

    while ((actual = getchar()) != '\n') {
        if (actual == objetivo) {
            putchar(reemplazo);
        }
        if (actual != objetivo) {
            putchar(actual);
        }
        
    }
    return 0;
}