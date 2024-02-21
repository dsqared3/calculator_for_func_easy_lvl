#include "graph.h"

int main() {
    struct StackNode *stack = NULL;
    char *string_for_result = malloc(100 * sizeof(char));
    char *line = scanf_formula();
    base_calculated(&stack, line, string_for_result);
    draw_point_in_field(string_for_result);
    free(string_for_result);
    free(line);
    return 0;
}

char *scanf_formula() {
    char c = '0';
    int size = 0;
    char *line = NULL;
    char *temp = NULL;

    while (c != '\n' && c != EOF) {
        scanf("%c", &c);
        temp = (char *)realloc(line, (size + 1) * sizeof(char));

        if (temp != NULL) {
            line = temp;
            line[size] = c;
            size++;
        } else {
            free(line);
            line = NULL;
        }
    }
    return line;
}

void base_calculated(struct StackNode **stack, char *line, char *string_for_result) {
    int i = 0;  //Для строки
    int j = 0;  //Для результирующегоs
    int *p_j = &j;
    int *p_i = &i;
    while (line[i] != '\n') {
        if (line[i] == '-' && i == 0) {
            string_for_result[j++] = ' ';
            function_for_stack(stack, string_for_result, '~', p_j);
        } else if (line[i] == '-' && line[i - 1] == '(') {
            string_for_result[j++] = ' ';
            function_for_stack(stack, string_for_result, '~', p_j);
        } else if (line[i] == ')') {
            while (((*stack)->data) != '(') {
                string_for_result[j++] = pop(stack);
            }
            pop(stack);
        } else if (line[i] == '(')
            push(stack, '(');
        else if ((line[i] >= '0' && line[i] <= '9') || line[i] == 'x') {
            string_for_result[j++] = line[i];
        } else if (line[i] == '+' || line[i] == '-' || line[i] == '/' || line[i] == '*') {
            string_for_result[j++] = ' ';
            function_for_stack(stack, string_for_result, line[i], p_j);
        }
        base_calculated_for_words(stack, line, string_for_result, p_i, p_j);
        i++;
    }
    while ((*stack) != NULL) {
        transform_char_to_text(string_for_result, pop(stack), p_j);
    }
}

void base_calculated_for_words(struct StackNode **stack, const char *line, char *string_for_result, int *p_i,
                               int *p_j) {
    int i = *p_i;
    int j = *p_j;
    if (line[i] == 'l' && line[i + 1] == 'n') {  //натурлогарифм
        string_for_result[j++] = ' ';
        function_for_stack(stack, string_for_result, 'l', p_j);
        i++;
    } else if (line[i] == 's' && line[i + 1] == 'q') {  // sqrt
        string_for_result[j++] = ' ';
        function_for_stack(stack, string_for_result, 'S', p_j);
        i += 3;
    } else if (line[i] == 'c' && line[i + 1] == 'o') {  // cos
        string_for_result[j++] = ' ';
        function_for_stack(stack, string_for_result, 'c', p_j);
        i += 2;
    } else if (line[i] == 's' && line[i + 1] == 'i') {  // sin
        string_for_result[j++] = ' ';
        function_for_stack(stack, string_for_result, 's', p_j);
        i += 2;
    } else if (line[i] == 't' && line[i + 1] == 'a') {  // tng
        string_for_result[j++] = ' ';
        function_for_stack(stack, string_for_result, 't', p_j);
        i += 2;
    } else if (line[i] == 'c' && line[i + 1] == 't') {  // ctg
        string_for_result[j] = ' ';
        j++;
        function_for_stack(stack, string_for_result, 'C', p_j);
        i += 2;
    }
    *p_i = i;
    *p_j = j;
}

void function_for_stack(struct StackNode **stack, char *string_for_result, char i, int *p_j) {
    if ((*stack) == NULL) {
        push(stack, i);
    } else {
        if (operations_prioryty((*stack)->data) < operations_prioryty(i)) {
            push(stack, i);
        } else {
            while ((*stack) != NULL && (operations_prioryty((*stack)->data) >= operations_prioryty(i))) {
                transform_char_to_text(string_for_result, pop(stack), p_j);
            }
            push(stack, i);
        }
    }
}

void transform_char_to_text(char *string_for_result, char i, int *p_j) {
    int j = *p_j;
    if (i == 's') {
        string_for_result[j++] = 's';
    } else if (i == 'c') {
        string_for_result[j++] = 'c';
    } else if (i == 't') {
        string_for_result[j++] = 't';
    } else if (i == 'C') {
        string_for_result[j++] = 'C';
    } else if (i == 'S') {
        string_for_result[j++] = 'S';
    } else if (i == 'l') {
        string_for_result[j++] = 'l';
    } else if (i == '*')
        string_for_result[j++] = '*';
    else if (i == '/')
        string_for_result[j++] = '/';
    else if (i == '+')
        string_for_result[j++] = '+';
    else if (i == '-')
        string_for_result[j++] = '-';
    else if (i == '~')
        string_for_result[j++] = '~';
    *p_j = j;
}

void draw_point_in_field(char *string_for_result) {
    puts("\x1B[2J");
    int n = 25, m = 80;
    const double x_min = 0;
    const double x_max = 4 * M_PI;
    const double y_min = 1;
    const double y_max = -1;
    for (int i = 0; i < n; i++) {
        double y = y_max - i * (y_max - y_min) / (n - 1);  // y = 1 - i/12
        for (int j = 0; j < m; j++) {
            double x = x_min + j * (x_max - x_min) / (m - 1);  // 3.14+j * 12.56/79
            double result = calculate(string_for_result, x);
            if (fabs(result - y) < 0.06) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

/* // если нужно показать красивую префиксную запись
void transform_char_to_text(char *string_for_result, char i, int *p_j) {
  int j = *p_j;
  if (i == 's') {
    string_for_result[j++] = 's';
    string_for_result[j++] = 'i';
    string_for_result[j++] = 'n';
  } else if (i == 'c') {
    string_for_result[j++] = 'c';
    string_for_result[j++] = 'o';
    string_for_result[j++] = 's';
  } else if (i == 't') {
    string_for_result[j++] = 't';
    string_for_result[j++] = 'a';
    string_for_result[j++] = 'n';
  } else if (i == 'C') {
    string_for_result[j++] = 'c';
    string_for_result[j++] = 't';
    string_for_result[j++] = 'g';
  } else if (i == 'S') {
    string_for_result[j++] = 's';
    string_for_result[j++] = 'q';
    string_for_result[j++] = 'r';
    string_for_result[j++] = 't';
  } else if (i == 'l') {
    string_for_result[j++] = 'l';
    string_for_result[j++] = 'n';
  } else if (i == '*')
    string_for_result[j++] = '*';
  else if (i == '/')
    string_for_result[j++] = '/';
  else if (i == '+')
    string_for_result[j++] = '+';
  else if (i == '-')
    string_for_result[j++] = '-';
  *p_j = j;
}
*/