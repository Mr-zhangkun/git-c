#include <stdio.h>

int main()
{
    int a = 12;
    if((a > 0) && (a <= 9))
    {
        printf("1\n");
    }
    else if((a > 9) && (a <= 99))
    {
        printf("2\n");
    }
    else 
    {
        printf("3\n");
    }
    return 0;
}
