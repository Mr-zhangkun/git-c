#include <stdio.h>

int main(void)
{
  int a[9] = {1,2,3,3,2,1,1,2,3};
  int b[9] = {0};
  int i, j, tmp,h;
  for(i = 0; i < 9; i++)
  {
    tmp = i;
    for(j = i + 1;j < 9; j++)
    {
      if(a[tmp] == a[j] )
      {
        b[j] = a[i];
        b[tmp] = a[i];
      }
    }
  }
  for(h = 1; h < 4; h++){
    printf("%d = ", h);
  for(i = 0; i < 9; i++){
    if (b[i] == h){
          printf("a[%d]",i);
  }
}
printf("\n");
}
}
