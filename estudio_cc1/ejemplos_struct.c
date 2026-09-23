#include <stdio.h>
#include <stdlib.h> // Para malloc() y free()

// Estructura recursiva para una lista enlazada (como vagones de un tren)
typedef struct nodo {
    int valor;                 // Dato almacenado
    struct nodo *siguiente;    // Puntero al siguiente nodo en memoria
} Nodo;

int main() {
    // Creación dinámica de nodos con malloc
    Nodo *primero = (Nodo *)malloc(sizeof(Nodo));
    Nodo *segundo = (Nodo *)malloc(sizeof(Nodo));

    // Configuración del primer nodo
    primero->valor = 100;
    primero->siguiente = segundo; // Enlaza con el segundo nodo

    // Configuración del segundo nodo (último de la lista)
    segundo->valor = 200;
    segundo->siguiente = NULL;    // NULL indica el fin de la lista

    // Recorrido de la lista enlazada
    Nodo *aux = primero;
    while (aux != NULL) {
        printf("Valor en nodo: %d\n", aux->valor);
        aux = aux->siguiente; // Avanza al siguiente elemento
    }

    // Liberar la memoria asignada
    free(segundo);
    free(primero);

    return 0;
}