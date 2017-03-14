#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a = 10;
  int *p;
  p = &a;
  printf("%d\n",a );
  printf("%p\n",&a );
  printf("%p\n",p );
  printf("%d\n",*p );
  printf("%d\n",*p );

  return 0;
}
