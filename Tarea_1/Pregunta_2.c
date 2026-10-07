#include <stdio.h>
#include <string.h>

int compare_words(char *p1, char *p2) {
    while(*p1 == *p2) {
        if (*p1 == '\0') {
            // si ambas llegan al final al mismo tiempo y son iguales
            return 1; //retorna 1 de verdadero
        }
        p1++;
        p2++;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc != 2){ // parchar si ingresa no ingresa dos argumentos
        printf("Se necesita un argumento\n");
        return 1;
    }


    char *palabra = &argv[1][0]; // definimos palabra como el argumento dado

    int counter = 0; //iniciamos un contador para las filas que contengan la palabra
    char linea[9999]; // definimos la línea a leer como char


    while (fgets(linea, sizeof(linea), stdin) != NULL) { //mientras la línea a leer no sea nula

        
        char word[1234] = ""; //definimos el char word como la palabra que vamos a leer

        for (char *i = linea; *i != '\0'; )  { //por cada carácter de la línea
            size_t largo = 0;
            
            while(*i != ' ' && *i != ',' && *i != '.' && *i != '\n' && *i != '\t' && *i != '\r' && *i != '\0') { //mientras el carácter leído no sea separador de ningún tipo
                
                if (largo < sizeof(word) - 1) { //dejamos libre una posición para el '\0' carácter terminador
                    word[largo] = *i; // colocamos sólo el carácter actual al final de la palabra
                    largo++; // y aumentamos el largo de la palabra
                }
                i++; //pasamos al sgte carácter
            }

            word[largo] = '\0';

            if (compare_words(palabra, word)) { //si las palabras son iguales (word con palabra)
                counter++; //aumentamos el contador
                break; //y continuamos a la sgte línea
            }
            word[0] = '\0'; //retornamos word a ser una palabra vacía

            if (*i != '\0') {
                i++; // si el carácter no es el último, seguimos avanzando en el for
            }
        }
    
    }
    printf("%d", counter);
    return 0;
}