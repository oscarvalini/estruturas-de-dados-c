#include <stdio.h>
#include <stdlib.h>

typedef struct StackItem {
    int value;
    struct StackItem *next; 
} StackItem;

typedef struct Stack {
    struct StackItem *head;
} Stack;

Stack* stack_init() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

StackItem* stack_item_init() {
    return (StackItem*) malloc(sizeof(StackItem));
}

void stack_push(Stack *stack, int value) {
    if(stack->head == NULL) {
        StackItem *head = stack_item_init();
        head->value = value;
        head->next = NULL;
        stack->head = head;
        return;
    }

    StackItem *new_head = stack_item_init();
    new_head->value = value;
    new_head->next = stack->head;
    stack->head = new_head;
}

int stack_pop(Stack *stack) {
    int value;

    StackItem *old_head = stack->head;
    stack->head = old_head->next;

    value = old_head->value;
    free(old_head);
    return value;
}

int stack_peek(const Stack *stack) {
    return stack->head->value;
}

void print_stack(const Stack *stack) {
    puts("=================STACK===============");
     
    StackItem *item = stack->head;
    
    while(item != NULL) {
        printf("%d \n", item->value);
        StackItem *temp = item->next;
        item = temp;
    }

    return;
}

void main() {
    Stack *stack = stack_init();

    stack_push(stack, 10);
    stack_push(stack, 8);
    stack_push(stack, 5);
    printf("Peek: %d\n", stack_peek(stack));

    int popped = stack_pop(stack);

    print_stack(stack);
}