# WebBench
Webbench 是一个古老而著名的网站压力测试工具，简单而实用。如果你不清楚你的网站能承受多大的压力，或者你想分析对比两个网站的性能，webbench 再好用不过了.

## 首先须要了解几个函数
- ### [getopt_long](http://man7.org/linux/man-pages/man3/getopt.3.html)   其实就是一个解析命令行参数的函数，如果翻墙了可以直接查看，或者用man查看详情。
```c
static const struct option long_options[]=
{
    {"force",no_argument,&force,1},
    {"reload",no_argument,&force_reload,1},
    {"time",required_argument,NULL,'t'},
    {"help",no_argument,NULL,'?'},
    {"http09",no_argument,NULL,'9'},
    {"http10",no_argument,NULL,'1'},
    {"http11",no_argument,NULL,'2'},
    {"get",no_argument,&method,METHOD_GET},
    {"head",no_argument,&method,METHOD_HEAD},
    {"options",no_argument,&method,METHOD_OPTIONS},
    {"trace",no_argument,&method,METHOD_TRACE},
    {"version",no_argument,NULL,'V'},
    {"proxy",required_argument,NULL,'p'},
    {"clients",required_argument,NULL,'c'},
    {NULL,0,NULL,0}
};
while((opt=getopt_long(argc,argv,"912Vfrt:p:c:?h",long_options,&options_index))!=EOF )
```
首先定义`long_options`这个结构体。 每组4个域第一个表示长参数，第二个表示是否需要参数或可选参数，若第三个为空则opt返回第四个域的值，否则opt返回0. 第四个域的值直接赋值给第三个所指向的地址。

然后使用`get_long`这个函数解析。`912Vfrt:p:c:?h`这个字符串中包含所有短参数。如果是需要参数`required_argument`则短参数后面加冒号`t:p:c:`。`options_index` 是匹配到的`long_options`结构体的下标。  

返回值`opt`是短参数例如-t 300 `opt = t, optarg=300` `optarg`在头文件中定义。`optind`指向下一个解析`argv`的下标。

- ### Socket 这个不用说了吧

- ### [fork](http://man7.org/linux/man-pages/man2/fork.2.html)    
fork通常作为一个函数被调用。这个函数会有两次返回，将子进程的PID返回给父进程，0返回给子进程。实际上，子进程总可以查询自己的PPID来知道自己的父进程是谁，这样，一对父进程和子进程就可以随时查询对方。

这里有一点要注意是子进程结束和僵尸(Zombie)进程。可以看一下`wait`函数（父进程阻塞清除）和`signal(SIGCHLD, SIG_IGN)`函数（父进程不关心让系统内核直接收回）。如果父进程先退出，其子进程交由`init`掌管，就是说如果父进程先退出可以不用管子进程, 因为`init`会帮忙擦屁股。

- ### [pipe](http://man7.org/linux/man-pages/man2/pipe.2.html)    
`int pipe2(int pipefd[2]);`  `pipefd[2]`是两端文件描述符，有一端只读(pipefd[0])，另一端只写(pipefd[1])。可以配合`read() fdopen()`等函数进行读写。

管道：这是最初的Unix IPC，显然具有很大的局限性。
1. 管道是半双工的，数据只能向一个方向流动；需要双方通信时，需要建立起两个管道；
2. 只能用于父子进程或者兄弟进程之间（具有亲缘关系的进程）；
3. 单独构成一种独立的文件系统：管道对于管道两端的进程而言，就是一个文件，但它不是普通的文件，它不属于某种文件系统，而是自立门户，单独构成一种文件系统，并且只存在与内存中。
4. 数据的读出和写入：一个进程向管道中写的内容被管道另一端的进程读出。写入的内容每次都添加在管道缓冲区的末尾，并且每次都是从缓冲区的头部读出数据。

扩展相关知识，可以了解更多`Linux IPC`目前主要分布式系统主要有哪些通信方式。

- ### [alarm](http://man7.org/linux/man-pages/man2/alarm.2.html)  定时器


## 源码分析
其实了解了上面这几个函数之后再来看源码就比较简单了。整体思路比较简单：

1. 解析参数 2. 构建请求头 3. fork()子进程（都是由主线程fork）

### 子进程
    1. sock建立连接 2. 设置定时器  3. while(1)(发送请求头和接收数据写入管道)
### 父进程
    1. 父进程读取管道中数据 2. 统计结果  3. 判断是否读取完毕
    
但是仔细思考里面就会有很多细节问题：

     1. 解析参数各种输入参数的检测
     2. 构造请求头时是否正确
     3. fork子进程失败或者sock失败管道读写失败处理
     4. 主线程统计是否会死循环
