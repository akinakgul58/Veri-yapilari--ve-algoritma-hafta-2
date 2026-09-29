#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;          
    struct Node *next;  
};

int main() {

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->data = 10;    
    node->next = NULL;  

    printf("Node degeri: %d\n", node->data);

    free(node);         
    return 0;
}