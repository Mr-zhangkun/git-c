## system 函数

示例代码：
```c
#include <stdlib.h>
int system(const char *command);
功能： 就是执行一个命令 
比如： system(" cp  file  newfile");完成文件拷贝
```
编程：删除目录
```c
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
```
## fgets函数  
示例代码：
```c
char *fgets(char *s, int size, FILE *stream);
功能： 就是一次读取一行,遇到'\n'就立刻返回. 当返回值为NULL时表示文件读取结束
参数： s , 用于存放读取的字符串(传递数组名即可)
      size, 指定读取一次最多读取到的字节个数
      stream, 直接填写stdin即可   
      
比如： fgets(buf, 64, stdin); 从标准输入读入一行
```
编程：修改文件名
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  char buf[32];
  char direct[64] = "mv ";
  while (fgets(buf, 32, stdin) != NULL){
    buf[strlen(buf) - 1] = '\0';

    strcat(direct, buf);
    strcat(buf, "-1");
    strcat(direct, " ");
    strcat(direct, buf);

    printf("%s\n", direct);
    system(direct);
    
    strcpy(direct, "mv \0");
  }

  return 0;
}
```
