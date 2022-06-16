

# linux操作系统（外挂，最小系统，最小的shell）



# 命令和vim

linux入门

linux和unix

vim

就是linux上面内置的一个编译器

vim有三种模式

![](C:\Users\ch\Desktop\前端\算法\屏幕截图 2022-04-13 210844.png)



我们可以在这个虚拟机上面安装很多个虚拟系统

## 命令形式

命令格式： 命令 [-选项] [参数]

选项：功能

参数：对象 目录



ls -la/etc 

注意：

1.个别的不遵循这样的准则

2.多个选项在一起的话，可以写在一起

3.简化完整选项

## 目录命令大全：

### 目录处理命令（ls） 

名称：ls

原意：list

显示目录文件

ls 如果是没有参数的话 就是只操作当前所在目录

ls -a就是显示所有的文件 -a就是看到所有的隐藏文件（all)

ls / 显示所有的文件夹

ls -l 表示显示所有文件(long) 长格式显示

ls -lh 表示人类 就是人性化显示（long human）

隐藏文件：

![](C:\Users\ch\Desktop\前端\算法\屏幕截图 2022-04-13 212355.png)

这个隐藏文件就是说 系统希望大家不要乱动的文件 是系统文件 开头就是用“.”开头

ls -l

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-13 212640.png)

1.代表引用计数 （表示这个文件 被用过几次 ）

这里的2就代表 被用过2次

2.所有者

3.所属组

4.大小 就是字节 这里可以根据 ls -lh 转换为对于的计算党委

```java
ls -lh//人性化
    
```

6. 文件最后一次修改时间

7. 文件名

   ----------------------------------------------------------------------------------------------------------------------------------------------------------

### 创建目录指令（mkdir)

mkdir（make directories）

 创建一个新的目录新的文件夹

用法：mkdir /新的目录名称

mkdir /tmp/masm

表示再tmp临时文件下面创建一个新的文件夹

-p就是递归创建就是说在没有文件夹的情况下创建一个文件夹 再往里面放文件

### 切换目录指令：(cd)

cd /目录名称

cd .. 返回到上一级的命令

### 目录操作命令（pwd）

pwd(print working dircetor)

显示当前在工作的目录

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-13 224315.png)

linux       分组：

u user 拥有者（**只有这一个**）文件的一个 但是可以改变 

g group所属者（用户 美女组，学生组）

o other 其他人（剩下的用户）

用户和文件的关系

所有者只能是一个用户

所属组是属于一个用户集合

创建了一个文件 那么我们就是这个文件的所有者 

我们允许其他人来拥有 其他人就是组员

如何剩下的就是other其他人

隐藏文件一开始设计出来

就是告诉用户 不要去修改和设计这个地方

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-13 212640.png)

第2个就是拥有者 第3个就是所有组 如何后面是文件的大小

### 删除目录指令(rmdir)删除空文件夹

rmdir （remove empty directories）

语法：rmdir 目录

删除空目录

```c++
rmdir /tmp/nihao
```

### 复制目录指令(cp  -p/-r)

cp -rp [源目录][目录]

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-13 230149.png)

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-13 231549.png)

不要忘记-r

 当然啦 复制的时候 我们也可以更改这个名字

比如

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-13 232802.png)

### 剪切更名命令（mv)

mv 原来目录 目标目录

重命名或者改后缀

比如text.c改为cpp

就是

```c++
mv text.c text.cpp
```

```

```



### 删除命令(rm -f )

rm -f 强制删除文件



### 创建文件命令(touch)

touch 文件名



没有指出路径就是当前路径下建立

中间不可以为空格

加上空格的话

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-14 212633.png)

### 短文件命令查看(cat)

cat  文件名

显示文件的内容

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-14 213350.png)

tac 文件名

倒着显示文件的内容

### 长文件查看命令(more)

more 文件名

进入more的时候 空格或者f就是翻页 回车就是一行一行往下找

```
more /etc/serives
```

### 可以回去看的长文件命令(less)

less 文件名

### 显示文件的前n行命令(head)

head -n number

### 显示文件最后的n行命令(tail)

tail -n

### 文件链接命令(ln)



ln link命令

ln -s 源文件 目标文件

```
ln -s /etc/issue /tmp/issue.soft
```

如何显示这个文件 如下

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-14 223133.png)

l是软连接文件

rwx就是权限

软连接 类似window的快捷方式

表示快捷方式指向原来的/etc/issue

软链接特点：

1.权限都是rxw

2.是一个快捷方式

硬件链接特点

相当于 

```
cp -p
```

但是可以同时更新

|            | 软连接                               | 硬链接                   |
| ---------- | ------------------------------------ | ------------------------ |
| 写法区别   | 更新源文件 这个也会变化              | 更新源文件 这个也会变化  |
| 删除源文件 | 打开不了                             | 仍然可以打开             |
| id         | 和源文件不是一个i                    | 和源文件是一个i          |
| 占用空间   | 占用空间                             | 不占用空间               |
| 命令       | -s                                   | 默认                     |
| 删除源文件 | 会一起被删除，因为这个是一个快捷方式 | 不会，因为这个是一个副本 |



### 修改权限命令(chmod)

chmod (change mod of file）

chmod -R(这个就叫做递归修改权限)

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-14 225817.png)

数字模式：

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-14 230021.png)

功能模式：

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-14 230109.png)

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-14 230330.png)



### 更换用户(su)

```c++
su username
```





### 更改权限所有者的命令 (chown)

change owner 目录名

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-15 144732.png)

只有管理员才可以设置

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-15 144814.png)

这个地方就是更改成ji这个用户

### 更改所属组的权限命令（chgrp)

chgrp 组名 用户名



### 查找文件命令（find)

find 范围 匹配条件

```
find /root -name nihao
```

就是在root下 查找名字为nihao的文件

但是这个只能查找到名字刚刚好为nihao的文件

如何找到前缀为nihao1的文件呢

这个时候需要通配符

```
find /root -name *init*
```

表示在root文件夹查找 中间字符是init的文件

如果写成 find /root -name init? 

