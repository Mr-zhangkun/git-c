#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[]) {
  char dest[128];
  char src[128] = "This is a test";
  int ret;
  int len = 0;
  len = strlen(src);
  printf("strlen = %d\n",len);
  printf("%lu\n",sizeof(len));


  strcpy(dest, src);
  printf("%s\n", dest);
  strcat(dest, src);
  printf("%s\n", dest);

  ret = strcmp(dest, src);
  if(ret > 0){
    printf("dest > src %d\n",ret);
  }
  else if(ret < 0){
    printf("dest < src %d\n",ret);
  }
  else{
    printf("dest = src %d",ret);
  }
  return 0;
}
