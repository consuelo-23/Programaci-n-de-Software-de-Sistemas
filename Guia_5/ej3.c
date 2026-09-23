#include <stdio.h>
#include <stdlib.h> // para reservar memoria dinámica

typedef struct Node {
    char op;
    int val;
    struct Node *left;
    struct Node *right;
}Node;

Node* crear_nodo(char op, int val, Node *l, Node *r) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) return NULL; //desarrollar con manejo de errores
    n -> op = op;
    n -> val = val;
    n -> left = l;
    n -> right = r;
    return n;
}

int conteo_nodos_internos(Node *root) {
    if(root == NULL) return 0;

    if (root -> op == '\0') return 0;

    return 1 + conteo_nodos_internos(root -> left) + conteo_nodos_internos(root -> right);
}

int main() {
    Node *n3 = crear_nodo('\0', 3, NULL, NULL);
    Node *n5 = crear_nodo('\0', 5, NULL, NULL);
    Node *n_mas = crear_nodo('+', 0, n3, n5);
    Node *n2 = crear_nodo('\0', 2, NULL, NULL);
    Node *raiz = crear_nodo('*', 0, n_mas, n2);

    int conteo = conteo_nodos_internos(raiz);
    printf("Hay %d operadores en este árbol\n", conteo);

    free(n3);
    free(n5);
    free(n_mas);
    free(n2);
    free(raiz);
    return 0;
}