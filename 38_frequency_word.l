%{
int count=0;
%}
WORD [Tt][Hh][Ee]
%%
{WORD} { count++; }
.|\n   ;
%%
int yywrap(){ return 1; }
int main(){ yylex(); printf("freq=%d\n",count); return 0; }
