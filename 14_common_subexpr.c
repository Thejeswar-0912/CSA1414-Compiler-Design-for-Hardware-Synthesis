#include <stdio.h>
#include <string.h>
// Input lines like: t = a + b
// Reuse previously seen RHS
struct Entry{ char rhs[128]; char name[16]; } e[256]; int n=0, temp=1;
int main(){
    char lhs[16], eq[4], rhs[128];
    while (scanf("%15s %3s %[^\n]\n", lhs, eq, rhs)==3){
        int found=-1;
        for(int i=0;i<n;i++) if(strcmp(e[i].rhs,rhs)==0) { found=i; break; }
        if(found==-1){ sprintf(e[n].name,"t%d",temp++); strcpy(e[n].rhs,rhs); found=n++; printf("%s = %s\n", e[found].name, rhs); }
        printf("%s = %s\n", lhs, e[found].name);
    }
    return 0;
}
