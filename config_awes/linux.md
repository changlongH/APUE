## 一些常用的linux 备份 ##

####  .bashrc ####
'''
if [ -f /etc/bashrc ]; then
    . /etc/bashrc
fi

source /etc/bash_completion.d/git
'''

- `coredump`相关 `ulimit -S -c 0	 ulimit  -c unlimited` 关闭 或者不限制大小，

#### .ssh/config ####

- 本地机器`HOST`配置 跳转机配置

