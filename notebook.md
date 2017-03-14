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
5. 更新本地库，与github库进行同步，将服务器提交下载到本地。
```sh
$ git pull
```
