#ifndef GRAPH_H
#define GRAPH_H

#include "operations.h"
#include "stack.h"
#include "transform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *scanf_formula();
void base_calculated(struct StackNode **stack, char *line, char *string_for_result);
void base_calculated_for_words(struct StackNode **stack, const char *line, char *string_for_result, int *p_i, int *p_j);
void function_for_stack(struct StackNode **stack, char *string_for_result, char i, int *p_j);
void transform_char_to_text(char *string_for_result, char i, int *p_j);
void draw_point_in_field(char *string_for_result);


#endif