表示在root文件夹查找 名字为init后面加一个字的文件

```
find -iname //就是不区分大小写查找
```

find / size (+n 表示大于n ；-n 表示小于n ; n 表示等于n)

linux的大小表示 就是用数据块 用k来表示

1个数据块就是512字节 0.5k

### 多个条件查找命令（find -a -type)

-a 就是条件都满足 

-o 表示条件满足其中一个

-type就是查找对应的类型文件

f（文件）

d（目录）

l(软连接)

### 条件查询命令（exec)

查找一个权限为root 大小为10k的文件 并且显示内容

```c++
root@ubuntu:/# find -user root -a -size 10k -type f -exec ls -l {} ;\\最后两个字符一定要家

```

表示的就是 查找到后 exec后面加上跟着的操作

就是ls 展示 -l就是输出 {}  \ ；



### 查看配置和命令非shell内置 (man)

man命令（manaul)

man 命令名

man 加配置文件名称 （查看帮助信息）

man 5 名字就是查看配置文件的信息

### 简短命令介绍  (what is) 

```c++
whatis ls//表示显示ls这个命令
```

### 获取命令信,获得shell内置命 (help)

内置命令 找不到路径

```c++
touch --help//就是获得 touch的选项
```

### 查看 命令路径（which)

which 加命令名字 就是查看命令路劲

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-15 163716.png)



### 添加一个用户 （useradd -m)

-m才可以显示

默认添加在home文件夹下面

useradd -d 目录（在指定目录下面创建一个新用户

）

```c++
useradd nihao//添加一个新的用户 名字叫做你好
```

### 配置用户（passwd)

passwd 用户名 给这个用户名配置密码

passwd -d 用户名 就是删除这个用户

### 查看用户（who)

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-15 164604.png)

### 删除用户（userdel -r）

1.userdel 直接删除 但是保留家目录

2.-r home下的目录一起删除

### 修改用户属性命令（usermod)

###  查看用户组的命令（id/gruoup)

```c++
id liu//查看用户的消息
```

### 建立组命令（groupadd)

### 删除组命令（groupdel)

### 修改组命令（gpasswd）

命令格式：gpasswd[选项]组群功能：

gpasswd组名：

修改密码 gpassed 组名

加入某个用户 gpasswd -a 用户名 组名

### 挂载命令（mount)

挂载文件名为/dev/sdb1的u盘，其文件系统为vfat，挂载点为/mnt

mount –t  vfat/dev/sdb1 /mnt

### 卸载命令（unmount)



### 压缩文件命令（gzip)

gzip 只能压缩文件

不保留源文件

gz 文件名字 就可以压缩

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-16 160313.png)

### 解压缩命令(gunzip)

### 压缩文件夹命令（tar)

-c 打包

-v显示信息

-f必须加

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-16 161357.png)

### 

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-16 161743.png)

### 压缩解压命令（zip)

zip 压缩的名字 要压缩的文件

zip -r  ... 这个是压缩目录的

### 解压命令（unzip)





### 关机命令（shutdown)

shutdown 

-h 加上时间就可以关机

```c++
shutdown -h now//现在就关机
```

-r 就是重启

### 重启命令（rbot）

# 文件表示

-表示一个文件

d表示一个目录

l表示一个软链接

权限：

r 读(read)

w 写(write)

x 执行（exec）

x是最大权限 一般来说读写权限就够了 不需要过大的权限

每3个一个权限

比如下面的一个图片

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-13 213916.png)

d代表这是一个目录 rwx代表 用户拥有者可以读写运行权限

r-x代表组成员可以读 运行 不可以写

最后就只有exec了



## 

mkdir 创建一个新的目录新的文件夹

用法：mkdir -新的目录名称

mkdir /tmp/masm

表示再tmp临时文件下面创建一个新的文件夹

-p就是递归创建就是说在没有文件夹的情况下创建一个文件夹 再往里面放文件

切换目录指令：

cd 切换到对应的目录下面去

cd /目录名/

pwd显示当前所在的目录

.表示当前目录  ..表示当前目录的上一级目录

rmdir删除目录：

remover 

cp 复制文件命令 

cp 文件目录 目的目录

cp可以复制出来许许多多的目录

```
cp 当前目录 目标目录
```

剪切目录 mv 

```
mv 当前目录 目标目录
```

clear清空



move剪切

rm删除文件和目录

```linux
rm 目录
```



# 权限管理

|             | 文件                      | 文件夹               |
| ----------- | ------------------------- | -------------------- |
| 读权限（r)  | cat ，more,less,head,tail | ls                   |
| 写权限(w)   | vim                       | touch mkdir rm rmdir |
| 执行权限(x) | exec(可以执行)            | cd(可以进入)         |

所有者是如何来的？

谁创造了这个文件谁就是这个文件的所有者

所属组

默认新建立的文件是没有x权限 防止木马病毒

## 15.文件压缩格式

.gz

.zip window 和linux都不用装软件就可以自行压缩处理

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-16 160313.png)

.tar 

文件夹压缩格式

这个非常常见

一般还可以进行压缩

就是.tar.gz

## 16.vim编辑器

vim没有菜单 只有命令

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-16 162901.png)

插入模式变为命令行模式 先输入exc再输入“：”

命令模式下输入 wq表示写入并且退出

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-16 171252.png)

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-16 172219.png)

### vim快捷键表示：

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-17 151642.png)

一般模式下的快捷键盘：

a.yy就是拷贝当前行，按下p就是粘贴（yard)拉取的

光标的位置下

b.dd 删除当前行 (错误删除如何补救，就是u )  u就是测回上一步 

vim拥有缓存区，可以一次测绘

那就是2p就是测绘近2步的操作

c.定位到最后一行

gg

d.定位行号

```
shft+n+g
```

更改单词：c命令

命令行模式下的命令：

a.查找对应的单词



```c++
/student//就是查找student这个单词
```

b.设置文件行号

set nu 就是显示行号

set nonu就是销毁

插入模式下的命令：

a.i当前光标的前一个输入

b.a（append)就是当前光标的后一个输入







## 17.linux级别

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-16 164203.png)

