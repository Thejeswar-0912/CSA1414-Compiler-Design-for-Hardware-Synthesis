%{
#include <stdio.h>
%}

%%
[0-9]{2}/[0-9]{2}/[0-9]{4}    { printf("Valid DOB\n"); }
.|\n                         { printf("Invalid DOB\n"); }
%%

int yywrap() { return 1; }

int main() {
    yylex();
    return 0;
}