#include <stdio.h>

// Definicja unii
union Dane {
    int calkowita;
    float zmiennoprzecinkowa;
    char znak;
};

int main() {
    // Inicjalizacja unii
    union Dane mojaUnia;

    // Przechowywanie i wyświetlanie wartości typu int
    mojaUnia.calkowita = 10;
    printf("Wartość typu int: %d\n", mojaUnia.calkowita);

    // Przechowywanie i wyświetlanie wartości typu float
    mojaUnia.zmiennoprzecinkowa = 3.14;
    printf("Wartość typu float: %f\n", mojaUnia.zmiennoprzecinkowa);

    // Przechowywanie i wyświetlanie znaku
    mojaUnia.znak = 'A';
    printf("Znak: %c\n", mojaUnia.znak);

    return 0;
}
