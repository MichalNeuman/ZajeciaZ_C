#include <stdio.h>

int main() {
    // Tworzenie tablicy dziesięciu liczb całkowitych i inicjalizacja wartościami od 0 do 9
    int tablica[10];
    for (int i = 0; i < 10; i++) {
        tablica[i] = i;
    }
    
    int *wskaznik = tablica; // Inicjalizacja wskaźnika na pierwszy element tablicy
    for (int i = 0; i < 10; i++) {
        printf("Wartość elementu %d: %d\n", i, *wskaznik);
        wskaznik++; // Inkrementacja wskaźnika, aby przejść do następnego elementu tablicy
    }
    
    return 0;
}
