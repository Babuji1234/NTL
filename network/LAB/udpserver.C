#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>
int main(){
    char buffer[20];
    char msg[20] = "hello client";
    socklen_t len;
    int sock = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in servaddr, cliaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9001);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(sock,(struct sockaddr*)&servaddr,sizeof(servaddr));
    len = sizeof(cliaddr);
    int n = recvfrom(sock,buffer,sizeof(buffer),0,(struct sockaddr*)&cliaddr,&len);
    buffer[n]='\0';
    puts(buffer);
    sendto(sock,msg,1000,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));

}