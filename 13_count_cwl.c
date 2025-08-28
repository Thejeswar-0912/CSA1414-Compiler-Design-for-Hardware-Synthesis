#include <stdio.h>
#include <ctype.h>
int main(){ int c, chars=0, words=0, lines=0, inw=0; while((c=getchar())!=EOF){ chars++; if(c=='\n') lines++; if(isspace(c)) inw=0; else if(!inw){ inw=1; words++; } } printf("chars=%d\nwords=%d\nlines=%d\n",chars,words,lines); return 0; }
