#ifndef PILHA_H
#define PILHA_H

typedef struct StackItem {
    int value;
    struct StackItem *next; 
} StackItem;

typedef struct Stack {
    struct StackItem *head;
} Stack;

Stack* stack_init();

StackItem* stack_item_init();

void stack_push(Stack *stack, int value);

int stack_pop(Stack *stack);

int stack_peek(const Stack *stack);

void print_stack(const Stack *stack);

#endif
