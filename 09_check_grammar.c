#include <stdio.h>
#include <ctype.h>
const char *s; int i;
int E(); int T(); int F();
int E(){ if(!T()) return 0; while(s[i]=='+'){ i++; if(!T()) return 0; } return 1; }
int T(){ if(!F()) return 0; while(s[i]=='*'){ i++; if(!F()) return 0; } return 1; }
int F(){ 
    // number
    if (isdigit(s[i])) {
        while (isdigit(s[i])) i++;
        return 1;
    }
    // identifier "id"
    if (s[i] == 'i' && s[i+1] == 'd') {
        i += 2;
        return 1;
    }
    if(s[i]=='('){ i++; if(!E()) return 0; if(s[i]!=')') return 0; i++; return 1;} return 0; }
int main(){ static char buf[1024]; if(!fgets(buf,sizeof(buf),stdin)) return 0; s=buf; i=0; int ok=E() && (s[i]=='\n'||s[i]=='\0'); puts(ok?"ACCEPT":"REJECT"); return 0; }
