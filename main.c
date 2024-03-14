#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Pessoa {
    char nome[255];
    short idade;
};

void print_stack_int(void *item) {
    printf("%d -> ", *((int *)item));
}

void print_stack_pessoa(void *pessoa) {
    struct Pessoa *p = (struct Pessoa*) pessoa;
    printf("nome: %s, idade: %d -> ", p->nome, p->idade );
}

int *new_int(int val) {
    int *pval = malloc(sizeof(int));
    *pval = val;
    return pval;
}

void main() {
    Stack *stack1 = create_stack();
    Stack *stack2 = create_stack();

    stack_push(stack1, new_int(10));
    stack_push(stack1, new_int(8));

    struct Pessoa p1;
    strcpy(p1.nome, "Oscar");
    p1.idade = 29;

    stack_push(stack2, &p1);

    stack_foreach(stack1, print_stack_int);
    printf("FIM\n\n");
    stack_foreach(stack2, print_stack_pessoa);
    printf("FIM\n\n");
}