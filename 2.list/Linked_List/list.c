#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *new_node() {
  Node *p = malloc(sizeof(Node));
  if(!p) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  p->data = 0;
  p->next = NULL;
  return p;
}

void push_front(Node **head, int data) {
  Node *p = new_node();
  p->next = *head;
  p->data = data;
  *head = p;
}

void push_back(Node **head, int data) {
  Node *p = new_node();
  if (*head == NULL) {
    *head = p;
    p->data = data;
    return;
  }
  Node *cur = *head;
  while (cur->next) {
    cur = cur->next;
  }
  cur->next = p;
  p->data = data;
}

void print_node(Node *head) {
  for (Node *cur = head; cur != NULL; cur = cur->next) {
    printf("%d->", cur->data);
  }
  printf("NULL\n");
}

void destory_node(Node *head) {
  for(Node *cur = head; cur != NULL; ) {
    Node *tmp = cur;
    cur = cur->next;
    free(tmp);
  }
}

int main() {
  Node *head = NULL;

  push_back(&head, 4);
  push_back(&head, 5);
  push_back(&head, 6);

  push_front(&head, 3);
  push_front(&head, 2);
  push_front(&head, 1);

  print_node(head);

  destory_node(head);

  return 0;
}
