#include <stdio.h>

// Deklaracje funkcji
int dodawanie(int a, int b) {
    return a + b;
}

int mnozenie(int a, int b) {
    return a * b;
}

int odejmowanie(int a, int b) {
    return a - b;
}

int main() {
    // Deklaracja wskaźnika do funkcji
    int (*wskaźnik_do_funkcji)(int, int);
    
    // Wybór operacji przez użytkownika
    int operacja;
    printf("Wybierz operację:\n");
    printf("1. Dodawanie\n");
    printf("2. Mnożenie\n");
    printf("3. Odejmowanie\n");
    scanf("%d", &operacja);
    
    // Ustawienie wskaźnika do odpowiedniej funkcji na podstawie wyboru użytkownika
    switch (operacja) {
        case 1:
            wskaźnik_do_funkcji = dodawanie;
            break;
        case 2:
            wskaźnik_do_funkcji = mnozenie;
            break;
        case 3:
            wskaźnik_do_funkcji = odejmowanie;
            break;
        default:
            printf("Nieprawidłowy wybór operacji.\n");
            return 1;
    }
    
    // Wczytanie liczb od użytkownika
    int liczba1, liczba2;
    printf("Podaj dwie liczby: ");
    scanf("%d %d", &liczba1, &liczba2);
    
    // Wywołanie wybranej funkcji za pomocą wskaźnika i wyświetlenie wyniku
    int wynik = wskaźnik_do_funkcji(liczba1, liczba2);
    printf("Wynik: %d\n", wynik);
    
    return 0;
}
