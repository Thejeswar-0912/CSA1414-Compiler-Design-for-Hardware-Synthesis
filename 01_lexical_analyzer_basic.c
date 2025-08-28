#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXID 64

int main() {
    int c, i;
    while ((c = getchar()) != EOF) {
        /* skip whitespace */
        if (c==' '||c=='\t'||c=='\r'||c=='\n') continue;
        /* skip // comments */
        if (c=='/') {
            int d = getchar();
            if (d=='/') {
                while ((c=getchar()) != EOF && c != '\n') {
                    // skip characters until newline
                }
                continue;
            }
            if (d=='*') { int prev=0;
                while ((c=getchar())!=EOF) { if (prev=='*' && c=='/') break; prev=c; }
                continue;
            }
            ungetc(d, stdin);
        }
        if (isalpha(c) || c=='_') {
            char id[MAXID]; i=0; id[i++]=c;
            while ((c=getchar())!=EOF && (isalnum(c)||c=='_')) { if (i<MAXID-1) id[i++]=c; }
            id[i]='\0'; if (c!=EOF) ungetc(c, stdin);
            printf("IDENTIFIER(%s)\n", id);
        } else if (isdigit(c)) {
            char num[128]; i=0; num[i++]=c;
            int dot=0;
            while ((c=getchar())!=EOF && (isdigit(c) || (!dot && c=='.'))) {
                if (c=='.') dot=1;
                if (i<(int)sizeof(num)-1) num[i++]=c;
            }
            num[i]='\0'; if (c!=EOF) ungetc(c, stdin);
            printf("NUMBER(%s)\n", num);
        } else if (strchr("+-*/%<>=!&|^~?:(){}[];,.", c)) {
            int d = getchar();
            char op[4]={0}; op[0]=c; op[1]=0;
            if ((c=='+' && (d=='+'||d=='=')) ||
                (c=='-' && (d=='-'||d=='=')) ||
                (c=='*' && d=='=') ||
                (c=='/' && d=='=') ||
                (c=='%' && d=='=') ||
                (c=='<' && (d=='='||d=='<')) ||
                (c=='>' && (d=='='||d=='>')) ||
                (c=='=' && d=='=') ||
                (c=='!' && d=='=') ||
                (c=='&' && (d=='&'||d=='=')) ||
                (c=='|' && (d=='|'||d=='='))) { op[1]=d; op[2]=0; }
            else { ungetc(d, stdin); }
            printf("OP(%s)\n", op);
        } else {
            printf("OTHER(%c)\n", c);
        }
    }
    return 0;
}
