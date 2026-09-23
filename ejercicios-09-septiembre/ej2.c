/*
Dado el tipo de datos Node, se desea procesar expresiones matemáticas
en texto (ej. 3+4*7)
Asuma que la cadena no contiene espacios en blanco, que está bien formada
y que sólo contiene operandos de un sólo dígito sin paréntesis

Escriba una función int calcular(char *expresión) que tome una cadena de
texto representando una expresión aritmética y retorne el valor
numérico (entero) de su evaluación

Para esto, implemente internamente la estrategia de parseo por
construcción de árbol binario de expresión: 
    se debe localizar el operador de menor precedencia para
    dividir la cadena recursivamente en sus subárboles
    izquierdo y derecho, reservar la memoria necesaria para la
    estructura mediante asignación dinámica, y posteriormente
    evaluar el árbol resultante
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char op; //operadores +, * o \0 si es número
    int val; // valor si op == \0
    struct Node *left, *right;
} Node;



Node *build_tree (char *expr, int start, int end) {
    //buscamos '+'
    int operador_pos = -1; // -1 default, sería cuando estamos en presencia de un número

    for (int i = end; i >= start; i--) {
        if (expr[i] == '+') {
            operador_pos = i;
            break;
        }
    }

    //buscamos '*'
    if (operador_pos == -1) {
        for (int i=end; i>=start; i--) {
            if (expr[i] == '*') {
                operador_pos = i;
                break;
            }
        }
    }
    


    Node *n = (Node *)malloc(sizeof(Node));
    if (operador_pos != -1) {
        n -> op = expr[operador_pos];
        n -> val = 0;
        n -> left = build_tree(expr, start, operador_pos -1);
        n -> right = build_tree(expr, operador_pos + 1, end);
    }
    if (operador_pos == -1) { // tenemos un número
        n -> op = '\0';
        n -> val = expr[start] - '0'; //debiera convertir de char a int
        n -> left = NULL;
        n -> right = NULL;
    }

    return n;

}

int evaluar(Node *root) {
    if (root == NULL) return 0;

    if (root-> op == '\0') return root -> val;

    if (root -> op == '+') return evaluar(root -> left) + evaluar(root -> right);

    if (root -> op == '*') return evaluar(root -> left) * evaluar(root -> right);

    return 0;
}


void liberar_arbol(Node *root) {
    if (root == NULL) return;
    liberar_arbol(root->left);
    liberar_arbol(root->right);
    free(root);
}



int calcular(char *expresion) {
    Node *root = build_tree(expresion, 0, strlen(expresion));
    int resultado = evaluar(root);

    liberar_arbol(root);
    return resultado;
}
     



int main() {
    char aaa[] = "4+3*5+3*2";
    printf("Resultado: %d\n", calcular(aaa));
    return 0;
}