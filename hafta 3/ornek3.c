/*
  ÖRNEK-3: Ortadaki düğümü bulma (slow / fast yöntemi)
 
  GENEL AÇIKLAMA:
  - findMiddle: slow ve fast, head'den başlar. Her adımda slow bir, fast iki
    düğüm ilerler. fast listenin sonuna (NULL) ulaştığında slow ortadadır.
    Eleman sayısı tek ise tam ortadaki, çift ise iki ortadan ikincisi bulunur.
    Boş listede NULL döner.
  - Liste uzunluğunu önceden saymaya gerek olmadığı için liste tek geçişte gezilir.
  - findMiddle listeyi değiştirmediği için Node* yeterlidir.
  - clear: Tüm düğümleri free eder ve head'i NULL yapar.
  - Test için ekleme işlemi sona ekleyen küçük bir yardımcı fonksiyonla yapılır.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

static void addEnd(Node** head, int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (n == NULL) {
        printf("Bellek ayrilamadi!\n");
        exit(1);
    }
    n->data = value;
    n->next = NULL;
    Node** link = head;
    while (*link != NULL) link = &(*link)->next;
    *link = n;
}

Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("(bos liste)\n");
        return;
    }
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

static void test(int n) {
    Node* head = NULL;
    for (int i = 1; i <= n; i++) addEnd(&head, i * 10);
    printf("Liste: "); printList(head);
    Node* mid = findMiddle(head);
    if (mid) printf("Ortadaki: %d\n\n", mid->data);
    else     printf("Ortadaki: NULL\n\n");
    clear(&head);
}

int main(void) {
    test(0);   
    test(1);
    test(5);  
    test(6);   
    return 0;
}