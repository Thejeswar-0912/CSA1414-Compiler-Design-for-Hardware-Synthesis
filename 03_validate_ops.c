#include <stdio.h>
#include <ctype.h>

int main() {
    char expr[100];
    int i = 0, valid = 1;

    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);

    while (expr[i] != '\0' && expr[i] != '\n') {
        char c = expr[i];
        if (isalnum(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == ' ' || c == '=') {
            // allowed characters
        } else {
            valid = 0;
            break;
        }
        i++;
    }

    if (valid)
        printf("VALID\n");
    else
        printf("INVALID\n");

    return 0;
}
