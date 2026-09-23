/*
Dada la estructura estándar para representar un nodo en un árbol
binario de enteros:

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Escriba una función recursiva int contar_hojas(Node *root) que reciba
el puntero a la raíz del árbol y determine la cantidad total de nodos hoja
que contiene. Considere que un nodo se define como "hoja" si no podee un
subárbol izquierdo ni derecho. La función debe manejar adecuadamente el
caso de recibir un árbol vacío.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

// Función auxiliar para construir nodos dinámicamente en el Heap
Node* crear_nodo(int valor) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) return NULL;
    n->val = valor;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Función recursiva que cuenta los nodos hoja
int contar_hojas(Node *root) {
    // Caso Base 1: Árbol o subárbol vacío
    if (root == NULL) return 0;

    // Caso Base 2: El nodo actual es una hoja (sin hijos)
    if (root->left == NULL && root->right == NULL) return 1;

    // Caso Recursivo: Sumar hojas del subárbol izquierdo y derecho
    return contar_hojas(root->left) + contar_hojas(root->right);
}

// MAIN PARA PRUEBAS
int main() {
    Node *root = crear_nodo(10);
    root->left = crear_nodo(5);
    root->right = crear_nodo(15);
    root->left->left = crear_nodo(2);

    printf("Cantidad total de nodos hoja: %d\n", contar_hojas(root));

    // Liberación de memoria
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
