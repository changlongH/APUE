#WebBench
Webbench 是一个古老而著名的网站压力测试工具，简单而实用。如果你不清楚你的网站能承受多大的压力，或者你想分析对比两个网站的性能，webbench 再好用不过了.

##首先须要了解几个函数
- [getopt_long](http://man7.org/linux/man-pages/man3/getopt.3.html)  其实就是一个解析命令行参数的函数，如果翻墙了可以直接查看，或者用man查看详情。

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
首先定义`long_options`这个结构体。  
然后使用`get_long`这个函数解析。`argc argv`没啥好说。后面这一串字符串短参数`t:p:c:`后面的冒号是因为他们都是`required_argument`。`options_index` 是解析到到`long_options`结构体的下标。  
返回值`opt`是短参数例如-t 300 `opt = t, optarg=300` `optarg`在头文件中定义。`optind`指向下一个需要解析的参数的下标。


