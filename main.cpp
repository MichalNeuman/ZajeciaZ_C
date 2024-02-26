#include <stdio.h>

int sum_of_multiples(int number) {
    if (number < 0) {
        return 0;
    }

    int sum = 0;
    for (int i = 3; i < number; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    int number;
    printf("Podaj liczbê: ");
    scanf("%d", &number);

    int result = sum_of_multiples(number);
    printf("Suma wielokrotnoœci 3 lub 5 poni¿ej %d wynosi: %d\n", number, result);

    return 0;
}