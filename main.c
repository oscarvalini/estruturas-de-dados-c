#include "pilha.h"
#include <stdio.h>

void main() {
    Stack *stack = stack_init();

    stack_push(stack, 10);
    stack_push(stack, 8);
    stack_push(stack, 5);
    printf("Peek: %d\n", stack_peek(stack));

    int popped = stack_pop(stack);

    print_stack(stack);
}