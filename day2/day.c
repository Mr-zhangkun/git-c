#include <stdio.h>
int main(){
    int a = 2017, b =3 , c = 10 ;
    int x ;
    int sum;
    if (((a % 4 == 0) && (a % 400 != 0 )) || (a / 400 == 0))
    {
        x = 1;
    }
    else
    {
        x = 0;
    }


    if (b == 3)
    {
        sum = 31 + 28 + x + c;
        printf("sum = %d\n", sum);
    }
    else if (b == 2)
    {
        sum = 31 + c;
        printf("sum = %d\n", sum);
    }
    else if (b == 1)
    {
        sum = c;
        printf("sum = %d\n", sum);

    }
}


