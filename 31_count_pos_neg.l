%{
int pos=0, neg=0;
%}
NUM [+-]?[0-9]+
%%
\-[0-9]+   { neg++; }
\+?[0-9]+  { pos++; }
.|\n       ;
%%
int yywrap(){ return 1; }
int main(){ yylex(); printf("positive=%d\nnegative=%d\n",pos,neg); return 0; }