## 18.软件包管理

源码包（c语言的包）开源包

二进制包（没有源代码）

类似window的setup.exe 文件

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-17 161518.png)

第一个是软件名字 后面是版本号 后面加上的是操作系统

查看软件包的命令

rpm 命令就是软件包的命令

### 查看（rpm -q）

```c++
rpm -qa foxmail//软件包名查看对于软件包的名字
```

```c++
rpm -qi fomxail//查询对应的消息
```

```c++
rpm -ql foxmai//查询安装后的路径

```

### 删除软件包（rpm -e)

```c++
rpm -e foxmail//删除软件包
```

### 安装rpm包

```c++
rpm -ivh rpm包安装全路径
```

i(install)

v(verbose) 提示

h(hash)进度条

rmp命令规则

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-17 165549.png)

rpm的依赖性

a->b->c

a依赖b b依赖c

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-17 170042.png)

环形需要我们同时下载

### yum命令

输入setup就可以配置设备

## 19.crond调度

指定系统在某个时间执行特殊的命令或程序

### crontab定时命令执行任务

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-19 201208.png)

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-19 201445.png)

特殊符号：

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-19 202400.png)

## 20.进程管理

查看进程（判断是否健康）

查看系统所有程序

杀死进程

### 查看进程命令（ps -le)

查看所有的进程

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-19 203325.png)

pid 就是进程id

uid 就是产生用户id

sz物理内存

### 查看健康状态命令（top)

<img src="C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-19 203741.png" style="zoom:50%;" />

主要看97.7 这个就是cpu有效时间

### 查看进程树命令（pstree)

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-19 204501.png)

### 杀死进程命令（kill) 

k -l 这个就是查看用多少个信号量

kill -all 就是杀死所有进程

## 21.工作管理

放入后台执行

2种方法

a.ctrl +z(放入后台然后是暂停的）

b.&（放入后台是执行的）

### 查看后台工作命令（jobs)

+先恢复 最后一个放入后台的进程

-次恢复

### 恢复后台命令（fg %工作号 ）

指定后台恢复的工作号

## 22.系统资源查看

### 查看系统资源监控命令（vmstat)

```
vmstat 1 3 // 监听系统资源 每次监听一秒 总3次
```

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-19 210649.png)

### 内存查看命令（free)

-b bit单位

-k kb单位

### 查看cpu命令（cat /porc/couinfo)



## 23.知识：缓存和缓冲的区别

前提条件：内存运算速度>> 硬盘运算速度

缓存：加快数据的读取(从硬盘读出)

缓冲：加快数据的写入（从硬盘写入）

## 24.make命令

make是用来工程软件的工具 自动编译化工具 根据文件的时间 来发现程序是否被修改过

读入makefile就可以完成大量的工作 

修改了c程序后 make联系的文件都可以一起更新

Makefile 就是查找这个文件寻找依赖关系

## 24./etc/passwd 文件解释

我们进入/etc/passwd 这个文件就可以看到我们的文件内容 如下

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-20 131305.png)

用户名：密码：UID（用户ID）：GID（组ID）：描述性信息：主目录：默认Shell

## 25.组群是什么

组群就是逻辑编辑文件的一个方便途径

每个文=文件都有一个用户和一个群组

系统组：linux创建

用户组：私人创建

群组的介绍如下：

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-20 132835.png)

这个是这样解释的

组名:口令:组ID:该组成员

# 第二章，编写一个多进程的程序：

### 1.多线程为何连简单的程序都完成不了

线程是进程的基本单位，多线程之间就是一个状态机的实现

那么这个状态机就是一个多处理并发的程序，谁都可以访问内存 那么内存的位置就很危险了



我们这里实现了一个封装的头文件函数

“thread.h”

这个文件

```c++
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdatomic.h>
#include <assert.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREAD 64
enum { T_FREE = 0, T_LIVE, T_DEAD, };
struct thread {
  int id, status;
  pthread_t thread;
  void (*entry)(int);
};

struct thread tpool[NTHREAD], *tptr = tpool;

void *wrapper(void *arg) {
  struct thread *thread = (struct thread *)arg;
  thread->entry(thread->id);
  return NULL;
}

void create(void *fn) {
  assert(tptr - tpool < NTHREAD);
  *tptr = (struct thread) {
    .id = tptr - tpool + 1,
    .status = T_LIVE,
    .entry = fn,
  };
  pthread_create(&(tptr->thread), NULL, wrapper, tptr);
  ++tptr;
}

void join() {
  for (int i = 0; i < NTHREAD; i++) {
    struct thread *t = &tpool[i];
    if (t->status == T_LIVE) {
      pthread_join(t->thread, NULL);
      t->status = T_DEAD;
    }
  }
tribute__((destructor)) void cleanup() {
  join();
}
        
```

我们观察这个结构体定义：

一个id 一个状态还有一个小小的线程

一个指针用来表示下一个线程号的位置

我们来观察这个create算法（表示的是创造一个线程，然后返回一个指针）

assert来判断后面表达式里面的公式是否可以正确

正确就返回 否则就撤销不然影响程序

然后建立一个结构体指针

附上id 还有status状态

调用线程创建函数 然后不断加加标记位

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-26 182846.png)

接下来我们要查看join这个函数 就是用来回收进程的函数

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-26 182933.png)

不断修改线程块 然后把里面的数值更改为true

### 2.进程和线程的区别

a.建立和切换线程比较快一些 

因为进程切换不需要建立页表 线程比较快一些

b.线程的速度更快

当一个进程被挂起 其他进程就会继续执行

c.并行计算

进程之间要通信 （数据）pipe 管道 共享文件区

线程：共享空间

### 3.简单的线程代码实现

线程处理事情的代码：

