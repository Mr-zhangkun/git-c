#include <stdio.h>

int main(){
  int a[6] = {1,3,5,7,9,10};
  int i, s;
  for(i = 0; i < 6; i ++){
    s = s + a[i];
  }
    printf("%d\n",s);
}
