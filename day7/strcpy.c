#include <stdio.h>


void cpy(char *a,char *b){
  int i = 0;
  while(b[i] != '\0'){
    a[i] = b[i];
    i++;
  }
}

int main(int argc, char const *argv[]) {
  char str[128];
  char src[128] = "This is a text";
  cpy(str, src);

  printf("%s\n",str);
  return 0;
}