```c++
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define N 4
int A[N][N],sum[N];
void *func(void* arg)
{
        int j,row;
        pthread_t tid=pthread_self();
        row=(int)arg;
        printf("thread %d [%lu} computes sum of row %d \n",row,tid,row);
        for(j=0;j<N;++j)
                sum[row]+=A[row][j];
        printf("Thread %d [%lu] done;sum[%d] =%d\n",row,tid,row,sum[row]);
        pthread_exit((void*)0);
}
int main()
{
        pthread_t thread[N];
        int i,j,r,total=0;
        void *status;
        for(i=0;i<N;i++)
{
                sum[i]=0;
                for(j=0;j<N;j++)
                {
                        A[i][j]=i*N+j+1;
                        printf("%4d",A[i][j]);
                }
                printf("\n");
        }
        printf("\n");
        printf("main create %d threads\n",N);
        for(i=0;i<N;++i)
        {
                pthread_create(&thread[i],NULL,func,(void*)i);
        }
        printf("main :try to join with threads\n");
        for(i=0;i<N;++i)
        {
                pthread_join(thread[i],&status);
                printf("main :jion with %d[%lu]:status=%d\n",i,thread[i],(int)status);
        }
	printf("main;coumpter and tatol sum:");
        for(i=0;i<N;++i)
                total+=sum[i];
        printf("%d",total);
        pthread_exit(NULL);
} 
                                                
                                                
```

当然为了防止 我们的线程共享的时候 修改竞争态 我们需要进行互斥的访问

我们就要再访问共享变量时候把他锁住 如何再修改 解锁

代码

```c++
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define N 4
int total=0;
pthread_mutex_t *m;
int A[N][N];
void *func(void *arg)
{
        int i,row,sum=0;
        pthread_t pid=pthread_self();
        row=(int)arg;
        printf("i am [%lu] sum of  %d\n",pid,row);
        for(i=0;i<N;++i)
                sum+=A[row][i];
        printf("thread %d [%lu] update total with %d\n:",row,pid,sum);

        pthread_mutex_lock(m);
        total+=sum;
        pthread_mutex_unlock(m);
        printf("sum is %d",total);
}
int main()
{
        pthread_t thread[N];
        int i,j,r;
        void *status;
        for(int i=0;i<N;++i)
        {
                for(int j=0;j<N;++j)
                {
                        A[i][j]=i*N+j+1;
                        printf("%4d",A[i][j]);
                }
                printf("\n");
        }
        m=(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
        pthread_mutex_init(m,NULL);
        printf("Main:create %d threads\n",N);
        for(i=0;i<N;++i)
        {
                 pthread_create(&thread[i],NULL,func,(void*)i);
        }
        printf("%d",total);
         printf("back\n");
        for(int i=0;i<N;++i)
        {
                pthread_join(thread[i],&status);
        }
        pthread_mutex_destroy(m);
        pthread_exit(NULL);
}



```

没有这个互斥的变量 当然这边涉及到了处理机的调度算法

死锁预防：

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-06-01 123217.png)



这个就是进程的互斥协议

死锁预防：

在死锁的时候 互斥量排个顺序

这样一次就只有一个在访问

函数 pthread_mutex_trylock()

```
while(1)
lock(m1)
if(!trylock(m2))
unlock(m1)
else
 break
 
```

三个函数 对应的基本操作：

pthread_cond_wait() 阻塞线程，知道接受信号，互斥量加锁后，就等待释放

```C++
while(S)
{
while(S<=0)
S--
}
```

pthread_cond_signal()发出信号，wakeup正在沉睡的进程

```C++
S++
```

pthread_cond_broakcast 广播 让所有人来抢

WAIT()

```c++
s->value--;
if(s->value<0)block(s-List);
```

siganl

```c++
s->value++;
if(s->value<=0) wakeup(s->list);
```

互斥协议实现：

a.自旋锁

思想：1.每个线程要去换出共享的key

2.如果发现自己换出来的不是key(是别人的 那么进不去)

3.使用完key后 换出来

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-06-07 190605.png)

线程1获得key 把自己的0换进去

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-06-07 190750.png)



其他进程换出来的就只有 进程1的0进不去

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-06-07 190918.png)

进程把自己的key放回去

缺点：如果进程一直不回去 就会发现错误 有的进程就一直进不去

原子xchg实现（就是原子的交换可以看作一瞬间完成的load和store的组合）

```c++
int xchg(volatile int *addr,int newval){
        int result;
        asm volatile("lock xchg %0,%1":"+m"(*addr),"=a"(result):"1"(newval));
        return result;
}

```

下面是锁的逻辑

```c++
int locked=0;
int sum=0;
void lock() { while (xchg(&locked, 1)) ; }
void unlock() { xchg(&locked, 0); }

```





2.互斥锁：

思想：

一个人占用锁 如何其他人用不到就一直等待

先把锁占用了 然后锁上 进行操作 再把锁解开



代码：

```c++
int lock=false;
void Tsum()
{
retry:
        while(lock==true)
        {
                goto retry;
        }
        lock=true;
        for(int i=0;i<=100000;i++)      sum++;
        lock=false;
}

```



### 生产者消费者问题：

生成者把资源放入 就变满 资源拿出就变空

生成者把进程翻入缓冲区知道满了就不放了

消费者

定义一个全局的共享变量：

```c++
int buf[NBUF];
int head,tail;//head用来放入一个空缓冲，tail用于满缓冲取出一个项目
int data;//满缓冲的数量
pthread_mutex_lock;//互斥的mutex——lock
pthread_cond_t empty,full;//进程变量

```

