/*
  GENEL AÇIKLAMA:
  - head, ilk düğümün adresini tutan işaretçidir. Baş düğüm değişebilecek
    fonksiyonlarda Node** alınır ve
    *head üzerinden main'deki head güncellenir.
  - addOrdered: Liste boşsa ya da value baştakinden küçükse yeni düğüm başa
    eklenir. Aksi halde, sonraki düğümün değeri value'dan küçük olduğu sürece
    ilerlenir ve yeni düğüm doğru yere bağlanır.
  - removeNode: Node** ile listeyi gezerek değeri bulur; bulunan düğümü
    kendisini gösteren bağlantıyı bir sonrakine çevirerek listeden çıkarır ve free eder.
  - count: Listeyi baştan sona gezip düğümleri sayar.
  - printList: Sadece okuma yaptığı için Node* yeterlidir.
  - clear: Her düğümün next'ini kaybetmeden önce saklar, düğümü free eder;
     en sonda *head = NULL yapar. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

static Node* createNode(int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (n == NULL) {
        printf("Bellek ayrilamadi!\n");
        exit(1);
    }
    n->data = value;
    n->next = NULL;
    return n;
}

void addOrdered(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL || value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* cur = *head;
    while (cur->next != NULL && cur->next->data < value)
        cur = cur->next;
    newNode->next = cur->next;
    cur->next = newNode;
}

void removeNode(Node** head, int value) {
    Node** link = head;               /* düğümü gösteren bağlantının adresi */
    while (*link != NULL && (*link)->data != value)
        link = &(*link)->next;
    if (*link == NULL) return;        /* değer bulunamadı */
    Node* temp = *link;
    *link = temp->next;
    free(temp);
}

int count(Node* head) {
    int c = 0;
    while (head != NULL) {
        c++;
        head = head->next;
    }
    return c;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

void clear(Node** head) {
    Node* cur = *head;
    while (cur != NULL) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
    *head = NULL;
}

int main(void) {
    Node* head = NULL;
    int values[] = {23, 11, 5, 9, 6, 4, 12, 24};
    for (int i = 0; i < 8; i++) addOrdered(&head, values[i]);

    printf("Liste: ");           printList(head);
    printf("Eleman sayisi: %d\n", count(head));

    removeNode(&head, 9);
    printf("9 silindi: ");       printList(head);
    removeNode(&head, 4);
    printf("4 (bas) silindi: "); printList(head);
    removeNode(&head, 100);
    printf("100 (yok): ");       printList(head);
    printf("Eleman sayisi: %d\n", count(head));

    clear(&head);
    printf("Temizlendi, eleman sayisi: %d\n", count(head));
    return 0;
}