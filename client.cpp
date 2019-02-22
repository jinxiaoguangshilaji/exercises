#include <stdio.h>
#include"mytcp.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <algorithm>
using std::min;
bool strcmp1(const char *,const char *);
int main(){
    char buff[100];
    char ret_msg[100];
    tcp_client client;
    client.init("127.0.0.1",1234);
    client.client_connect();
    int n=0;
    while(1)
    {
        client.resv_msg(buff,sizeof(buff));
        printf("copy it :\n%s\n",buff);
        ++n;
        sprintf(ret_msg,"I have %d messages",n);
        client.send_msg(ret_msg,strlen(ret_msg)+1);
        if(strcmp1(buff,"$end"))
            break;
    }
}

bool strcmp1(const char * a,const char *b)
{
    int len=min(strlen(a),strlen(b));
    for(int i=0;i<len;++i)
        if(a[i]!=b[i])
            return 0;
    return 1;
}
