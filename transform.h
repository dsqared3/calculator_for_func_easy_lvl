#ifndef OUTPUT_H
#define OUTPUT_H

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct struct_v2 {
    double data;
    struct struct_v2* next;
};

int misdigit(char c);
double calculate(char* postfix, double result);
double pop_v2(struct struct_v2 **top);
void push_v2(struct struct_v2 **top, double data);
void operations_with_1val(struct struct_v2 **stack , char x);
void operations_with_2val(struct struct_v2 **stack, char x);


#endif