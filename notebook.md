# 学习笔记

## git

### 关于git
什么是git?

git 是一个分布式版本控制软件.

### 安装git
##### ubuntu Linux
```sh
$ sudo apt-get install git
```
##### mac os
```sh
$brew install git
```
### 创建本地版本库
```sh
$ mkdir git        //建一个目录存放库
$ git init         //将当前目录建成git库
$ ls -l            //查看是否建成库
$ .git             //出现该文件表示成功
```
### 增加文件
1. 创建一个新文件。
```sh
$ touch hello.c
$ vi hello.c
```
2. 复制已有文件到当前目录。
```sh
$ cp ../../git/*.c .      //复制文件
$ cp -r ../../git .       //复制目录
```
### 查看目录状态
```sh
$ git status
```
### 跟踪文件
将当前目录下的所有文件进行跟踪。
```sh
$ git add .
```
### 配置个人用户信息
为提交增加个人用户信息
```sh
$ git config --global user.name "name"                 //配置用户名字
$ git config --global user.email "asdf@outlook.com"    //配置用户邮箱
$ git config --global core.editor vim                  //配置编辑器
```

### 提交
向本地仓库提交跟踪文件。
```sh
$ git commit
```
编辑提交信息
```
First commit

init commit
```
![图片](http://p1.bqimg.com/1949/b6f0c4bbe364df7e.png)
### 查看提交信息
查看提交的相关的信息
```sh
$ git log
```
```
第一行：commit ID
第二行：提交作者名字和邮箱
第三行：提交时间
第四行：提交信息标题
第五行：提交信息具体内容
```
![图片](http://p1.bqimg.com/1949/a1085382c120b4f9.png)
### git diff
1.　查看修改的源码。
```sh
$ git diff
```
2. 比较两个提交的版本
```sh
$ git diff commitID-1 commitID-2
```
3. 理解Patch标记格式的含义
```sh
diff --git a/README.md b/README.md       //虚拟a、ｂ目录
index 3ebf114..605afc0 100644　　　　　　　//commitID
--- a/README.md                         //"---"之前的
+++ b/README.md                         //"+++"之后的
@@ -103,3 +103,5 @@ int main(void)      //起始行，修改行
 007 | 张琨　| 男
 008 | 董俊峰| 男
 009 | 姚宝山| 男
+　　　　　　　　　　　　　　　　　　　　　　　　//新添加
+
```
### 删除文件
1. 从版本库中删除文件。（真正的删除）
```sh
$ git rm hello.c  (rm hello.c)
$ git status
$ git add .
$ git commit
```
2. 删除文件后恢复。
```sh
$ rm -rf hello.c
$ git status
$ git checkout hello.c
```
### 版本之间的切换
根据commitID可以进行版本的切换。
```sh
$ git reset --hard commitID
```
### 忽略文件
忽略不需要跟踪到git库里的文件。
```sh
$ touch .gitigore        //创建隐藏文件
$ vim .gitigore          //填写需要忽略的文件名
-------------
a.out
-------------
$ git add .
$ git commit
```
### github
1. 注册邮箱。（非qq等国内邮箱）
* [outlook](https://login.live.com/login.srf?wa=wsignin1.0&rpsnv=13&ct=1489490184&rver=6.7.6640.0&wp=MBI_SSL&wreply=https%3a%2f%2foutlook.live.com%2fowa%2f%3fauthRedirect%3dtrue%26realm%3doutlook.com&id=292841&whr=outlook.com&CBCXT=out&fl=wld&cobrandid=90015)

2. 创建git库
* [新建git库](https://github.com/Mr-zhangkun?tab=repositories)
3. 从github将创建的git库克隆到本地。
```sh
$ git clone http://github.com/username/git
```
4. 将本地库与github库进行同步，将本地提交推送到服务器上。
```sh
$ git push origin master
input username:
input password:
```

![图片](http://p1.bqimg.com/1949/ff09fc417b0ae9c9.png)


5. 更新本地库，与github库进行同步，将服务器提交下载到本地。
```sh
$ git pull
```
![图片](http://p1.bqimg.com/1949/75b45ddd30e87df2.png)
# markdown
### Markdown
Markdown 是一种轻量级标记语言，用易读易写的纯文本格式编写可以转换成HTML文档.
### 标题
使用＃可以表示１－６级标题。
```
# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题
```
效果：
# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题

### 文字修饰
看一下粗体、斜体的标记
```
*这是斜体*
_这是斜体_
**这是粗体**
__这是粗体__
~~这是划掉~~
_斜体中**加粗**可以这样表示_
```
效果：

*这是斜体*

_这是斜体_

**这是粗体**

__这是粗体__

~~这是划掉~~

_斜体中**加粗**可以这样表示_

### 列表
##### 无序列表
主要使用-和*来标记无序列表
```
* 这是第一列 
-　这是第二列
*　两个符号作用一样
```
效果:

* 这是第一列 

- 这是第二列

* 两个符号作用一样

##### 有序列表
用“x. ”来标记有序列表，x可以是任意数字，可以自增排序。
```
1. 第一列
2. 第二列
1. 第三列
4. 第四列
```
效果：

1. 第一列

2. 第二列

1. 第三列

4. 第四列

嵌套有序列表以"    "来标记。
```
1. 第一层第一个
    1. 第二层第一个
    1. 第二层第二个
1. 第一层第二个
2. 第一层第三个
    1. 第二层第三个
```
效果：
1. 第一层第一个
    1. 第二层第一个
    1. 第二层第二个
1. 第一层第二个
2. 第一层第三个
    1. 第二层第三个
### 任务列表
```
* [x] 第一个任务，已完成
* [ ] 第二个任务，未完成
* [ ] 第三个任务，未完成
```
效果：

* [x] 第一个任务，已完成

* [ ] 第二个任务，未完成

* [ ] 第三个任务，未完成

### 链接
```
*[github](http://github.com)
```
效果：

*[github](http://github.com)

### 图片
```
![图片](http://www.quanjing.com/image/2016index/biu4.jpg)
```
效果：

![图片](http://www.quanjing.com/image/2016index/biu4.jpg)

### 代码块

\```c  
#include <stdio.h>  
int main(void){  
printf(“hello world!”);  
return 0;  
}  
\```

效果：

```c
#include <stdio.h>
int main(void){
printf(“hello world!”);
return 0;
}
```
### Emoji表情　　
从该网址复制表情代码后粘贴。[Emoji](https://www.webpagefx.com/tools/emoji-cheat-sheet/)
```
:open_mouth:
:open_mouth:
:open_mouth:
:open_mouth:
```
效果：
:open_mouth:
:open_mouth:
:open_mouth:
:open_mouth:

### 表格
```
学号 | 姓名 | 性别
-----|------|---
001 | 小明 | 男
002 | 小红 | 女
```
效果：

学号 | 姓名 | 性别
----|-----|---
001 | 小明 | 男
002 | 小红 | 女
