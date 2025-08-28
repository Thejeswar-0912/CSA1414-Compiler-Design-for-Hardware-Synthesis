%{
#include <stdio.h>
%}

%%
https?:\/\/[a-zA-Z0-9\.\/]+    { printf("Valid URL\n"); }
.|\n                           { printf("Invalid URL\n"); }
%%

int yywrap() { return 1; }

int main() {
    yylex();
    return 0;
}