- git配置
- 使用默认颜色，配置如下：

1. git config --global color.diff auto

2. git config --global color.status auto

3. git config --global color.branch auto

- git alias设置

4. git config --global alias.st status

5. git config --global alias.co checkout

6. git config --global alias.ci commit

7. git config --global alias.di diff

8. git config --global alias.br branch

9. git config user.name "程序员"

10. git config user.email "abc1234@email.com"

- git 分支命名规范

1. dev  --开发总分支 开发期都会合并到这里

2. feature/xxx ---功能开发分支,功能特性修改

3. hotfix/* master上修复的高优先缺陷

4. support/* 文档、测试相关

5. release/* 发布

6. bugfix/* dev 上修复一般优先缺陷

- commit message

-- `#feature xxxx`

-- `#bugfix xxx` 


- git 自动补全命令文件 `git-completion.bash`

在 ~/.bashrc 中写入执行这个文件
`if [ -f xxx/git-completion.bash]; then
    . .git-completion.bash
 endif`

- git tig
