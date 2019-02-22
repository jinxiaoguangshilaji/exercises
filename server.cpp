#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "mytcp.h"
int main(){
    char buff[100];
    char ret_msg[100];
    tcp_server server;
    server.init("127.0.0.1",1234);
    server.server_pre();
    server.server_wait_accept();
    for(int i=0;i<10;++i)
    {
        sprintf(buff,"it's %dth  message",i);
        server.send_msg(buff,strlen(buff)+1);
        server.resv_msg(ret_msg,sizeof(ret_msg));
        printf("return it:\n%s\n",ret_msg);
    }
    sprintf(buff,"$end");
    server.send_msg(buff,strlen(buff)+1);
    return 0;
}
