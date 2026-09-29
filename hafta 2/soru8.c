#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

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


struct Node *insertAtBeginning(struct Node *head, int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;  
    head = newNode;        
    return head;
}

void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("Onceki liste: ");
    printList(head);

    head = insertAtBeginning(head, 5);

    printf("Yeni liste:   ");
    printList(head);


    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;

    return 0;
}