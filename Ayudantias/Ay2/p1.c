// estructura de datos como árbol binario

#include <stdio.h>
#include <stdlin.h> // necesario para malloc() y free()

// 5. Estructuras complejas en C --> typedef
 // Oopción B
typedef struct nodo { // define la plantilla de una "caja" que contiene:
    int valor; //un número entero
    struct nodo* izq; //dos punteros (izquierdo y derecho) que guardan direcciones
    struct nodo* der; // de memoria hacia otros nodos hijos o NULL
} nodo;


//a)
nodo* generar(int valor) {
    nodo* nuevo = (nodo*)malloc(sizeof(nodo)); //malloc() pide a la memoria dinámica el espacio exacto de un nodo
    nuevo -> valor = valor; //inicializa sus variables
    nuevo -> izq = NULL;
    nuevo -> der = NULL;
    return nuevo; // retorna la dirección en memoria del nuevo nodo
}

//b)
void agregar(nodo* cabeza, int valor) { // función para agregar nodos
    nodo* nuevo = generar(valor); // nuevo nodo es el que generamos
    nodo* aux = cabeza; // nodo auxiliar(?)
    while (aux) { // mientras estemos buscando
        if (aux -> valor > nuevo -> valor) { // si el valor nuevo es menor al actual del nodo lo colocamos el nuevo a la izquierda
            if (aux -> izq == NULL) { // si la izquierda está vacío lo colocamos ahí
                aux -> izq = nuevo;
                break;
            } // si no está vacío, repetimos el proceso, y el auxiliar se convierte en el nodo que estaba a la izquierda
            aux = aux->izq; 
        }

        else if (aux -> valor < nuevo -> valor) { // misma idea hacia la derecha
            if (aux -> der == NULL){
                aux -> der = nuevo;
                break;
            }
            aux = aux -> der;
        }
    }
}

//c) busca eliminar todo el árbol
void liberaMemoria(nodo* cabeza) { // hace todo al mismo tiempo
    if (cabeza == NULL) return; // chequea si el nodo es NULL, si lo es no retorna nada
    liberarMemoria(cabeza -> izq); // va al nodo a la izquierda y chequea si es vacío
    liberarMemoria(cabeza -> der); // va al nodo a la derecha y chequea con la función
    free(cabeza); // libera el espacio
}


//d) una función que busque un valor dentro del árbol (determina si está o no sólamente)
void buscar(nodo* cabeza, int valor){
    for(;cabeza->valor != valor;){ // el for exige para funcionar: for (inicialización ; condición ; actualización)
        // en este caso sólo tenemos la condición
        if (cabeza->valor > valor){
            buscar(cabeza->izq, valor);
        }
        else if (cabeza->valor < valor){
            buscar(cabeza->der, valor);
        }
        return;
    }
    printf("Valor encontrado\n");
}