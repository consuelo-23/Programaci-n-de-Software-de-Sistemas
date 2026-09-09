/*
Escriba un programa o conjunto de funciones en C que implemente una calculadora evaluadora de expresiones representadas
    mediante un árbol binario. Para esto, asuma que la estructura de cada nodo del árbol almacena un operador (por ejemplo '+' o '*')
    o bien un operando numérico cuando se trata de una hoja (indicándolo con '\0').

Su solución debe:

- Incluir una función constructora para crear y asignar memoria dinámicamente en el Heap a los nodos del árbol.

- Implementar una función que reciba el puntero a la raíz del árbol y calcule recursivamente el resultado entero de evaluar
    la expresión representada.



primero: tengo que crear un árbol
*/

//Librerías
#include <stdio.h>
#include <stdlib.h> // para reservar memoria dinámica

typedef struct Node {
    char op;
    int val;
    struct nodo *left;
    struct nodo *right;
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


// vamos a jugar con las raíces
int evaluar(Node *root) {
    if (root == NULL) return 0;
    
    // recursividad
    if (root -> op =='\0') {
        return root -> val;
    }

    //y tarea se fue para la casa
    int izq = evaluar(root -> left);
    int der = evaluar(root -> right);

    if (root -> op == '+') return izq + der;
    if (root -> op == '*') return izq * der;

    return 0;
}

int main() {
    Node *n3 = crear_nodo('\0', 3, NULL, NULL);
    Node *n5 = crear_nodo('\0', 5, NULL, NULL);
    Node *n_mas = crear_nodo('+', 0, n3, n5);
    Node *n2 = crear_nodo('\0', 2, NULL, NULL);
    Node *raiz = crear_nodo('*', 0, n_mas, n2);

    printf("Resultado de la expresión: %d\n", evaluar(raiz));
    return 0;
}