#include <stdio.h>

void swap(int *p,int *q){
  int c;
  c = *p;
  *p = *q;
  *q = c;
//  printf("%d\n", *p);
//  printf("%d\n", *q);
}


int main(int argc, char const *argv[]) {
  int a = 10;
  int b = 20;
  printf("%d %d\n",a, b);
  swap(&a, &b);
  printf("%d %d\n",a, b);
  return 0;
}
