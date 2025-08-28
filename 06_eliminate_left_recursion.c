#include <stdio.h>
#include <string.h>
// Input like: A->Aalpha|A beta|gamma|delta   (spaces optional)
// Output eliminates immediate left recursion for A
int main(){
    char line[1024]; if(!fgets(line,sizeof(line),stdin)) return 0;
    char A; if(sscanf(line," %c->",&A)!=1) return 0;
    char *p=strchr(line,'>'); if(!p) return 0; p++;
    char alphas[20][256], betas[20][256]; int na=0, nb=0;
    char *tok=strtok(p,"|\n");
    while(tok){
        while(*tok==' ') tok++;
        if(tok[0]==A){
            tok++; strcpy(alphas[na++], tok);
        } else {
            strcpy(betas[nb++], tok);
        }
        tok=strtok(NULL,"|\n");
    }
    if(na==0){ printf("%c->%s",A,p); return 0; }
    printf("%c->",A);
    for(int i=0;i<nb;i++){ if(i) printf("|"); printf("%s%c'",betas[i],A); }
    printf("\n%c'->",A);
    for(int i=0;i<na;i++){ if(i) printf("|"); printf("%s%c'",alphas[i],A); }
    printf("|ε\n");
    return 0;
}
