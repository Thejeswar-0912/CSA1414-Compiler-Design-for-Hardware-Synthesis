#include <stdio.h>
#include <string.h>
// Input: A->alpha1|alpha2|...  (simple strings)
// Finds longest common prefix and factors once
int main(){
    char line[1024]; if(!fgets(line,sizeof(line),stdin)) return 0;
    char A; if(sscanf(line," %c->",&A)!=1) return 0;
    char *p=strchr(line,'>'); if(!p) return 0; p++;
    char alts[50][256]; int n=0;
    char *tok=strtok(p,"|\n");
    while(tok){ while(*tok==' ') tok++; strcpy(alts[n++],tok); tok=strtok(NULL,"|\n"); }
    if(n<2){ printf("%s", line); return 0; }
    int lcp=0; int cont=1;
    while(cont){
        char ch=alts[0][lcp];
        if(!ch){ break; }
        for(int i=1;i<n;i++){ if(alts[i][lcp]!=ch){ cont=0; break; } }
        if(cont) lcp++;
    }
    if(lcp==0){ printf("%s", line); return 0; }
    printf("%c->%.*s%c'\n",A,lcp,alts[0],A);
    printf("%c'->",A);
    for(int i=0;i<n;i++){ if(i) printf("|"); if((int)strlen(alts[i])==lcp) printf("ε"); else printf("%s", alts[i]+lcp); }
    printf("\n");
    return 0;
}
