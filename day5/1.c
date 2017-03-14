#include <stdio.h>

int main(){
    char s[1];
    char ch[5] = "abcde";
    s[0] = 'a';

    int i = 0;
    for(i = 0; i < 5; i++)
        putchar(s[i]);
    printf("\n");
    printf("%s\n", s);
}
