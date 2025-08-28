%option noyywrap
%{
#include <stdio.h>
FILE *out;
int commentCount = 0;
%}

%%
"//".*                              { commentCount++; }
"/*"([^*]|\*+[^*/])*"*/"            { commentCount++; }
.|\n                                { fputc(yytext[0], out); }
%%

int main() {
    out = fopen("output.c", "w");
    if (!out) {
        perror("output.c");
        return 1;
    }
    yylex();
    fclose(out);
    printf("Number of comment lines: %d\n", commentCount);
    return 0;
}