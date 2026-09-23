#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int valor, Node *l, Node *r){
    Node *n = (Node *)malloc(sizeof(Node));
    n -> value = valor;
    n -> left = l;
    n -> right = r;

    return n;
}

bool value_search(Node *root, int valor){
    if (root == NULL) return 0;

    if (root -> value == valor) return 1;

    if (root -> value != valor) {
        bool izq = value_search(root -> left, valor);
        bool der = value_search(root -> right, valor);

        if(izq | der) return 1;
        else return 0;
    }
}

int main() {
    Node *one = create_node(1, NULL, NULL);
    Node *three = create_node(3, NULL, NULL);
    Node *two = create_node(2, one, three);
    Node *seven = create_node(7, NULL, NULL);
    Node *six = create_node(6, NULL, seven);
    Node *five = create_node(5, NULL, six);
    Node *root = create_node(4, two, five);

    bool hay_cinco = value_search(root, 5);
    printf("¿Existe el 5 en este árbol? %s\n", hay_cinco ? "True" : "False");

    free(one);
    free(two);
    free(three);
    free(root);
    free(five);
    free(six);
    free(seven);
    return 0;
}