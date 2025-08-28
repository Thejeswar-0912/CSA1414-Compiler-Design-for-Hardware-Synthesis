%{
%}
%%
foo     { printf("bar"); }
.|\n    { printf("%s", yytext); }
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
