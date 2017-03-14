#include <stdio.h>


int len(char * a){
  int i = 0;
  while(a[i] != '\0'){
    i += 1;
  }
  return i;
}



int main(int argc, char const *argv[]) {
  char str[15] = "hello";
  int a = 0;
  a = len(str);
  printf("%d\n",a);
  return 0;
}
