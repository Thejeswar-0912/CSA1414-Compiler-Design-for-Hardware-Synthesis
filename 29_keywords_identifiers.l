%{
#include <string.h>
char *kws[]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","inline","int","long","register","restrict","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while",0};
int iskw(const char*s){ for(int i=0;kws[i];i++) if(strcmp(kws[i],s)==0) return 1; return 0; }
%}
ID   [A-Za-z_][A-Za-z0-9_]*
WS   [ \t\r\n]+
%%
{WS}     ;
{ID}     { if(iskw(yytext)) printf("KEYWORD %s\n",yytext); else printf("IDENTIFIER %s\n",yytext); }
.        ;
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
