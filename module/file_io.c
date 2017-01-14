/*
 * I/O 5个函数 open read write lseek close
 */

#include <stdio.h>

// int open(const char *path, int oflag, ... /* mode_t mode */)
// int openat(int fd, const char *path, int oflag, ... /* mode_t mode */)
// 两个函数 1. 返回值 成功返回文件描述符（自增加ID） 2. openat支持相对路径 fd则为父节点的文件描述符

void main()
{
	int f1 = open("/home/hcl001/git/APUE/README.md", "r", "a+");
	printf("%d\n", f1);
}
