#include <stdio.h>

int main(void)
{
    char c;
    c = getchar();
    int i = 0;
    while(c != EOF){
        if(c == 10){
            i += 1;
        }
        c = getchar();
    }
    printf("%d\n", i);
}