```c++
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define NBUF 5
#define N 10
int buf[NBUF];
int head,tail;
int data;
pthread_mutex_t mutex;
pthread_cond_t empty,full;
int init()
{
        head = tail = data = 0;
        pthread_mutex_init(&mutex,NULL);
        pthread_cond_init(&full,NULL);
        pthread_cond_init(&empty,NULL);
}
void *producer()
{
        int i;
        pthread_t me=pthread_self();
        for(i=0;i<N;++i){
        	pthread_mutex_lock(&mutex);
                if(data==NBUF)//如果缓冲满了 就互斥这个进程
                {
                        printf("producter: %lu:all bufs FULL:wait\n",me);
                        pthread_cond_wait(&empty,&mutex);//交换互斥量和空的量等待 empty变量
                }
                buf[head++]=i+1;//
                head %= NBUF;
                data++;
                printf("producer :%lu data:%d value=%d\n",me,data,i+1);//每次就交换出去互斥量
                pthread_mutex_unlock(&mutex);
                pthread_cond_signal(&full);//发生full互斥，将full的变量交换出去
        }
        printf("producer %lu :exit\n",me);
        }
void *consumer()
{
        int i,c;
        pthread_t me=pthread_self();
        for(i=0;i<N;++i)
        {
                pthread_mutex_lock(&mutex);
                if(data==0)
                {
                        printf("consumer %lu : all bufs EMPTY:wait\n",me);
                        pthread_cond_wait(&full,&mutex);//交换满的变量出去
                }
                c=buf[tail++];
                tail%=NBUF;
                data--;
                printf("consumer %lu:value=%d\n",me,c);
                pthread_mutex_unlock(&mutex);
                pthread_cond_signal(&empty);//把互斥量放到交换区中去
        }
        printf("consumer : %lu exit\n",me);
}
int main()
{
        pthread_t pro,con;
        init();
        pthread_create(&pro,NULL,producer,NULL);
        pthread_create(&con,NULL,consumer,NULL);
        prthread_join(pro,NULL);
        pthread_join(con,NULL);
}

    


```

如何查找文件的定义：

```
grep -r "xxx" /usr/include
```

这个命令 就可以查找到我们需要的文件定义

多线程的排序问题：



### 4.fork的输出秘密以及dup fork哲学

对于stdout 的话 那么我们注意到一个点就是 如何输出到终端的话就是line buffer

如果是pipe管道的话就是buff buffer

line buffer:遇到“\n”就会输出来这个字符

buff buffer:遇到4096个字节才会输出

fork函数调用的时候就会复制出完整的两份就是返回值不同

fork里面有个指针指向对象

文件描述符打开后需要一个偏移量

dup（）就是新加了一个描述符 指向对象

如下图：

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-31 162216.png)

因为每个fork都要复制一下 于是我们的unix给出了一个高性能的实现

copy on write

进程就是一个映射表

所有的操作系统就是管理状态机

进程管理一个映射表来映射所有的函数

分段后可以看到那些页面是可读那些是可写

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-31 163645.png)

这个就是copy on wirte 就是先复制一份后 再通过修改权限进行写 把内容改掉

代码测试：

如下：

```c++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <string.h>

#define NPROC 1000
#define MB 128
#define SIZE (MB * (1 << 20))

#define xstr(s) str(s)
#define str(s) #s

int main() {
  char *data = malloc(SIZE); // 128MB shared memory调用内存
  memset(data, '_', SIZE);

  for (int i = 0; i < NPROC - 1; i++) {
    if (fork() == 0) break;
  }

  // NPROC processes go here

  asm volatile(".fill 1048576 * " xstr(MB) ", 1, 0x90"); // 128MB shared code

  unsigned int idx = 0;
  int fd = open("/dev/urandom", O_RDONLY); assert(fd > 0);
  read(fd, &idx, sizeof(idx));
  close(fd);
  idx %= 1048576 * MB;

  data[idx] = '.';
  printf("pid = %d, write data[%u]\n", getpid(), idx);

  while (1) {
    sleep(1); // not terminate
  }
}
```

没个进程都在fork复制 但是我们的程序确实是没有爆掉 这就证明了copy on wirte这个程序

我们的操作系统是实现了的

这里关于linux的哲学：

我们思考这样的一个哲学问题 平行时空是否能够做到时间旅行 杀死自己

大概理解应该是这样的

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-31 165128.png)

可以简单地写一个dfs地函数 区别是不用递归！不用递归！不用递归！

天啦？这是为什么

因为我们的父进程持有子进程地状态 我们就不用递归

我们的平时宇宙只要消失就可以了

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-31 170037.png)

当然我们有一个非常有趣的地方 我们平行宇宙地进程是可以平行发生的！天啦 这太神奇了 我们只需要修改 50代码就可以了

代码

```c++
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

#define DEST '+'
#define EMPTY '.'

struct move {
  int x, y, ch;
} moves[] = {
  { 0, 1, '>' },
  { 1, 0, 'v' },
  { 0, -1, '<' },
  { -1, 0, '^' },
};
char map[][512] = {
  "#######",
  "#.#.###",
  "#.....#",
  "#.....#",
  "#...#+#",
  "#######",
  "",
};

void display();

void dfs(int x, int y) {
  if (map[x][y] == DEST) {
    display();
  } else {
    int nfork = 0;

    for (struct move *m = moves; m < moves + 4; m++) {
      int x1 = x + m->x, y1 = y + m->y;
if (map[x1][y1] == DEST || map[x1][y1] == EMPTY) {
        int pid = fork(); assert(pid >= 0);
        if (pid == 0) { // map[][] copied
          map[x][y] = m->ch;
          dfs(x1, y1);
          exit(0); // clobbered map[][] discarded
        } else {
          nfork++;
         // waitpid(pid, NULL, 0); // wait here to serialize the search
        }
      }
    }

    while (nfork--) wait(NULL);
  }
}

int main() {
  dfs(1, 1);
}

void display() {
  for (int i = 0; ; i++) {
    for (const char *s = map[i]; *s; s++) {
      switch (*s) {
        case EMPTY: printf("   "); break;
        case DEST : printf(" ○ "); break;
        case '>'  : printf(" → "); break;
        case '<'  : printf(" ← "); break;
        case '^'  : printf(" ↑ "); break;
        case 'v'  : printf(" ↓ "); break;
        default   : printf("▇▇▇"); break;
      }
    }
    printf("\n");
    if (strlen(map[i]) == 0) break;
  }
  fflush(stdout);
  sleep(1); // to see the effect of parallel search
}

                                          
```

我们发现所有程序同时打印了所有的解

### 5.execve（）函数

这个函数就是用来重置系统的状态机的 

恢复到初始的状态

变成了另外一个函数

我们

```c++
man execve()的时候是会看到不同的消息的 必须传入一个路径名
```

所以我的execve()要小心



### 6、exit()销毁函数

销毁一个状态机

### 7.最小的一个进程hello word

利用汇编来写的程序

