#include <stdio.h>

int main() {
    int sayi, orijinal, kalan, ters = 0;

    printf("Bir tam sayi giriniz: ");
    scanf("%d", &sayi);

    orijinal = sayi;  

    if (sayi < 0) {
        printf("%d bir palindrom sayi degildir.\n", sayi);
        return 0;
    }

    while (sayi != 0) {
        kalan = sayi % 10;       
        ters = (ters * 10) + kalan; 
        sayi = sayi / 10;          
    }

    if (orijinal == ters)
        printf("%d bir palindrom sayidir.\n", orijinal);
    else
        printf("%d bir palindrom sayi degildir.\n", orijinal);

    return 0;
}