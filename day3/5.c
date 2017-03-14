#include <stdio.h>

int main()
{
    int a = 12345657;
    int b, i;
    printf("%d\n", a);
    for(i = 1; i < 100; i++)
    {
        if(a != 0)
        {
            b = a % 10;
            printf("%d", b);
            a = a / 10;
        }
    }
    printf("\n");
}
