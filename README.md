# README

## 目标

在控制台模仿贪吃蛇大作战,~~做到什么样就另说了~~.



## 步骤

### 建立服务端与客户端tcp链接

1. 学习socket相关知识

   1. 双端互发信息√

   嘤..遇到问题了,修改了下代码,然后就出现问题了

   server启动后,开始监听localhost:23333;client也可以正常连接和收发数据
   但是这次连接结束后
   重新打开server,就没有再监听port23333,尽管listen函数返回值仍然为0
   paste.ubuntu.com/p/CQ8bfDyw9c/

   

2. 编程

3. 部署

### 账户数据

1. 建立数据库存储账号信息
2. 传输登录信息
3. 验证信息
4. 心跳包检测在线

### 游戏通信

1. 没想好