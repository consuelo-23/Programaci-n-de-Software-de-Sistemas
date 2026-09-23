/*
dado el tipo de dato Node para representar un nodo en un árbol binario, escriba una función
recursiva en C void liberar_arbol(Node *root) que reciba el puntero a la raíz de una árbol binario 
y libere toda la memoria reservada dinámicamente en el Heap para sus nodos

Para garantizar la integridad del programa, la función debe asegurar la liberación previa
de los subárboles hijo antes de liberar el nodo padre (recorrido post -order)
y manejar adecuadamente el caso de un árbol vacío
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char op;            // '+', '*' o '\0' si es un número
    int val;            // Valor numérico si op == '\0'
    struct Node *left;
    struct Node *right;
} Node;

// Función auxiliar para crear nodos en Heap
Node* crear_nodo(char op, int val, Node *l, Node *r) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) return NULL;
    n->op = op;
    n->val = val;
    n->left = l;
    n->right = r;
    return n;
}

// Función solicitada: Liberación recursiva de memoria dinámicamente
void liberar_arbol(Node *root) {
    // Caso Base: Si el árbol o subárbol está vacío, no hay nada que liberar
    if (root == NULL) return;

    // 1. Liberar recursivamente el subárbol izquierdo
    liberar_arbol(root->left);

    // 2. Liberar recursivamente el subárbol derecho
    liberar_arbol(root->right);

    // 3. Liberar la memoria del nodo actual (Padre)
    free(root);
}

// MAIN PARA PRUEBAS
int main() {
    // Construcción manual de la expresión: (3 + 5) * 2
    Node *n3 = crear_nodo('\0', 3, NULL, NULL);
    Node *n5 = crear_nodo('\0', 5, NULL, NULL);
    Node *suma = crear_nodo('+', 0, n3, n5);
    Node *n2 = crear_nodo('\0', 2, NULL, NULL);
    Node *raiz = crear_nodo('*', 0, suma, n2);

    // Liberación de toda la memoria consumida por la estructura
    liberar_arbol(raiz);
    raiz = NULL; // Buena práctica: evitar punteros colgantes

    printf("Memoria liberada exitosamente.\n");
    return 0;
}
  