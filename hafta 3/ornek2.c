/*
 
  GENEL AÇIKLAMA:
  - insertAt: position <= 0 veya liste boşsa yeni düğüm başa eklenir.
    Aksi halde (position-1). düğüme kadar ilerlenir; liste bitiyorsa
    döngü son düğümde durur veyeni düğüm sona eklenir. 
    Yeni düğüm bulunan düğümün arkasına bağlanır.
  - deleteAt: position < 0 veya liste boşsa işlem yapılmaz. position == 0 ise
    *head bir sonrakine kaydırılır. Diğer durumlarda (position-1). düğüme
    gidilir; arkasında düğüm yoksa pozisyon geçersizdir ve hiçbir şey yapılmaz,
    varsa düğüm bağlantıdan çıkarılıp free edilir.
  - Baş düğüm değişebildiği için head parametresi Node** olarak alınır.
  - printList sadece okur , clear tüm düğümleri free eder.
 */
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

void insertAt(Node** head, int value, int position) {
    Node* newNode = createNode(value);
    if (position <= 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* cur = *head;
    int i = 0;
    while (i < position - 1 && cur->next != NULL) {
        cur = cur->next;
        i++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
}

void deleteAt(Node** head, int position) {
    if (position < 0 || *head == NULL) return;
    if (position == 0) {
        Node* temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }
    Node* cur = *head;
    int i = 0;
    while (i < position - 1 && cur->next != NULL) {
        cur = cur->next;
        i++;
    }
    if (cur->next == NULL) return;    /* geçersiz pozisyon */
    Node* temp = cur->next;
    cur->next = temp->next;
    free(temp);
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

int main(void) {
    Node* head = NULL;

    insertAt(&head, 10, 0);   printf("insertAt(10,0):  "); printList(head);
    insertAt(&head, 20, 5);   printf("insertAt(20,5):  "); printList(head); 
    insertAt(&head, 5, -3);   printf("insertAt(5,-3):  "); printList(head);  
    insertAt(&head, 15, 2);   printf("insertAt(15,2):  "); printList(head);  

    deleteAt(&head, 10);      printf("deleteAt(10) gecersiz: "); printList(head);
    deleteAt(&head, 2);       printf("deleteAt(2):     "); printList(head);
    deleteAt(&head, 0);       printf("deleteAt(0):     "); printList(head);
    deleteAt(&head, 1);       printf("deleteAt(1):     "); printList(head);

    clear(&head);
    printf("clear sonrasi:   "); printList(head);
    return 0;
}