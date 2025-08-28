#include <stdio.h>
#include <ctype.h>
int main() {
    char id[100];
    int i = 0, ok = 1;
    printf("Enter an identifier: ");
    scanf("%s", id);

    if (!(isalpha(id[0]) || id[0] == '_')) {
        printf("INVALID\n");
        return 0;
    }
    for (i = 1; id[i] != '\0'; i++) {
        if (!(isalnum(id[i]) || id[i] == '_')) {
            ok = 0;
            break;
        }
    }
    if (i > 64)
        ok = 0;

    if (ok)
        printf("VALID\n");
    else
        printf("INVALID\n");

    return 0;
}
