#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


void push(Node** head, int value) {
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Błąd alokacji pamięci!");
        exit(1);
    }

    
    new_node->data = value;

    
    new_node->next = *head;

    
    *head = new_node;
}


void pop(Node** head) {
    if (*head == NULL) {
        printf("Lista jest pusta, nie ma czego usunąć.\n");
        return;
    }

    
    Node* temp = *head;

    
    *head = (*head)->next;

    
    free(temp);
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

    
    push(&head, 3);
    push(&head, 7);
    push(&head, 1);

    
    printf("Lista przed usunięciem pierwszego elementu: ");
    display(head);

    
    pop(&head);

    
    printf("Lista po usunięciu pierwszego elementu: ");
    display(head);

    
    delete_list(&head);

    return 0;
}
