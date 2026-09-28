#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));

    node1->data = 10;
    node1->next = node2;   

    node2->data = 20;
    node2->next = NULL;    

    printf("node1 degeri: %d\n", node1->data);
    printf("node2 degeri (node1 uzerinden): %d\n", node1->next->data);
    printf("node2 degeri: %d\n", node2->data);

    free(node1);
    free(node2);
    return 0;
}