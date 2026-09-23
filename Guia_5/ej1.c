#include <stdio.h>
#include <stdlib.h>

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

int height(Node *root) {
    if (root == NULL) return 0;

    int izq = height(root -> left) + 1;
    int der = height(root -> right) + 1;

    if (izq >= der) return izq;
    else return der;
}

int main() {
    Node *one = create_node(1, NULL, NULL);
    Node *three = create_node(3, NULL, NULL);
    Node *two = create_node(2, one, three);
    Node *seven = create_node(7, NULL, NULL);
    Node *six = create_node(6, NULL, seven);
    Node *five = create_node(5, NULL, six);
    Node *four = create_node(4, two, five);

    int altura = height(four);
    printf("Altura es: %d\n", altura);

    free(one);
    free(two);
    free(three);
    free(four);
    free(five);
    free(six);
    free(seven);
    return 0;
}