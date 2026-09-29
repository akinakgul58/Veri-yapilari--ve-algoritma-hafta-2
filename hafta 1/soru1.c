#include <stdio.h>

#define N 10

int main() {
    int dizi[N];

    printf("10 tane tam sayi girin:\n");
    for (int i = 0; i < N; i++) {
        printf("dizi[%d] = ", i);
        scanf("%d", &dizi[i]);
    }

    
    printf("\nGirdiginiz dizi:\n");
    for (int i = 0; i < N; i++) {
        printf("dizi[%d] = %d\n", i, dizi[i]);
    }

    return 0;
}