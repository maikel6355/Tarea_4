#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Definición del nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

static Nodo* cabeza = NULL;
static unsigned int tamano_lista = 0;

// Inicializar la lista
void linked_list_init() {
    while (cabeza != NULL) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
    tamano_lista = 0;
}

// Agregar un elemento al final de la lista
// 0: éxito, -1: error
int linked_list_append(int dato) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo_nodo) return -1;
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = NULL;

    if (cabeza == NULL) {
        cabeza = nuevo_nodo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != NULL)
            actual = actual->siguiente;
        actual->siguiente = nuevo_nodo;
    }
    tamano_lista++;
    return 0;
}

// Agregar un elemento al inicio de la lista
// 0: éxito, -1: error
int linked_list_prepend(int dato) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo_nodo) return -1;
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = cabeza;
    cabeza = nuevo_nodo;
    tamano_lista++;
    return 0;
}

// Elimina el primer elemento que coincide con el dato proporcionado
// 0: éxito, -1: error (elemento no encontrado)
int linked_list_remove(int dato) {
    Nodo* actual = cabeza;
    Nodo* anterior = NULL;

    while (actual != NULL) {
        if (actual->dato == dato) {
            if (anterior == NULL) {
                cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            tamano_lista--;
            return 0;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return -1;
}

// Encontrar un elemento en la lista
// 1: éxito, 0: error (elemento no encontrado)
int linked_list_contains(int dato) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        if (actual->dato == dato)
            return 1;
        actual = actual->siguiente;
    }
    return 0;
}

// Regresa el tamaño de la lista
unsigned int linked_list_size() {
    return tamano_lista;
}

// Imprimir todos los elementos de la lista enlazada
void linked_list_print() {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Función auxiliar para stack.c
//para encontar el primer elemento de la lista
Nodo* linked_list_head() {
    return cabeza;
}
