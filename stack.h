#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

void push(StackNode** top, char data);
char pop(StackNode** top);
void print(struct StackNode *head);




#endif // STACK_H
