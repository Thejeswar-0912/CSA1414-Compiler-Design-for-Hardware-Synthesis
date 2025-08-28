%{
#include <string.h>
%}
ID   [A-Za-z_][A-Za-z0-9_]*
NUM  [0-9]+
OP   [+\-*/=<>!&|]+
WS   [ \t\r\n]+
STR  \"([^\\\n]|\\.)*\"
%%
{WS}           ;
"#include"<[^>\n]+>   { printf("INCLUDE %s\n", yytext); }
{STR}          { printf("STRING %s\n", yytext); }
{NUM}          { printf("NUMBER %s\n", yytext); }
{ID}           { printf("ID %s\n", yytext); }
{OP}           { printf("OP %s\n", yytext); }
.              { printf("SYM %s\n", yytext); }
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