很自然

```assembly
#include <sys/syscall.h>

.globl _start
_start:
  movq $SYS_write, %rax   # write(
  movq $1,         %rdi   #   fd=1,
  movq $st,        %rsi   #   buf=st,
  movq $(ed - st), %rdx   #   count=ed-st
  syscall                 # );

  movq $SYS_exit,  %rax   # exit(
  movq $1,         %rdi   #   status=1
  syscall                 # );

st:
  .ascii "\033[01;31mHello, OS World\033[0m\n"
ed:

```

那么我们可以使用strace来跟踪这个过程

```linux
gcc -c minimal.S &&ld minimal.o
```

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-26 200409.png)

gdb调试的时候 info inferiors

就可以看到进程号

利用pmap就可以看到地址空间

layout 可以查看汇编指令

在gdb 下输入！cat 我们能够看到一个文件/proc/2573/map的进程消息

### 8.进程地址消息

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-27 120338.png)

这个就是i用来查看到的地址消息

```c++
man proc
```

这个就只有3步 一个是运行 一个是写入 一个是推出

如何找到pthread这个文件

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-25 213613.png)

这样子一步步往里面找进去

可以利用代码来验证

那么如下

assert函数就是一个宏调用 如果为false就报错 终止一个运行 如果为true就继续运行

可以终止程序以免更加严重的错误

mmap函数：

用来映射我们的进程内存地址信息：

我们的c程序可以指向任何地方

我们当然可以写下如下的函数

```c++
include <stdio.h>
int main()
{
        unsigned *p;
        p=(void*)main;

        printf("%x\n",*p);
}

```

当然我们用一个指针指向main这个函数 

我们可以试试用int来看看

打印处这个函数地址空间

当然我们很幸运的就是 我们还可以写其他的指针和函数来表示这个数值

比如

```c++
int sum(int a,int b)
{
	printf(“%d",a+b);
return a+b;
}
```

d定义一个指针来标向这个函数

```c++
int(*p)(int,int);
p=sum;
printf("%d",p);
```

把这个函数的地址空间打印出来 

当然我们还可以用objdump -d | vim - 
来查找sum函数䣌地址会发现居然是一致的

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-27 113915.png)

这个地址空间是一样的 所以计算机没有魔法

### 9.利用进程空间来进修修改（linux外挂）

操作系统进行了一种访问机制当然这个访问机制能够允许我们去内存里面访问我们的修改器 这样我们就可以利用linxu来做外挂

### 10.最小的shell程序

最小的shell程序 我们可以这样来写

在网上搞到了一份的源代码 最重要的如何使用这份代码

我们最重要的就是gdb 调试

but有一个很严重的问题！！！没有main函数如何调试呢 就是加入b断点使用run命令

当然这里介绍一个很简单的命令就是layout命令

通过layout 一步步来看这个命令

源代码的实践就是一个命令的解释器



### layout

man layout是一个非常有用的调试gun命令

### 11.终端

tty命令

tty可以显示当前终端的描述符

我们可以用echo 打印到另一个终端上面去

![](C:\Users\ch\Desktop\屏幕截图 2022-05-29 120352.png)

### 12.c语言库函数的定义

我们cling编译会更加安全

比如我们实现一个字符·操作函数

```c++
void *memset(void *s, int c, size_t n) {
  for (size_t i = 0; i < n; i++) {
    ((char *)s)[i] = c;
  }
  return s;
}

```

我们来看看gcc和cling编译的不同把

```lisp
cling a.c -o2 -c
```

写入这样de

### 13.可执行文件

链接和加载



可执行文件就是状态机的描述以及数据结构的迁移（状态

可执行文件就是exceve来调用

我们在执行文件的时候 输入./a.out的时候 就会报错 说没有权限 

但是我们加入权限后确会报错说文件格式不对 why?

组合多个可执行文件的时候 会把数据端整合 bass组合为一体



当我们的计算机执行进程我们仍然可以看到一些小小的size 一个a.out  文件组成

| 文件头 | 代码端 | 数据段 | 符号表 | bss段（保存未初始化的全局变量） |
| ------ | ------ | ------ | ------ | ------------------------------- |

我们可以用size 命令来查看这个文件的长度

我们也可以用readelf -h  a.out来查看这个文件具体每一段的代码

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-30 211059.png)

**静态链接和动态链接：**

静态链接把必要的代码和库函数全部插入进去，一般这样的a.out比较强大但是独立，对此类的函数调用保存在函数的文件中去，动态的时候函数加载到内存里面去

动态各个程序 共享存的函数

对于一个a.out构造：

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-30 213757.png)

bass用来动态分配内存空间

启动一个计算机 会自动分配栈的空间大小 当然我们也可以看到这段大概是多少 有程序但是只能是

```c++
#include "thread.h"

__thread char *base, *cur; // thread-local variables
__thread int id;

// objdump to see how thread-local variables are implemented
__attribute__((noinline)) void set_cur(void *ptr) { cur = ptr; }
__attribute__((noinline)) char *get_cur()         { return cur; }

void stackoverflow(int n) {
  set_cur(&n);
  if (n % 1024 == 0) {
    int sz = base - get_cur();
    printf("Stack size of T%d >= %d KB\n", id, sz / 1024);
  }
  stackoverflow(n + 1);
}

void Tprobe(int tid) {
  id = tid;
  base = (void *)&tid;
  stackoverflow(0);
  }

int main() {
  setbuf(stdout, NULL);
  for (int i = 0; i < 4; i++) {
    create(Tprobe);
  }
}


```

这段函数就是不断地开辟一个线程，如何把栈挤爆了 把栈的大小输出就ok了

文件系统：

每个文件都有一个指针：

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-06-08 191219.png)

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-06-08 191649.png)

我们的文件系统里面有许多的fat 标识 但是每个标识后面的都是簇

里面存放着我们的文件

我们可以创建一个映像的文件 命令如下：

```c++
yes | head -c 104857600 > fs.img

```

我们使用 mkfs.fat 就可以进入这个文件查看

```
create an MS-DOS system at system
```



