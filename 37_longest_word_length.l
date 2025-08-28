%{
int maxlen=0;
%}
WORD [A-Za-z]+
%%
{WORD} { if(yyleng>maxlen) maxlen=yyleng; }
.|\n   ;
%%
int yywrap(){ return 1; }
int main(){ yylex(); printf("max=%d\n", maxlen); return 0; }
