%{
%}
MOB  [6-9][0-9]{9}
%%
^{MOB}$   { printf("VALID\n"); }
^.*$      { printf("INVALID\n"); }
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
