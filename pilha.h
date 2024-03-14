#ifndef PILHA_H
#define PILHA_H

typedef struct Node {
    void *data;
    struct Node *next; 
} Node;

typedef struct Stack {
    struct Node *top;
} Stack;

Stack* create_stack();

Node* create_node();

void stack_push(Stack *stack, void *data);

void *stack_pop(Stack *stack);

void *stack_peek(const Stack *stack);

void stack_foreach(Stack *stack, void (*cb) (void*));

#endif
