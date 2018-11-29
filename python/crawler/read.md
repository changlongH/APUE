## 传统 方法##
- 创建一个线程池，每个线程socket下载一个页面
- 阻塞式(blocking)socket 下载很大的页面效率并不高

## Async ##
- 在建立链接之前设置异步I/O， non-blocking sockets
- 在处理I/O的时候选择响应机制就比较重要了。 这个还是看需求把
- 有一篇文章不错[python3 async io](https://www.keakon.net/2015/09/07/%E5%88%9D%E6%8E%A2Python3%E7%9A%84%E5%BC%82%E6%AD%A5IO%E7%BC%96%E7%A8%8B)

- 使用`DefaultSelector`效率可能不是最高，但是用起来很不错的选择
- 注册事件，然后主程序`loop`检测是否有完成事件，有响应回调。

