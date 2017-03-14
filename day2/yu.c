#include <stdio.h>

int main()
{
    int a = 2,b = 0, c = 3;
    int num = 0;
    printf("a && b = %d\n", a && b);
    printf("a && c = %d\n", a && c);
    printf("a && b && c = %d\n", a && b && c);
    printf("(num = 10) && b ====>>> %d\n", (num = 10) && b);
    printf("num = %d\n",num);
    return 0;
}
