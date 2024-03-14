#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Stack* stack_init() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

StackItem* stack_item_init() {
    return (StackItem*) malloc(sizeof(StackItem));
}

void stack_push(Stack *stack, void *value) {
    if(stack->head == NULL) {
        StackItem *head = stack_item_init();
        head->data = value;
        head->next = NULL;
        stack->head = head;
        return;
    }

    StackItem *new_head = stack_item_init();
    new_head->data = value;
    new_head->next = stack->head;
    stack->head = new_head;
}

void *stack_pop(Stack *stack) {
    void *data;

    StackItem *old_head = stack->head;
    stack->head = old_head->next;
    data = old_head->data;

    free(old_head);

    return data;
}

void *stack_peek(const Stack *stack) {
    return stack->head->data;
}

void stack_foreach(Stack *stack, void (*cb) (void*)) {
    StackItem *item = stack->head;
    
    while(item != NULL) {
        cb(item->data);
        StackItem *temp = item->next;
        item = temp;
    }

    return;
}