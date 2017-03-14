#include <stdio.h>
#include <string.h>

char *pj(char *dest,char *tag,char *ch){
  strcpy(dest,tag);
  strcat(dest,ch);
  printf("%s\n",dest);
}


int main(int argc, char const *argv[]) {
  char a[8] = "<h1>";
  char b[20] = "helloworld";
  char c[30];
  pj(c,a,b);
  pj(c,a,b);
//  printf("%s\n",c);
  return 0;
}
