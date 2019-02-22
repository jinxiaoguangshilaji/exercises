#pragma once 
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<string>
#include<cstring>
#include<unistd.h>
using std::string;

class mytcp
{
public:
    ~mytcp();
    void init(string,int);
    int resv_msg_n(int ,char*,int);
    virtual int send_msg(const char*,int)=0;
    virtual int resv_msg(char* ,int)=0;
protected:
    int server_sock;
    int server_port;
    string server_ip;
    struct sockaddr_in server_addr;
};

class tcp_client:public mytcp 
{
public:
    void client_connect();
    virtual int send_msg(const char*,int);
    virtual int resv_msg(char*,int);
};

class tcp_server:public mytcp 
{
public:
    ~tcp_server();
    void server_pre();
    void server_wait_accept();
    virtual int send_msg(const char*,int);
    virtual int resv_msg(char*,int);
private:
    int client_sock;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size;
};

#include "mytcp.cpp"
