#ifndef PILHA_H
#define PILHA_H

typedef struct StackItem {
    void *data;
    struct StackItem *next; 
} StackItem;

typedef struct Stack {
    struct StackItem *head;
} Stack;

Stack* stack_init();

StackItem* stack_item_init();

void stack_push(Stack *stack, void *data);

void *stack_pop(Stack *stack);

void *stack_peek(const Stack *stack);

void stack_foreach(Stack *stack, void (*cb) (void*));

#endif
