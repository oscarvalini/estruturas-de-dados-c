#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

print_node(Node *node) {
    printf("node: %p \n", node);
    printf("&node: %p \n", &node);
    printf("node->value %d \n", node->value);
    printf("node->next %p \n", node->next);
}

int main() {
    struct node node1;
    struct node node2;

    node2.value = 2;
    node2.next = NULL;
    
    node1.value = 1;
    node1.next = &node2;

    print_node(&node1);
    print_node(&node2);
    print_node(node1.next);

    return 0;
}