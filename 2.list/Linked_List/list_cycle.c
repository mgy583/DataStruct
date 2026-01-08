#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node *creat_node(int value, Node* next){
    Node *n = malloc(sizeof *n);
    n->data = value;
    n->next = next;
    return n;
}

void node_print(Node* n) {
    if (!n)
        return;
    Node *cur = n;
    do{
        printf("%d -> ", cur->data);
        cur = cur->next;
    }while(cur != n);
    printf("back to head\n");
}

void list_destroy(Node *head)
{
    while (head) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int count_circle(Node *head){
    if(!head) return 0;
    Node *slow = head;
    Node *fast = head;
    int count = 1;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            Node *current = slow;
            while(current->next != slow){
                count ++;
                current = current->next;
            }
        }
    }
    return count;
}

int main(){
    // Node *head = malloc(sizeof(Node));
    Node *head = NULL;
    for(int i = 0; i < 10; i++) {
        head = creat_node(i, head);
    }

    Node *tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head;

    node_print(head);
    // break the cycle before destroying to avoid infinite loop
    tail->next = NULL;
    list_destroy(head);
    
    int cycle_length = count_circle(head);
    printf("Cycle length: %d\n", cycle_length);    
    
    return 0;
}