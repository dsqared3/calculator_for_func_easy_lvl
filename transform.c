#include "transform.h"

void push_v2(struct struct_v2 **top, double data) {
    struct struct_v2 *tmp = malloc(sizeof(struct struct_v2));
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

double pop_v2(struct struct_v2 **top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct struct_v2 *temp = *top;
    double pop_v2 = temp->data;
    *top = temp->next;
    free(temp);

    return pop_v2;
}

int misdigit(char c) {
    int flag = 0;
    if (c >= '0' && c <= '9') {
        flag = 1;
    } else
        flag = 0;
    return flag;
}

double calculate(char *postfix, double result) {
    struct struct_v2 *stack = NULL;
    int len = strlen(postfix);
    for (int i = 0; i < len; i++) {
        if (misdigit(postfix[i])) {
            double tmp = 0;
            while (misdigit(postfix[i])) {
                tmp = tmp * 10 + (int)(postfix[i] - '0');
                i++;
            }
            i--;
            push_v2(&stack, tmp);
        } else if (postfix[i] == 'x') {
            push_v2(&stack, result);
        } else if (strchr("+-*/", postfix[i]))
            operations_with_2val(&stack, postfix[i]);
        else if (postfix[i] != ' ')
            operations_with_1val(&stack, postfix[i]);
    }
    double result_value = pop_v2(&stack);
    return result_value;
}

void operations_with_2val(struct struct_v2 **stack, char x) {
    {
        double val1 = pop_v2(stack);
        double val2 = pop_v2(stack);
        switch (x) {
            case '+':
                push_v2(stack, val2 + val1);
                break;
            case '-':
                push_v2(stack, val2 - val1);
                break;
            case '*':
                push_v2(stack, val2 * val1);
                break;
            case '/':
                push_v2(stack, val2 / val1);
                break;
        }
    }
}

void operations_with_1val(struct struct_v2 **stack, char x) {
    double val = pop_v2(stack);
    switch (x) {
        case 's':
            push_v2(stack, sin(val));
            break;
        case 'c':
            push_v2(stack, cos(val));
            break;
        case 't':
            push_v2(stack, tan(val));
            break;
        case 'C':
            push_v2(stack, cos(val) / sin(val));
            break;
        case 'S':
            push_v2(stack, sqrt(val));
            break;
        case 'l':
            push_v2(stack, log(val));
            break;
        case '~':
            push_v2(stack, -val);
            break;
    }
}