#include <stdio.h>
#include <ctype.h>

int huan() {
  char c;
  int flag = 0;
  while((c = getchar()) != EOF){
    if (flag == 0){
      if(c == '%'){
        flag++;
      }
      else if(c == 32){
        printf("%%20");
        flag = 0;
      }
      else{
        flag = 0;
        printf("%c", c);
      }
    }
    else if(flag == 1){
      if(c == '2'){
        flag++;
      }
      else if(c == 32){
        printf("%%%%20");
        flag = 0;
      }
      else{
        printf("%%%c",c);
        flag = 0;
      }
    }
    else if(flag == 2){
      if(c == '0'){
        printf(" ");
      }
      else if(c == 32){
        printf("%%2%%20");
        flag = 0;
      }
      else{
        printf("%%2%c",c);
      }
      flag = 0;
    }
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  huan();
return 0;
}
