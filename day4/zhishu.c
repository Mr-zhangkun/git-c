#include <stdio.h>

int main()
{
    int  i, j,a;
    for(i = 2; i <= 100; i++)
    {
        a = 0;
        for(j = 2; j <= i -1; j++)
        {
            if(i % j == 0)
            {
                a = 1;
            }
        }
        if (a == 0)
        {
            printf("%d\n", i);
        }
    }
}

