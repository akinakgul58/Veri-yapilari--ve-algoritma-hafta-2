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

struct Node *deleteNode(struct Node *head, int value) {

    if (head == NULL) {
        return NULL;
    }

    if (head->data == value) {
        struct Node *temp = head;
        head = head->next;      
        free(temp);
        return head;
    }

    struct Node *previous = head;
    struct Node *current = head->next;

    while (current != NULL) {
        if (current->data == value) {
            previous->next = current->next;  
            free(current);                   
            return head;
        }
        previous = current;
        current = current->next;
    }

    printf("%d listede bulunamadi.\n", value);
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
    head->next->next->next = createNode(40);

    printf("Onceki liste: ");
    printList(head);

    int silinecek;
    printf("Silinecek sayiyi girin: ");
    if (scanf("%d", &silinecek) != 1) {
        printf("Gecersiz giris!\n");
        return 1;
    }

    head = deleteNode(head, silinecek);

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