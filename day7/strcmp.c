#include <stdio.h>

int main(int argc, char const *argv[]) {
  char str[32] = "hello";
  char src[32] = "world";
  int i = 0;
  while(str[i] == src[i]){
    i +=1;
    if(str[i] == '\0'){
      printf("str=src\n");
      break;
    }
  }
  printf("%d\n",(str[i] - src[i]));
  return 0;
}
