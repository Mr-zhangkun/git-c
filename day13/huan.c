#include <stdio.h>
#include <ctype.h>

int huan() {
  int flag;
  char c;
  while((c = getchar()) != EOF){
    if(c == 32){
      printf("%%20");
    }
    else{
      if (flag == 0){
        if(c == '%'){
          flag++;
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
        else{
          putchar('%');
          putchar(c);
          flag = 0;
        }
      }
      else if(flag == 2){
        if(c == '0'){
          putchar(' ');
        }
        else{
          putchar('%');
          putchar('2');
          putchar(c);
        }
        flag = 0;
      }
    }
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  huan();
  return 0;
}
