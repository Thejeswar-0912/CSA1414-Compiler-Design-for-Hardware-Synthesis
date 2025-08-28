%{
%}
%%
^[AEIOUaeiou][A-Za-z]*$   { printf("ACCEPT\n"); }
^.*$                      { printf("REJECT\n"); }
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
