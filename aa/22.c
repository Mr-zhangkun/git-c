#include <stdio.h>

int main()
{
    char c;
    c = getchar();
    while(c != EOF){
        if(c == 32){
            printf("%%20");
        }
        else
            printf("%c", c); 
        c = getchar();
    }
}
