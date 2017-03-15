#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char cmd[100];
  if(2 == argc){
    //printf("%s\n", argv[1]);
    //printf("%s\n", argv[2]);
    sprintf(cmd,"rm -r %s", argv[1]);
    //strcat(argv[1],argv[2]);
    //printf("cmd = %s\n",cmd);
    //printf("cmd = cp %s %s\n",argv[1], argv[2]);
    system(cmd);
  }
  else{
    printf("xxxxxx\n");
  }
  return 0;
}
