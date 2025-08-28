#include <stdio.h>
#include <ctype.h>
#include <string.h>
char stack[256]; int top=-1;
void push(char c){ stack[++top]=c; }
char pop(){ return stack[top--]; }
int prec(char c){ if(c=='+'||c=='-') return 1; if(c=='*'||c=='/') return 2; return 0; }
int main(){
    char in[256], post[256]; int j=0;
    if(!fgets(in,sizeof(in),stdin)) return 0;
    for(int i=0; in[i] && in[i]!='\n'; ++i){
        char c=in[i]; if(c==' ') continue;
        if(isalnum(c)){ post[j++]=c; }
        else if(c=='('){ push(c); }
        else if(c==')'){ while(top>=0 && stack[top]!='(') post[j++]=pop(); pop(); }
        else { while(top>=0 && prec(stack[top])>=prec(c)) post[j++]=pop(); push(c); }
    }
    while(top>=0) post[j++]=pop(); post[j]=0;
    int t=1; char a,b,op;
    char temp1[8], temp2[8];
    char st[256]; int sp=-1;
    for(int i=0; post[i]; ++i){
        if(isalnum(post[i])) st[++sp]=post[i];
        else{
            b = st[sp--]; a = st[sp--]; op=post[i];
            printf("t%d = %c %c %c\n", t, a, op, b);
            st[++sp] = '0'+t; t++;
        }
    }
    if(sp==0) printf("result = t%c\n", st[sp]);
    return 0;
}
