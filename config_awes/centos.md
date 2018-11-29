## CentOS 7 服务器基础相关配置 ##

- adduser hcl 添加用户

- passwd xxxx 设置密码

- 给新用户`sudo`权限需要修改 `sudoers` 文件
    加权限->修改配置->减权限
    `root  ALL=(ALL) ALL` 下面添加一行
    `hcl ALL=(ALL) ALL` 

- 修改ssh远程端口
    `vim /etc/ssh/sshd_config`
    `#Port 22 -> Port 8080`
    `systemctl restart sshd.service`

- 取消密码和远程root登陆 修改 `/etc/ssh/sshd_config`

- 切换到新用户目录
    `mkdir .ssh; chmod 700 .ssh`
    上传公钥修改权限 400/600

- 测试登陆

- `sudo yum install git` 安装配置git

- ulimit -c 打开core dump

- sestatus 查看是否开启SELinux

1. 配置`.vimrc`
2. `gitconfig` `git`颜色 和 `git`自动补全
3. tig插件

## 系统python2.7 需要安装python3.5 ##
- pip安装虚拟环境(pip 9.x.x) virtualen
- 先安装相关依赖避免安装python3的时候报错
- 下载安装python3.5 安装到`/user/locale/`目录下
- 创建虚拟环境`/env/env3.6`
- 添加快捷键`bashrc`打开虚拟环境

