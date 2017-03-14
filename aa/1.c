#include <stdio.h>

int main(void)
{
    char a = 'a';
    a = getchar();
    printf("a(10) = %d\t a(8) = %o\t a(16) = %x\t",a,a,a);
    printf("a = %c\n", a -= 32);

    a = getchar();
    printf("a = %c\n", a);

    a = getchar();
    printf("a = %c\n", a);
    return 0;
}
