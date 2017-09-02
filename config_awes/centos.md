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

1. 配置`.vimrc`
2. `gitconfig` `git`颜色 和 `git`自动补全
3. tig插件

