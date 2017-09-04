## MongoDB 安装和配置 ##

- 根据官网创建configure repository
    create an /etc/yum.repos.d/mongodb-enterprise.repo file
    配置相关信息

- sudo yum install -y mongodb-enterprise 

- 是否打开了SELinux如果打开了就根据文档做一些设置

- 启动 关闭 重启 sudo service mongod start/stop/restart

- 查看日志文件 /var/log/mongodb/mongod.log

- 更改mongo 配置 /etc/mongod.conf

- 删除mongodb
    sudo service mongod stop
    sodu yum erase $(rpm -qa | grep mongodb-enterprise) // Remove Packages
    sudo rm -r /var/log/mongodb;sudo rm -r /var/lib/mongo // Eemove Data Directories

## 登入数据库 ##
    mongo; use admin; 切换到管理员
    db.createUser({user:"hcl",pwd:"hcl123321",roles:["root"]}) 创建新用户
    新的用户在db.system.users 中 db.getCollectionNames() 或者show tables; 查看文档名称
    db.auth("hcl","hcl123321") 查看是否创建成功

## 安装pymongo ##
    python -m pip install pymongo // 注意python pip 安装环境是否正确 python版本是否正确
    在env环境下 sudo python 还是会使用默认的python 环境安装 //TODO
