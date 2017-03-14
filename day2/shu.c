#include <stdio.h>

int main()
{
    int a = 111;
    int sum = 1;
    if(a)
    {
        a = a / 10;
    }
    if(a)
    {
        a = a / 10;
        sum = sum + 1;
    }
    if(a)
    {
    sum = sum + 1;
    }
    printf("%d", sum);
}
