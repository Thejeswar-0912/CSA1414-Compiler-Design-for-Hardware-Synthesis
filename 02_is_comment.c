#include <stdio.h>
int main(){
    char s[1024];
    if(!fgets(s,sizeof(s),stdin)) return 0;
    if(s[0]=='/' && s[1]=='/') { puts("COMMENT"); return 0; }
    if(s[0]=='/' && s[1]=='*'){
        for(int i=2;s[i];++i) if(s[i-1]=='*' && s[i]=='/'){ puts("COMMENT"); return 0; }
    }
    puts("NOT_COMMENT");
    return 0;
}
