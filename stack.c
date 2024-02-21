#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void push(struct StackNode **top, char data) {
    struct StackNode *tmp = malloc(sizeof(struct StackNode));
    if (*top == NULL) {
        tmp->data = data;
        tmp->next = NULL;
        (*top) = tmp;
    } else {
        tmp->data = data;
        tmp->next = *top;
        (*top) = tmp;
    }
}

char pop(StackNode **top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    StackNode *temp = *top;
    char pop = temp->data;
    *top = temp->next;
    free(temp);

    return pop;
}

/*
void print(struct StackNode *head) {
  while (head != NULL) {
    printf("%c ", head->data);
    head = head->next;
  }
}
*/