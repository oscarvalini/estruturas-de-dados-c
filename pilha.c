#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Stack* create_stack() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

Node* create_node() {
    return (Node*) malloc(sizeof(Node));
}

void stack_push(Stack *stack, void *value) {
    if(stack->top == NULL) {
        Node *head = create_node();
        head->data = value;
        head->next = NULL;
        stack->top = head;
        return;
    }

    Node *new_head = create_node();
    new_head->data = value;
    new_head->next = stack->top;
    stack->top = new_head;
}

void *stack_pop(Stack *stack) {
    void *data;

    Node *old_head = stack->top;
    stack->top = old_head->next;
    data = old_head->data;

    free(old_head);

    return data;
}

void *stack_peek(const Stack *stack) {
    return stack->top->data;
}

void stack_foreach(Stack *stack, void (*cb) (void*)) {
    Node *item = stack->top;
    
    while(item != NULL) {
        cb(item->data);
        Node *temp = item->next;
        item = temp;
    }

    return;
}