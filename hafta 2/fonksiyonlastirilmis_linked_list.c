#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *insertBeginning(struct Node *head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Bellek ayrilamadi!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = head;   
    return newNode;       
}

int getFirst(struct Node *head, int *found) {
    if (head == NULL) {
        *found = 0;
        return 0;
    }
    *found = 1;
    return head->data;
}

void display(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int search(struct Node *head, int value) {
    struct Node *current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == value)
            return position;
        current = current->next;
        position++;
    }
    return 0;
}

void freeList(struct Node *head) {
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;

    head = insertBeginning(head, 30);
    head = insertBeginning(head, 20);
    head = insertBeginning(head, 10);

    printf("Liste: ");
    display(head);

    int found;
    int first = getFirst(head, &found);
    if (found)
        printf("Ilk node degeri: %d\n", first);

    int aranan;
    printf("Aranan sayiyi girin: ");
    if (scanf("%d", &aranan) != 1) {
        printf("Gecersiz giris!\n");
        freeList(head);
        return 1;
    }

    int pos = search(head, aranan);
    if (pos > 0)
        printf("%d listede VAR (%d. sirada).\n", aranan, pos);
    else
        printf("%d listede YOK.\n", aranan);

    freeList(head);
    head = NULL;
    return 0;
}
