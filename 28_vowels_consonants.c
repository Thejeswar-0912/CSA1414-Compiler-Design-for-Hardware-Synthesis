#include <stdio.h>
#include <ctype.h>
int main(){ int c,v=0,cn=0; while((c=getchar())!=EOF){ if(isalpha(c)){ char x=tolower(c); if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u') v++; else cn++; } } printf("vowels=%d\nconsonants=%d\n",v,cn); return 0; }
