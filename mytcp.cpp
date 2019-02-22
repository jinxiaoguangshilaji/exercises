#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<string>
#include<cstring>
#include<unistd.h>
#include "mytcp.h"
using std::string;

int tcp_client::send_msg(const char* src,int n)
{
    write(server_sock,(char*)&n,4);
    write(server_sock,src,n);
    return 1;
}

int tcp_client::resv_msg(char *src,int n)
{
    int len;
    int ans=resv_msg_n(server_sock,(char*)&len,4);
    if(ans==0)
        return 0;
    if(n<len)
        len=n;
    ans=resv_msg_n(server_sock,src,len);
    return ans;
}
int tcp_server::send_msg(const char* src,int n)
{
    write(client_sock,(char*)&n,4);
    write(client_sock,src,n);
    return 1;
}

int mytcp::resv_msg_n(int src,char *des,int n)
{
    int cont=0,temp=0;
    while(cont<n)
    {
        temp=read(src,des+cont,n-cont);
        if(temp==0)
            break;
        cont+=temp;
    }
    return cont;
}

int tcp_server::resv_msg(char *src,int n)
{
    int len;
    int ans=resv_msg_n(client_sock,(char*)&len,4);
    if(ans==0)
        return 0;
    if(n<len)
        len=n;
    ans=resv_msg_n(client_sock,src,len);
    return ans;
}

void mytcp::init(string add,int port)
{
    server_port=port;
    server_sock=socket(AF_INET,SOCK_STREAM,0);
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=inet_addr(add.c_str());
    server_addr.sin_port=htons(port);
}

void tcp_server::server_pre()
{
    bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
    listen(server_sock,server_port);
    client_addr_size=sizeof(client_addr);
}

void tcp_server::server_wait_accept()
{
    client_sock = accept(server_sock,(struct sockaddr*)&client_addr,&client_addr_size);
}

void tcp_client::client_connect()
{
    connect(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));
}

tcp_server::~tcp_server()
{
    close(client_sock);
}
mytcp::~mytcp()
{
    close(server_sock);
}

