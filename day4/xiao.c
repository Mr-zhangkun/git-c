#include <stdio.h>

int main()
{
    int a = 1, b = 2, c = 3;
    if(a < b)
    {
        if(a < c)
        {
            printf("%d\n",a);
        }
        else
        {
            printf("%d\n",c);
        }
    }
    else
    {
        if(b < c)
        {
            printf("%d\n",b);
        }
        else
        {
            printf("%d\n",c);
        }
    }
return 0;
}
