#include <stdio.h>

int main(void)
{
int a[5] = {1,23,10,89,35};
int i, j, h;
for(i = 1; i < 5; i++){
  if(a[0] < a[i]){
    a[0] = a[i];
  }
  }
  printf("%d\n", a[0]);
}
