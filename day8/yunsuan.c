#include <stdio.h>

int main(int argc, char const *argv[]) {
  float s, q, a, b, i, j;
  int n = 20;
  for(i =1; i <= n ; i = i + 2){
  a = 1 / i;
  s = s + a;
  }
  for(j = 2; j <= n; j = j + 2){
  b = 1 / j;
  q = q + b;
  }

  printf("%.5f\n",s - q);
  return 0;
}