###  14.动态加载

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-06-01 112514.png)

整个过程的执行状态就是这样的：

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-06-01 113028.png)

 加载到我们的内存里面去 配置运行时的状态 还有状态机的初始状态

### 15.文件系统

1.提供api

2.提供隔离 不能无限制扩大

虚拟磁盘就是

```c++
vector<int> s1;
/*最简单就是key vlaue*/
```

逻辑相关的放在一个目录里面去

如何建立一个树

文件api调用

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-06-12 155933.png)

这里返回的是文件的虚拟磁盘的文件操作符

一个指针

open打开

close关闭

dup复制

fork继承

文件系统手册：

[ptfm]: http://jyywiki.cn/pages/OS/manuals/MSFAT-spec.pdf

几个名词：

1.byte字节 就是一个数据流集合的名词

2.• bad (defective)  不能够写和读的扇区 这个地方是不能够数据写和读

3.file 一个文件 包括了数据和描述

4.sector 扇区

5.cluster 簇 一种分配的单元 （包括一组连续的扇区）

bios parameter block （引导扇区）这个地方就是用来引导我们的扇区的物理块

fat12/16都是在偏移在36的的地方

fat12的卷大小要小于4mb





如何判断文件系统是哪个呢：

```c++
If(CountofClusters < 4085) {
/* Volume is FAT12 */
} else if(CountofClusters < 65525) {
 /* Volume is FAT16 */
} else {
 /* Volume is FAT32 */
} 

```



fat12 不能超过4084的卷

fat16不能少于4085的卷

引导块存放了许多重要的东西 里面有很多的引导快 都是一些指针 我们如果这个地方损坏了 就会有灾难性伤害

fat36在扇区6做了相应的备份

fat文件分配表里面包含了很多的文件状态 以及指针

fatxx说明表现就是xx长度

第一个数据存放在的簇必须是cluster 2

fat表现高4位要保留住 这里的话就是可以修改掉

为了确定是哪一个簇 可以用这个算法

```c++
If(BPB_FATSz16 != 0)
 FATSz = BPB_FATSz16;
 Else
 FATSz = BPB_FATSz32;
If(FATType == FAT16)
 FATOffset = N * 2;
Else if (FATType == FAT32)
 FATOffset = N * 4;
ThisFATSecNum = BPB_ResvdSecCnt + (FATOffset / BPB_BytsPerSec);
ThisFATEntOffset = REM(FATOffset / BPB_BytsPerSec);2

```

计算扇区内部在哪一个商区：

```c++
SectorNumber = (FatNumber * FATSz) + ThisFATSecNum
```

表现的头2个部分是保留的：

对于fat[0]这个地方 我们的低8位是00010010

其余位置都是用1来填充

于是有：

 for FAT12, FAT[0] = 0x0FF8 for FAT16, FAT[0] = 0xFFF8 for FAT32 FAT[0] = 0x0FFFFFF8 

第二个fat[1]表项用来 记录格式化程序的eoc值

fat【1】的高2位流出来做dirty标志

2个标志：

一个是cinblush 这个表示是否磁盘错误

一个是hrderr 这个是是否 磁盘错误

目录：

我们可以查看的目录结构是用tree看到的

我们可以看到tree来写出目录的写法



### 16.输入输出设备

有2种设备一个字符流，一个块的设备

字符流：

类似一个管道，我们可以在里面拉取设备，读到哪里，写到哪里

块设备：

拥有一个一个的块

显卡也是字符也是数组

提供输入和输出的函数

read()函数

 wirte()函数

iocol读取一个设备的状态

内核驱动程序：就是一段内核的代码 是一个虚拟的设备 后面可以没有对应的设备支持

质量庞大质量低的代码

### 17.hard and soft link

hard 链接后 我们修改啊a.txt b.txt里面的文件也会被修改

```
ln a.txt b.txt
```

这个就是生成b.txt的硬链接

只要我们修改a.txt的链接 那么吧b.txt也会跟着修改

如果我们查看这个编号的话 就会发现这2个是完全相同的编号

```c++
ls -i *.txt
```

如下图：

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-06-11 160401.png)

2个的编号是一样的 那么就是同一文件

硬链接 指向同一个节点

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-06-11 160835.png)

软连接：

快捷方式

允许许多的ln

### 18.空闲空间管理

链表法

每一个存放下一个的位置

位图法

我们可以使用lsblk来表示出磁盘的分区情况

```c++
lsblk -p 查看分区的大小
  fdsik //分区的工具
   fdsik -n添加新的分区
    可以选择 
    l 逻辑（0到3）
    p 主分区（4之后)
    
```



## 27.shell编程

 shell 如何编写一个简单的程序

```shell
#!/bin/bash
echo "hello,word";

```

shell就是一个脚本语言，那么我们进行的就是一堆的指令集合在一起，一起执行的

shell 默认的权限是不能执行的，所以到了后面要把权限打开掉

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-04-23 174846.png)

shell编程如何获得参数

$n(n为数字)

$0是输出脚本名称

### 进程fork

```c++

# include<stdio.h>
# include<sys/types.h>
# include<unistd.h>

int main()
{ 
 	int ret_from_fork,mypid;
 	mypid=getpid();
 	printf("before:my pid is %d\n",mypid);
 	ret_form_fork=fork();
 	sleep(1);
 	printf("after:my pid is %d,fork() said %d\n",getpid(),ret_form_fork);
}

```

fork返回的是的2次参数，一个参数是0，就是子进程，一个是pid就是父进程，这个pid就是父进程创建的子进程

代码：

```c++
#include <stdio.h>
 #include <stdlib.h>
#include <unistd.h>
 #include <string.h>
#include <pthread.h>
int main()
{
	pid_t pid=fork();
	if(pid==0)
	{
		printf("   child is create!%d,my father is %d \n",getpid(),getppid());
	}
	else
	
	{
       		printf("child is creat!,%d,my father is %d",pid,getppid());	
	}
	printf("nihao\n");
	return 0;
} 

```

注意到nihao打出了2遍这说明了 父子进程都执行同样的代码

共享那些内容：

全局，数据区，data，text

