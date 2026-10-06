#include <stdio.h>

char main(int argc, char *argv[]) {
    if (argc != 3) { // parchamos si es que entregan más o menos de 2 argumentos al llamar la función
        printf("Se admiten dos argumentos, ni más ni menos\n");
        return 1;
    }

    if (argv[1][1] != '\0' || argv[2][1] != '\0') { // parchar si ingresan strings o carácteres especiales
        printf("Debe ingresar caracteres unitarios, no palabras o frases\n");
        return 1;
    }

    // definimos el carácter objetivo como el primer argumento
    char objetivo = argv[1][0]; 
    char reemplazo = argv[2][0];
    // y el carácter de reemplazo como el segundo argumento

    // instrucción de introducir el texto
    printf("Ahora, introduzca una palabra o frase: ");
    
    // definimos como carácter el actual que se lee en el momento
    char actual;

    while ((actual = getchar()) != '\n') { //mientras el carácter actual no sea el último del string
        if (actual == objetivo) {
            putchar(reemplazo); // si es igual al carácter objetivo, lo reemplazamos por el de reemplazo
        }
        if (actual != objetivo) {
            putchar(actual); // si no es el objetivo, lo printeamos nomás tal cual
        }
        
    }
    return 0;
}