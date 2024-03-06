#include <stdio.h>
#include <string.h>


typedef struct {
    char imie[40];
    char nazwisko[40];
    char nr_telefon[10];
}Contact;


void dodajkontakt(Contact *tab, char imie[], char nazwisko[], char nrtelefonu[]) {
    int i = 0;
    while (tab[i].imie[0] != '\0' && i < 100) {
        i++;
    }
    if (i >= 100) {
        printf("Brak miejsca na dodanie nowego kontaktu\n");
        return;
    }
    strcpy(tab[i].imie, imie);
    strcpy(tab[i].nazwisko, nazwisko);
    strcpy(tab[i].nr_telefon, nrtelefonu);
    printf("Dodano nowy kontakt: %s %s\n", imie, nazwisko);
}

void wyszukiwanie_po_nazwisku(Contact *tab, char *nazwisko) {
    int i = 0;
    while (i < 100) {
        if (strcmp(tab[i].nazwisko, nazwisko) == 0) {
            printf("Znaleziono kontakt: %s %s %s\n", tab[i].imie, tab[i].nazwisko, tab[i].nr_telefon);
            return;
        }
        i++;
    }
    printf("Nie znaleziono kontaktu o nazwisku %s\n", nazwisko);
}

void usun_kontakt_po_nazwisku(Contact *tab, char nazwisko[]) {
    int i = 0;
    while (i < 100) {
        if (strcmp(tab[i].nazwisko, nazwisko) == 0) {
            printf("Usunięto kontakt: %s %s\n", tab[i].imie, tab[i].nazwisko);

            for (int j = i; j < 99; ++j) {
                strcpy(tab[j].imie, tab[j + 1].imie);
                strcpy(tab[j].nazwisko, tab[j + 1].nazwisko);
                strcpy(tab[j].nr_telefon, tab[j + 1].nr_telefon);
            }

            tab[99].imie[0] = '\0';
            tab[99].nazwisko[0] = '\0';
            tab[99].nr_telefon[0] = '\0';
            return;
        }
        i++;
    }
    printf("Nie znaleziono kontaktu o nazwisku: %s\n", nazwisko);
}
void wypiszKsiazke(const Contact *ksiazka, int liczba_kontaktow) {
    printf("Książka adresowa:\n");
    for (int i = 0; i < liczba_kontaktow; ++i) {
        printf("%s %s - %s\n", ksiazka[i].imie, ksiazka[i].nazwisko, ksiazka[i].nr_telefon);
    }
}

int main() {
    Contact kontakty[100] = {
            {"Jan", "Kowalski", "123456789"},
            {"Anna", "Nowak", "987654321"},
            {"Piotr", "Wiśniewski", "555333777"}
    };
    dodajkontakt(kontakty, "Adam", "Malinowski", "999888777");
    wyszukiwanie_po_nazwisku(kontakty,"Nowak");
    wypiszKsiazke(kontakty,4);
    return 0;
}
