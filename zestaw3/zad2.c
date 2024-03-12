#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funkcja do alokacji pamięci dla macierzy
int** alokujMacierz(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Błąd alokacji pamięci!\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Błąd alokacji pamięci!\n");
            exit(1);
        }
    }

    return matrix;
}

// Funkcja do zwalniania pamięci zaalokowanej dla macierzy
void zwolnijMacierz(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Funkcja do wypełniania macierzy losowymi liczbami
void wypelnijMacierz(int** matrix, int rows, int cols) {
    srand(time(NULL)); // Inicjalizacja generatora liczb pseudolosowych

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; // Losowa liczba od 0 do 99
        }
    }
}

// Funkcja do wyświetlania zawartości macierzy
void wyswietlMacierz(int** matrix, int rows, int cols) {
    printf("Zawartość macierzy:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Podaj liczbę wierszy macierzy: ");
    scanf("%d", &rows);
    printf("Podaj liczbę kolumn macierzy: ");
    scanf("%d", &cols);

    // Alokacja pamięci dla macierzy
    int** matrix = alokujMacierz(rows, cols);

    // Wypełnienie macierzy losowymi liczbami
    wypelnijMacierz(matrix, rows, cols);

    // Wyświetlenie zawartości macierzy
    wyswietlMacierz(matrix, rows, cols);

    // Zwolnienie zaalokowanej pamięci
    zwolnijMacierz(matrix, rows);

    return 0;
}
