%{
int line=1;
%}
%%
^.*\n   { printf("%4d: %s", line++, yytext); }
.+$     { printf("%4d: %s\n", line++, yytext); }
\n      { printf("%4d: \n", line++); }
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
