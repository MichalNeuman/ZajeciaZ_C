
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


void add_first(Node** head, int value) {
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Błąd alokacji pamięci!");
        exit(1);
    }

    
    new_node->data = value;

    
    new_node->next = *head;

    
    *head = new_node;
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

    
    add_first(&head, 3);
    add_first(&head, 7);
    add_first(&head, 1);

   
    printf("Lista: ");
    display(head);

    
    delete_list(&head);

    return 0;
}
