#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// malloc ile yeni düğüm oluşturur
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {          
        printf("Bellek ayrilamadi!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    // Listeyi yazdır
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Belleği serbest bırak
    current = head;
    while (current != NULL) {
        struct Node *temp = current;   
        current = current->next;       
        free(temp);                   
    }
    head = NULL;                      
    return 0;
}