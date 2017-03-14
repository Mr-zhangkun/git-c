#include <stdio.h>

int main()
{
    int i = 1;
    int b = 1;
    for(i = 1; i < 10; i ++)
    {
        b = (b + 1) * 2;
    }
    printf("%d\n", b);
}
