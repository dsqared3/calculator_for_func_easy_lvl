#include "operations.h"

#include <stdio.h>

int operations_prioryty(char c) {
    int flag = 0;
    switch (c) {
        case '+':
        case '-':
            flag = 1;
            break;
        case '*':
        case '/':
            flag = 2;
            break;
        case 's':
        case 'c':
        case 't':
        case 'C':
            flag = 3;
            break;
        case 'S':
        case 'l':
            flag = 4;
            break;
        case '~':
            flag = 5;
            break;
        default:
            flag = 0;
            break;
    }
    return flag;
}