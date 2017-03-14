#include <stdio.h>
#include <math.h>

int main()
{
    int a = 2, b = 3, c = 1;
    int x = b * b - 4 * a * c;
    double x1,x2;
    printf ("x = %d\n", x);
    if(x > 0)
    {
        x1 = (- b + sqrt( x )) * 1.0/ (2 * a);
        x2 = (- b - sqrt( x )) * 1.0 /(2 * a);
        printf("x1 = %f,x2 = %f\n",x1,x2);
    }
    else if (x == 0)
    {
        x1 = x2 = -b * 1.0/ (2*a);
        printf("x1 = x2 = %f\n", x1);
    }
    else 
    {
        printf ("no\n");
    }
}
