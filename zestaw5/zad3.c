#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


void append(Node** head, int value) {
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Błąd alokacji pamięci!");
        exit(1);
    }

    
    new_node->data = value;
    new_node->next = NULL;

    
    if (*head == NULL) {
        *head = new_node;
        return;
    }

   
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    
    last->next = new_node;
}


void remove_last(Node** head) {
    
    if (*head == NULL) {
        printf("Lista jest pusta, nie ma czego usunąć.\n");
        return;
    }

    
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    
    Node* second_last = *head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    
    free(second_last->next);

    
    second_last->next = NULL;
}


void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


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
    Node* head = NULL; 

    
    append(&head, 3);
    append(&head, 7);
    append(&head, 1);

    
    printf("Lista przed usunięciem ostatniego elementu: ");
    display(head);

    
    remove_last(&head);

    
    printf("Lista po usunięciu ostatniego elementu: ");
    display(head);

    
    delete_list(&head);

    return 0;
}
