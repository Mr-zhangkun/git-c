#include <stdio.h>
int main()
{
    int score = 78;
    if (score >= 90)
    {
        printf ("A\n");
    }
    if (score >=70 && score < 90)
    {
        printf ("b\n");
    }
    if (score >= 60 && score <70)
    {
        printf("c\n");
    }
    if (score < 60)
    {
        printf("D\n");
    }
    return 0;
}
