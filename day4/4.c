#include <stdio.h>


int main()
{
    int a;
    int b = 12345678;
    for (a = 2;; a++)
    {
        b = b / 10;
        if(b)
        {
            printf("%d\n", a ); 
        }
    }   

}
