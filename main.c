#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "linked_list.h"

void test_stack() {
    printf("Probando la implementación de 'stack')\n");
    stack_init();

    printf("Agregando 100 elementos...\n");
    for (int i = 1; i <= 100; i++) {
        if (stack_push(i) == -1) {
            printf("Error en push %d\n", i);
        }
    }

    printf("Tamaño: %u (esperado: 100)\n", stack_size());
    printf("Stack lleno? %d (esperado: 1)\n", stack_is_full());

    printf("Intentando un push más...\n");
    printf("Resultado del push: %d (esperado: -1)\n", stack_push(101));

    printf("Sacando 5 elementos...\n");
    for (int i = 0; i < 5; i++) {
        printf("Popped %d (esperado: %d)\n", stack_pop(), 100 - i);
    }

    printf("Tamaño: %u (esperado: 95)\n", stack_size());
    printf("Stack vacío? %d (esperado: 0)\n", stack_is_empty());

    printf("Vaciando el stack...\n");
    while (!stack_is_empty()) {
        stack_pop();
    }

    printf("Tamaño: %u (esperado: 0)\n", stack_size());
    printf("Stack vacío? %d (esperado: 1)\n", stack_is_empty());

    printf("Pop de un stack vacío...\n");
    printf("Popped: %d (esperado: -1)\n", stack_pop());
}

void test_linked_list() {
    printf("\nTesting Linked List implementation...\n");
    linked_list_init();

    printf("Agregando 10, 20, 30...\n");
    linked_list_append(10);
    linked_list_append(20);
    linked_list_append(30);

    printf("Agregando 5 al inicio...\n");
    linked_list_prepend(5);

    printf("Lista (debería ser 5, 10, 20, 30): ");
    linked_list_print();

    printf("Tamaño: %u (esperado: 4)\n", linked_list_size());
    printf("¿Contiene a 20? %d (esperado: 1)\n", linked_list_contains(20));
    printf("¿Contiene a 99? %d (esperado: 0)\n", linked_list_contains(99));

    printf("Quitando 20...\n");
    linked_list_remove(20);

    printf("Lista (debería ser 5, 10, 30): ");
    linked_list_print();
    printf("Quitando 99...\n");
    printf("Resultado: %d (esperado: -1)\n", linked_list_remove(99));
    printf("Tamaño: %u (esperado: 3)\n", linked_list_size());
}

int main() {
    test_stack();
    test_linked_list();
    return 0;
}