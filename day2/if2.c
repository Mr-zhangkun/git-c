#include <stdio.h>

int main()
{
    int score = 58;
    if (score >= 90)
    {
        printf("A\b");
    }
    else if (score >= 70)
    {
        printf("B\n");
    }
    else if (score >= 60)
    {
        printf("C\n");
    }
    else
    {
        printf ("D\n");
    }
    return 0;
}

