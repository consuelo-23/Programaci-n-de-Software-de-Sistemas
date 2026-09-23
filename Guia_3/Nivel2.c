#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(const char *text) {
    if (text == NULL) printf("text is null");
    
    const char *izq = text;
    if (strlen(text)== 0) printf("text has no characters");
    const char *der = text + (strlen(text) - 1);

    while (izq<der) {
        if (*izq != *der) {
            printf("The text %s is not a palindrome\n", text);
            return 1;
        }
        else {
            *izq++;
            *der--;
        }
    }
    printf("The text %s is a palindrome\n", text);
    return 0;
}


/*
*texto -> puntero al primer caracter
char *texto: recibe una cadena

*extraer -> función tiene que crear una cadena con malloc()
malloc devuelve la dirección de memoria
función necesita retornar un puntero a char
*/
char *extraer(char *texto, int inicio, int n) { 
    char *nueva = malloc((n + 1) * sizeof(char));

    if (nueva == NULL)
        return NULL;

    for (int i = 0; i < n; i++)
        nueva[i] = texto[inicio + i];

    nueva[n] = '\0';

    return nueva;
}




int main() {
    const char a[] = "reconocer";
    const char b[] = "sistemas";
    is_palindrome(a);
    is_palindrome(b);

    char texto[] = "Hola mundo";
    char *nueva = extraer(texto, 0, 5); // palabra, inicio, #carácteres
    printf("%s\n", nueva);
    free(nueva);
    return 0;

}