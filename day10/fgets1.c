#include <stdio.h>

int main(int argc, char *argv[]) {
  char a[100];

  while(fgets(a, 23, stdin) != NULL){
    printf("%s\n", a);
  }
  return 0;
}

//./a.out < a.txt
