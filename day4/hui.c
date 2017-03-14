#include <stdio.h>


int main()
{
    int  a, b, c, d, x;

    for(x = 10000; x <= 99999; x++){
        d = x / 10000;
        c = x % 10000 / 1000;
        b = x % 100 / 10;
        a = x % 10;

        if (a == d && b == c){
        printf("%d\n", x);
        }
    }
}
