#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
int main(){
    char buffer[100];
    char msg[40] = "hello server";
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in servaddr ;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9001);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    sendto(sockfd,msg,1000,0,(struct sockaddr*)NULL,sizeof(servaddr));
    recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)NULL,NULL);
    puts(buffer);
    close(sockfd);
}