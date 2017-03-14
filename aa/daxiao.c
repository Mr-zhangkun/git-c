#include <stdio.h>


int main()
{
    char c;
    int i = 0;
    while((c = getchar()) != EOF){
        if((c >= 65) && (c <=90)){
            printf("%c", c + 32);
        }
        else if((c >= 97) && (c <= 122)){
            printf("%c", c - 32);
        }
        else if(c == 10){
            i += 1;
            printf(" ");
        }
        else{
            printf("%c", c);
        }
    }
    printf("\n%d\n",i);
}
