%{
%}
D   [0-9]
F   {D}+(\.{D}+)?
%%
{F}      { printf("%s\n", yytext); }
.|\n     ;
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
