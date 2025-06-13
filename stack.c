#include "stack.h"
#include "linked_list.h"

// Definimos la estructura Nodo de nuevo para poder acceder al primer elemento
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Declaramos la función auxiliar para obtener la cabeza
Nodo* linked_list_head(void);
// Inicializar stack con un máximo de 100 elementos
#define TAMANO_MAXIMO_PILA 100

void stack_init() {
    linked_list_init();
}

// Agregar un entero (dato) al stack
int stack_push(unsigned int dato) {
    if (linked_list_size() >= TAMANO_MAXIMO_PILA)
        return -1;
    return linked_list_prepend(dato);
}

// Saca un elemento del stack
int stack_pop() {
    if (linked_list_size() == 0)
        return -1;

    Nodo* cabeza = linked_list_head();
    int dato = cabeza->dato;

    linked_list_remove(dato);
    return dato;
}

// Regresa el tamaño del stack
unsigned int stack_size() {
    return linked_list_size();
}

// 1: lleno, 0: no lleno
int stack_is_full() {
    return linked_list_size() >= TAMANO_MAXIMO_PILA;
}

// 1: vacío, 0: no vacío
int stack_is_empty() {
    return linked_list_size() == 0;
}
