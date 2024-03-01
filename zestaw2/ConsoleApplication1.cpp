

#include <stdio.h>

typedef struct {
    char imie[30];
    float ocena;
}Student;


void sortuj(Student *tab, int rozmiar) {
    for (int j = 0; j < rozmiar - 1; j++) {
        for (int i = 0; i < rozmiar - 1; i++) {
            if (tab[i].ocena < tab[i + 1].ocena) {
                Student tymczasowe = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tymczasowe;

            }
        }
    }
};

void wyswietl_tablice(Student* tab, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        printf("Imie: %s, Ocena: %.1f\n", tab[i].imie, tab[i].ocena);
    }
}


int main()
{
    Student stud1 = { "Michal",3.5 };
    Student stud2 = { "Maciek",4.5 };
    Student stud3 = { "Marcin",4 };
    Student stud4 = { "Martin",5 };
    Student tab[] = { stud1,stud2,stud3,stud4};

    int rozmiar = sizeof(tab)/sizeof(tab[0]);
    wyswietl_tablice(tab, rozmiar);
    sortuj(tab, rozmiar);
    wyswietl_tablice(tab, rozmiar);
    return 0;
}

