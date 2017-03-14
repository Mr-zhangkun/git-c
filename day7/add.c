#include <stdio.h>
#include <string.h>

int add (int a,int b){
  int sum;
  sum = a + b;
  return sum;
}
int jian (int a,int b){
  int sum;
  sum = a - b;
  return sum;
}

int cheng (int a,int b){
  int sum;
  sum = a * b;
  return sum;
}
int chu (int a,int b){
  int sum;
  sum = a / b;
  return sum;
}
int yu (int a,int b){
  int sum;
  sum = a % b;
  return sum;
}

int main(int argc,const char *argv[]){
  int i = 4;
  int j = 2;
  int f;
  if(*argv[1] == '+'){
    f = add(i ,j);
  }
  else if(*argv[1] == '-'){
    f = jian(i, j);
  }
  else if(*argv[1] == '*'){
    f = cheng(i, j);
  }
  else if(*argv[1] == '/'){
    f = chu(i, j);
  }
  else if(*argv[1] == '%'){
    f = yu(i, j);
  }
  printf("f = %d\n",f);
}
