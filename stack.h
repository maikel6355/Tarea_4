#ifndef STACK_H
#define STACK_H

// Inicializar stack con un máximo de 100 elementos
void stack_init();

// Agregar un entero al stack
// 0: éxito, -1: stack lleno
int stack_push(unsigned int data);

// Saca un elemento del stack
// Regresa el entero: éxito, -1: stack está vacío
int stack_pop();

// Regresa el tamaño del stack
unsigned int stack_size();

// 1: lleno, 0: no lleno
int stack_is_full();

// 1: vacío, 0: no vacío
int stack_is_empty();

#endif // STACK_H