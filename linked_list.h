#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Inicializar la lista
void linked_list_init();

// Agregar un elemento al final de la lista
// 0: éxito, -1: error
int linked_list_append(int data);

// Agregar un elemento al inicio de la lista
// 0: éxito, -1: error
int linked_list_prepend(int data);

// Elimina el primer elemento que coincide con el dato proporcionado
// 0: éxito, -1: error (elemento no encontrado)
int linked_list_remove(int data);

// Encontrar un elemento en la lista
// 1: éxito, 0: error (elemento no encontrado)
int linked_list_contains(int data);

// Regresa el tamaño de la lista
unsigned int linked_list_size();

// Imprimir todos los elementos de la lista enlazada
void linked_list_print();

#endif // LINKED_LIST_H