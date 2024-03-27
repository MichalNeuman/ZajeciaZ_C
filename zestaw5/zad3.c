#include <stdio.h>
#include <stdlib.h>

// Definicja struktury elementu listy
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Funkcja do dodawania elementu na koniec listy
void append(Node** head, int value) {
    // Utwórz nowy element
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Błąd alokacji pamięci!");
        exit(1);
    }

    // Ustaw wartość nowego elementu
    new_node->data = value;
    new_node->next = NULL;

    // Jeśli lista jest pusta, ustaw nowy element jako głowę listy
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // W przeciwnym razie, znajdź ostatni element listy
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    // Powiąż ostatni element z nowym elementem
    last->next = new_node;
}

// Funkcja do usuwania ostatniego elementu z listy
void remove_last(Node** head) {
    // Jeśli lista jest pusta, nie ma co usuwać
    if (*head == NULL) {
        printf("Lista jest pusta, nie ma czego usunąć.\n");
        return;
    }

    // Jeśli lista ma tylko jeden element, usuwamy ten element
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Znajdź przedostatni element
    Node* second_last = *head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    // Zwolnij pamięć zajmowaną przez ostatni element
    free(second_last->next);

    // Ustaw pole next przedostatniego elementu na NULL, aby odłączyć ostatni element od listy
    second_last->next = NULL;
}

// Funkcja do wyświetlania listy
void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Funkcja do usuwania listy
void delete_list(Node** head) {
    Node* current = *head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    Node* head = NULL; // Inicjalizacja pustej listy

    // Dodawanie kilku elementów na koniec listy
    append(&head, 3);
    append(&head, 7);
    append(&head, 1);

    // Wyświetlenie listy przed usunięciem ostatniego elementu
    printf("Lista przed usunięciem ostatniego elementu: ");
    display(head);

    // Usunięcie ostatniego elementu
    remove_last(&head);

    // Wyświetlenie listy po usunięciu ostatniego elementu
    printf("Lista po usunięciu ostatniego elementu: ");
    display(head);

    // Usunięcie listy (zwolnienie pamięci)
    delete_list(&head);

    return 0;
}
