#include <stdio.h>
int main(){ int c, ws=0, nl=0; while((c=getchar())!=EOF){ if(c==' '||c=='\t') ws++; else if(c=='\n') nl++; } printf("whitespaces=%d\nnewlines=%d\n",ws,nl); return 0; }
