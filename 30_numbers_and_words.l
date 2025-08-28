%{
%}
NUM  [+-]?[0-9]+
WORD [A-Za-z]+
WS   [ \t\r\n]+
%%
{NUM}  { printf("NUMBER %s\n", yytext); }
{WORD} { printf("WORD %s\n", yytext); }
{WS}   ;
.      ;
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
