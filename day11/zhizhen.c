#include <stdio.h>

int main(void){
/*int a[10] = {1,2,3,4,5,6,7,8,9,10};
int i, *p;
p = a;
for(i = 0; i < 10; i++){
  printf("%d\n",*p );
  p++;
}
}*/


int a[10] = {1,2,3,4,5,6,7,8,9,10};
char *b;
b = a;
int i;
for(i = 0; i < 10;i++){
  printf("%d",*b);
  b +=4;
}
}
