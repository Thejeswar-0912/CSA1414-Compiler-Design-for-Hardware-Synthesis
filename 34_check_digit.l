%{
%}
%%
^[0-9]\n?$   { printf("DIGIT\n"); }
^.*$         { printf("NOT_DIGIT\n"); }
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
