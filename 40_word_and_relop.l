%{
%}
ID   [A-Za-z]+
RELOP (<=|>=|==|!=|<|>)
WS   [ \t]+
%%
^{ID}{WS}{RELOP}{WS}{ID}$   { printf("OK\n"); }
^.*$                        { printf("NO\n"); }
%%
int yywrap(){ return 1; }
int main(){ yylex(); return 0; }
