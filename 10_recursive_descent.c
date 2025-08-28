#include <stdio.h>
#include <ctype.h>
const char *s; int i;
void E(); void T(); void F();
void E(){ T(); while(s[i]=='+'){ printf(" + "); i++; T(); } }
void T(){ F(); while(s[i]=='*'){ printf(" * "); i++; F(); } }
void F(){ if(isdigit(s[i])){ while(isdigit(s[i])) putchar(s[i++]); } else if(s[i]=='('){ putchar('('); i++; E(); if(s[i]==')'){ putchar(')'); i++; } } }
int main(){ static char buf[1024]; if(!fgets(buf,sizeof(buf),stdin)) return 0; s=buf; i=0; E(); putchar('\n'); return 0; }
