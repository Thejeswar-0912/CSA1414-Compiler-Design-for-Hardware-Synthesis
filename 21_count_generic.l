%{
int chars=0, lines=0, words=0, inw=0;
%}
%%
[ \t\r]+     { chars+=yyleng; inw=0; }
\n           { chars++; lines++; inw=0; }
[^ \t\r\n]+  { chars+=yyleng; words++; inw=1; }
.            { chars++; }
%%
int yywrap(){ return 1; }
int main(){ yylex(); printf("chars=%d\nlines=%d\nwords=%d\n",chars,lines,words); return 0; }
