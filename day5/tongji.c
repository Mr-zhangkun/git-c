#include <stdio.h>

int main(){
  char c;
  int i, j;
  while((c = getchar()) != EOF){
    if(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))){
      i += 1;
    }
    else if((c >= 48) && (c <= 57)){
      j += 1;
    }
    }
    printf("zimu = %d,shuzi = %d\n", i, j);
  }
