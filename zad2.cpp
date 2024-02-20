#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 2

int main() {
    int grades[SUBJECTS][STUDENTS] = {
        {3, 2, 4, 4, 3},  // Oceny z matematyki
        {2, 4, 2, 5, 5}   // Oceny z fizyki
    };

    double sum[SUBJECTS] = { 0 }; // Suma ocen dla każdego przedmiotu

    // Obliczanie sumy ocen dla każdego przedmiotu
    for (int i = 0; i < SUBJECTS; i++) {
        for (int j = 0; j < STUDENTS; j++) {
            sum[i] += grades[i][j];
        }
    }

    // Obliczanie średniej ocen dla każdego przedmiotu
    double avg[SUBJECTS];
    for (int i = 0; i < SUBJECTS; i++) {
        avg[i] = sum[i] / STUDENTS;
    }

    // Wyświetlanie średnich ocen dla każdego przedmiotu
    printf("Średnia ocen z matematyki: %.2f\n", avg[0]);
    printf("Średnia ocen z fizyki: %.2f\n", avg[1]);

    return 0;
}