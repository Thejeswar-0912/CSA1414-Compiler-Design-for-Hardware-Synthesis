#include <stdio.h>
#include <ctype.h>
int expr(); int term(); int factor();
int factor() {
    int c;
    // skip whitespace
    do {
        c = getchar();
    } while (c == ' ');

    if (isdigit(c)) {
        int v = c - '0';
        while ((c = getchar()) != EOF && isdigit(c)) {
            v = v * 10 + (c - '0');
        }
        if (c != EOF) ungetc(c, stdin);
        return v;
    }

    if (c == '(') {
        int v = expr();
        getchar(); // consume ')'
        return v;
    }

    return 0;
}
int term(){ int v=factor(); int c; while((c=getchar())!=EOF){ if(c=='*') v*=factor(); else if(c=='/') v/=factor(); else { ungetc(c,stdin); break; } } return v; }
int expr(){ int v=term(); int c; while((c=getchar())!=EOF){ if(c=='+') v+=term(); else if(c=='-') v-=term(); else { ungetc(c,stdin); break; } } return v; }
int main(){ printf("%d\n",expr()); return 0; }
