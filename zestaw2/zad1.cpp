// zad2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
   
    int x = 3;
    printf("%f/n", x);

    funkcja(&x)

        printf("%f/n", x);



    return 0;
}// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania



void funkcja(float *x) {
    *x = 2 * x;
}
