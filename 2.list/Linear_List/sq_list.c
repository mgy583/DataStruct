#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX_SIZE 10
typedef struct {
    int data[MAX_SIZE];
    int length;
} SqList;

void init_list(SqList* L) {
    for(int i = 0; i < MAX_SIZE; i++) {
        L->data[i] = 0;
    }
    L->length = 0;
}

bool list_empty(SqList* L) {
    if(L->length == 0) {
        printf("The list is empty.\n");
        return true;
    } else {
        printf("The list is not empty.\n");
        return false;
    }
}

int list_length(SqList* L) {
    return L->length;
}

bool get_elem(SqList* L, int index, int* e) {
    if(index < 1 || index > L->length || list_empty(L)) {
        return false;
    }
    *e = L->data[index-1];
    return true;
}

int locate_elem(SqList* L, int e) {
    for(int i = 0; i < L->length; i++){
        if(L->data[i] == e) {
            return i + 1;
        }
    }
    return -1;
}   

bool list_insert(SqList *L, int index, int e) {
    if(index < 1 || index > L->length + 1 || L->length == MAX_SIZE) {
        return false;
    }
    for(int i = L->length; i >= index; --i){
        L->data[i] = L->data[i-1]; 
    }
    L->data[index-1] = e;
    L->length++;
    return true;   
}

bool list_delete(SqList *L, int index) {
    if(index < 1 || index > L->length || list_empty(L)) {
        return false;
    }
    for(int i = index; i < L->length; i++) {
        L->data[i-1] = L->data[i];
    }
    L->length--;
    return true;
}

void clear_list(SqList *L) {
    for (int i = 0; i < MAX_SIZE; i++) {
        L->data[i] = 0;
    }
    L->length = 0;
}

void destroy_list(SqList *L) {
    free(L);
}

void print_list(SqList *L) {
    if(list_empty(L)) {
        return;
    }
    for(int i=0; i < L->length; i++) {
        printf("%d -", L->data[i]);
    }
    printf("END\n");
}

void reverse_list(SqList *L) {
    int start = 0;
    int end = L->length - 1;
    while(start < end) {
        int tmp = L->data[start];
        L->data[start] = L->data[end];
        L->data[end] = tmp;
        start++;
        end--;  
    }
}

int main() {
    SqList *list = malloc(sizeof(SqList));

    init_list(list);
    list_insert(list, 1, 10);
    list_insert(list, 2, 20);
    list_insert(list, 3, 30);
    list_insert(list, 4, 40);
    list_insert(list, 5, 50);
    list_insert(list, 6, 60);

    int e;
    get_elem(list, 1, &e);

    print_list(list);

    int pos = locate_elem(list, 20);
    printf("position of element 20: %d\n", pos);

    reverse_list(list);
    print_list(list);

    list_delete(list, 1);
    print_list(list);

    clear_list(list);
    print_list(list);

    destroy_list(list);

    return 0;
}