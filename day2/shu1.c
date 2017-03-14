#include <stdio.h>


int main()
{
    int x = 8765;
    int a, b, c, d;
    if(x)
    {
        d = x % 10;
        x = x / 10;
    }
    if(x)
    {
        c = x % 10;
        x = x / 10;
    }
    if(x)
    {
        b = x % 10;
        x = x / 10;
    }
    if(x)
    {
        a = x % 10;


    }

    printf("%d, %d, %d, %d\n", d, c, b, a);
}
