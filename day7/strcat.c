#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char dest[128] = "This is a test";
  char src[128] = "This is a test too";
  char tmp[128];
  int i = 0;
  while(src[i] != '\0'){
    tmp[i] = src[i];
    i += 1;
  }
  printf("%s%s\n",dest,tmp);
  return 0;
}
