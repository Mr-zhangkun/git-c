#include <stdio.h>

int main(){
  int a[5] = {1,4,6,3,2};
  int i, j, h, tmp;
  for(i = 0; i < 5; i++){
    h = i;
    for(j = i + 1; j < 5; j++ ){
      if(a[j] > a[h]){
        h = j;
      }
    }
  /*  if(h != i){
      tmp = a[h];
      a[h] = a[i];
      a[i] = tmp;
    }*/
  }
  for(i = 0; i < 5; i++){
    printf("a[%d] = %d\n", i ,a[i]);
  }
}
