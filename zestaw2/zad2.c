#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void funkcja(float *x) {
    *x = 2 * *x;
}

int main() {

    float x = 3.5;
    printf("%f\n", x);

    funkcja(&x);

    printf("%f\n", x);



    return 0;
}// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania





