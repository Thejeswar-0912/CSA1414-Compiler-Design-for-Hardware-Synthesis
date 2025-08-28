#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 128

struct Entry {
    char name[64];
    char type[32];
};

struct Entry *sym;

int n = 0;

int find(const char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(sym[i].name, name) == 0)
            return i;
    }
    return -1;
}

int main() {
    char cmd[16], name[64], type[32];

    sym = malloc(MAX * sizeof(struct Entry));
    if (!sym) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    while (scanf("%15s", cmd) == 1) {
        if (strcmp(cmd, "insert") == 0) {
            scanf("%63s %31s", name, type);
            if (find(name) == -1) {
                strcpy(sym[n].name, name);
                strcpy(sym[n].type, type);
                n++;
                puts("OK");
            } else {
                puts("EXISTS");
            }
        }
        else if (strcmp(cmd, "lookup") == 0) {
            scanf("%63s", name);
            int i = find(name);
            if (i == -1)
                puts("NOT_FOUND");
            else
                printf("%s %s\n", sym[i].name, sym[i].type);
        }
        else if (strcmp(cmd, "delete") == 0) {
            scanf("%63s", name);
            int i = find(name);
            if (i == -1) {
                puts("NOT_FOUND");
            } else {
                sym[i] = sym[n - 1];
                n--;
                puts("DELETED");
            }
        }
        else if (strcmp(cmd, "list") == 0) {
            for (int i = 0; i < n; i++) {
                printf("%s %s\n", sym[i].name, sym[i].type);
            }
        }
    }

    free(sym);

    return 0;
}
