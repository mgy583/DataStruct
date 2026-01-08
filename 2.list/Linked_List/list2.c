#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* create_node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insert_at_end(Node* head, int data) {
    Node* new_node = create_node(data);
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_at_beginning(Node* head, int data) {
    Node* new_node = create_node(data);
    new_node->next = head->next;
    head->next = new_node; 
}

void insert_at_position(Node* head, int data, int position){
    Node* new_node = create_node(data);
    for(int i=0; i < position-1; i++){
        head = head->next;
    }
    new_node->next = head->next;
    head->next = new_node;
    new_node->prev = head;
    new_node->data = data;
    if(new_node->next != NULL){
        new_node->next->prev = new_node;
    }
}

void list_reverse(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    while(current != NULL) {
        Node* next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void display_list(Node* head) {
    Node* temp = head;
    while(temp!=NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    Node* head = create_node(0); // Dummy head node

    insert_at_end(head, 10);
    insert_at_end(head, 20);
    insert_at_beginning(head, 5);
    insert_at_position(head, 15, 2); // Insert 15 at position 2

    printf("Doubly Linked List: ");
    display_list(head->next); // Skip dummy head node
                              

    printf("Doubly Linked List(reverse): ");
    list_reverse(&head->next);
    display_list(head->next); // Skip dummy head node

    return 0;
}