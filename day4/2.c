#include <stdio.h>

int main()
{
    int a = 1, b = 0, c = 1;
    for(a = 1; a <= 10; a++)
    {
        c = c * a;
        b = b + c;
//        printf("%d\n", b);
    }
    printf("%d\n", b);

}
