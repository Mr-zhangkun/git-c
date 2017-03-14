#include <stdio.h>

int main()
{
    int a = 12, b = 59 ,c = 0;
    if(a > 12 )
    {
        c = a - 12;
        printf("%d : %d PM\n", c, b);
    }
    else if(a == 12) 
    {
        printf("12 : %d PM\n", b);
    }

    else
    {
        printf("%d : %d AM\n", a, b);
    }
}
