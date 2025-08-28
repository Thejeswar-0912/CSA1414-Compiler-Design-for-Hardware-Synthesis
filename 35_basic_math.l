%{
int a,b;
%}
WS   [ \t]+
NUM  -?[0-9]+
%%
^{NUM}{WS}\+{WS}{NUM}$ { sscanf(yytext,"%d + %d",&a,&b); printf("%d\n",a+b); }
^{NUM}{WS}\-{WS}{NUM}$ { sscanf(yytext,"%d - %d",&a,&b); printf("%d\n",a-b); }
^{NUM}{WS}\*{WS}{NUM}$ { sscanf(yytext,"%d * %d",&a,&b); printf("%d\n",a*b); }
^{NUM}{WS}\/{WS}{NUM}$ { sscanf(yytext,"%d / %d",&a,&b); if(b) printf("%d\n",a/b); else printf("DIV0\n"); }
^.*$                   { /* ignore */ }
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
