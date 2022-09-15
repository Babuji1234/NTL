#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#define PORT 5000
#define MAXLINE 1000
int main(int argc, char const *argv[])
{
    char buffer[100];
    char msg[100] = "hello client ";
    int listenfd;
    socklen_t len;
    struct sockaddr_in servaddr,cliaddr;
    bzero(&servaddr,sizeof(servaddr));
    listenfd = socket(AF_INET,SOCK_DGRAM,0);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
    bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    len = sizeof(cliaddr);
    int n = recvfrom(listenfd,buffer,sizeof(buffer),0,(struct sockaddr*)&cliaddr,&len);
    buffer[n] = '\0';
    puts(buffer);
    sendto(listenfd,msg,MAXLINE,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
}