#include <stdio.h>
#include <stdlib.h>

// Definicja struktury elementu listy
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Funkcja do dodawania elementu na początek listy
void push(Node** head, int value) {
    // Utwórz nowy element
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Błąd alokacji pamięci!");
        exit(1);
    }

    // Ustaw wartość nowego elementu
    new_node->data = value;

    // Powiąż nowy element, aby wskazywał na obecny początek listy
    new_node->next = *head;

    // Ustaw nowy element jako początek listy
    *head = new_node;
}

// Funkcja do usuwania pierwszego elementu z listy
void pop(Node** head) {
    if (*head == NULL) {
        printf("Lista jest pusta, nie ma czego usunąć.\n");
        return;
    }

    // Zapamiętaj pierwszy element
    Node* temp = *head;

    // Przesuń głowę listy na następny element
    *head = (*head)->next;

    // Zwolnij pamięć zajmowaną przez pierwotny pierwszy element
    free(temp);
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

    // Dodawanie kilku elementów na początek listy
    push(&head, 3);
    push(&head, 7);
    push(&head, 1);

    // Wyświetlenie listy przed usuwaniem pierwszego elementu
    printf("Lista przed usunięciem pierwszego elementu: ");
    display(head);

    // Usunięcie pierwszego elementu
    pop(&head);

    // Wyświetlenie listy po usunięciu pierwszego elementu
    printf("Lista po usunięciu pierwszego elementu: ");
    display(head);

    // Usunięcie listy (zwolnienie pamięci)
    delete_list(&head);

    return 0;
}