不同的内容：

进程id fork返回值，ppid不一样 时间不一样

***<font color='red'>读时共享写时复制</font>***

读的时候就是读父进程的 写的时候就是子进程的

实现代码：

```c++
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int glob=10;
int main()
{
	int local;
	pid_t pid;
	local=8;
	if((pid = fork())==0)
	{
	local++;
	printf("%d %d",glob,local);
	sleep(2);
	}
	else if(pid>0)
	{
		glob=1;
		local--;
		printf("%d %d",glob,local);
		sleep(10);
	}
	return 0;
}

```

注意到输出时

10 9 

这个是子进程：

子进程读取的时候 就是读取时候读取共享的栈区数据

所以就是全局10 local就是本地就是8+1=9

1 7

这个是父进程：

父进程就是读取本地的进程 就是1 

local就是8-1=7；

当然我们可以进行调试这个程序：

```c++
gcc -g fork.c -o fork//带有调试的编译 这样编译过后的文件 具有编译的debug功能
```

输入gdb 就可以进入调试

b 可以设置断点 

r就是运行到断点处

当然我们可以进入子进程查看一下

```c++
set follow——mode child //进入子进程查看变量
```

exec函数族

调用exec a.out就会调用 a.out这个程序里面的代码

### mmap映射

磁盘只能read和write

但是把它映射到内存中就可以用指针来操作

![](C:\Users\ch\Desktop\前端\操作系统\title_sprite.png)

mmap创建内存

```c++
void *mmap(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset);
/*
addr:首地址
length：大小
prot:读写属性
flag：标志共享 MAP_SHARED/MAP_PRIVATE	
fd:用于创建文件的文件描述符
offset:偏移位置（4k整数倍）




*/
```

cpu可以2个一起运行

利用tmux来分开查看

tmux new -s py（表示新开一个窗户）

ctrl+b 再按上% 表示左右分开窗户

ctrl+b 再按上“表示上下窗户

判断是否共享全局变量：

```c++
#include "thread.h"


int x=1;

void Thello(int id) {
  usleep(id * 100000);
  printf("Hello from thread #%c\n", "123456789ABCDEF"[x++]);
}
int main() {
  for (int i = 0; i < 10; i++) {
    create(Thello);
  }
}

```

这个x不断增加 就输出 代表这个x是共享

如果x放入程序中就没有什么效果

就是不断的1





# 操作系统内核之道

## 1.一个图的所有文件解释

![](C:\Users\ch\Desktop\前端\计算机组成原理\屏幕截图 2022-05-06 165447.png)

我们使用linux来表示这些数据就可以了

gcc工具：

1.反汇编一个机器指令 objdump -d

对象是.o可重定位文件（当然我们看到的话，发现数据是0000开始）

这就证明了重定位，装入的时候

如下图

![](C:\Users\ch\Desktop\前端\计算机组成原理\屏幕截图 2022-05-06 165916.png)

这个地方就是0开始

如我们查看可执行文件会发生什么事情呢

我们发现开始的地方不是0000 这是为什么呢？

这时候使用的是虚拟内存的地址 不是重定位文件

如下：

![](C:\Users\ch\Desktop\前端\计算机组成原理\屏幕截图 2022-05-06 170105.png)

![](C:\Users\ch\Desktop\前端\计算机组成原理\屏幕截图 2022-05-06 170148.png)

## 2.程序的原子性

原子性就是一个程序一段代码是独占一段时间的

单处理器多线程（随时可能被切断）

多处理器多线程（同时并发执行）

处理的方式：

大任务切换到小任务上面去

work head去锁里面取任务

出去不可并行的步骤：

```c++
Thm. $T_n < T_\infty + \frac{T_1}{n}$ (PDC, Chap. 1)
```

lock unlock阻止并发

## 3.程序的原子性的并发互锁。

如何解决并发性锁的问题就是进行原子性操作

利用原子程序语言

实现互斥

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-20 103034.png)

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-20 103136.png)

一个程序的初始状态有自变量还有栈帧什么的

画出来就是

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-20 160616.png)

## 4.linux的中断系统

中断分为：同步中断和异步终端

- 同步中断指的是当指令执行时由CPU控制单元产生的，之所以称为同步，是因为只有在一条指令终止执行后CPU才会发出中断。

- 异步中断是由其他硬件设备依照CPU时钟信号随机产生的。

   同步就是异常，异步就是中断。

  中断有可屏蔽（所有的io设备）和不可屏蔽

  

轮询：一种方法是不断询问程序的是否有请求 如何回应

```c++
while(1)
{
 find_cpu();
 if(push)
 exit;
}
```

中断：

```c++
push
exit
```

push下去输出的是中断信号

处理器受到信号就会中断cpu

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-21 173420.png)

这个是cpu的内存分配

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-21 174056.png)

在code里面0.5gb是闪存 里面有着中断向量表

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-21 174410.png)

按下按键的时候就会跳转到对应的中断向量表那边去

中断号：

软件中断：利用request_irp来注册中断

中断向量表：从内存的4地址开始

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-21 175007.png)

一个中断向量表是一个数组 每个数组就是一个4字节大小长度的中断地址

保存的是指向一个程序的指针

过程就是：

先main入栈

如何保存现场，用来恢复现场的数值

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-21 175507.png)

地址的计算：64+n*4 就是指向该地址

调用的过程：

第一步： 发送中断信号

第二部：查看中断向量表 判断优先级

第三步：把寄存器的数值都保存进去

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-21 180600.png)

查看中断向量表：

```c++
cat /proc/interrupts
```

如下图所示：

![](C:\Users\ch\Desktop\前端\操作系统\屏幕截图 2022-05-21 182524.png)

第一个是中断线；

第二个是中断程序的计数器 15就是发生了15次中断

第三个是中断设备名

## 5.linux可爱的命令

xeyes（显示一个眼睛）

cowsay(就是动物说话)

oneko(养一只小猫)

## 6.linux镜像

unzip解压文件

进入文件后 vi makefile就可以生成一个镜像

然后make run就可以跑起来啦



## 7.如果编写一个内核

## 

