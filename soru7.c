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

int main() {
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    int aranan;
    printf("Aranan sayiyi girin: ");
    if (scanf("%d", &aranan) != 1) {
        printf("Gecersiz giris!\n");
        return 1;
    }

    int bulundu = 0;
    struct Node *current = head;

    while (current != NULL) {
        if (current->data == aranan) {
            bulundu = 1;
            break;                 
        }
        current = current->next;    
    }

    if (bulundu)
        printf("%d listede VAR.\n", aranan);
    else
        printf("%d listede YOK.\n", aranan);


    current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;

    return 0;
}