#include <stdio.h>
#include <ctype.h>
int main(){
    int c;
    while((c=getchar())!=EOF && c!='\n'){
        if(isalnum(c)) printf("PUSH %c\n",c);
        else if(c=='+') printf("ADD\n");
        else if(c=='-') printf("SUB\n");
        else if(c=='*') printf("MUL\n");
        else if(c=='/') printf("DIV\n");
    }
    printf("PRINT\n");
    return 0;
}
