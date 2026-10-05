#include <stdio.h>
#include <string.h>

int compare_words(char *p1, char *p2) {
    while(*p1 == *p2) {
        if (*p1 == '\0') {
            // si ambas llegan al final al mismo tiempo y son iguales
            return 1;
        }
        p1++;
        p2++;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc != 2){ // parchar si ingresa dos o más argumentos
        printf("Se necesita sólamente un argumento");
        return 1;
    }

    if (argv[1][0] == '\0') { // parchar por si no ingresa nada
        printf("Debe ingresar un argumento (palabra)\n");
        return 1;
    }

    char palabra = argv[1][0];


    printf("Ingrese un texto: ");
    char linea[9999];
    while (fgets(linea, sizeof(linea), stdin) != NULL) {
        printf("%s", linea);

        if (linea[0] == '\n') {
            break; //rompe el bucle y termina
        }

        for (int i=0; i <strlen(linea); i++) {

        }
    }
    return 0;
}