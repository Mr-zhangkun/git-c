#include <stdio.h>

int main()
{
    int a, b, c, d, e;
    for(a = 100; a <= 999; a ++)
    {
      b = a % 10;
      c = a /10 % 10;
      d = a /100;
      e = b*b*b + c*c*c + d*d*d;

      if(e == a)
      {
          printf("%d\n", a);
      }
    }
}
