#include <stdio.h>
#include "stack.h"

int main(){
  linklist p;
  if((p = link_create()) == NULL){
    puts("error!");
    return 0;
  }
  int i, a[5] = {6, 4, 3, 2, 1};
  for(i = 0; i < 5; i++){
    if(push(p,a[i]) != 0){
      return 0;
    }
  }
  link_show(p);
  printf("%d\n",pop(p));
  link_show(p);
  return 0;
}
