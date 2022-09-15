#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
int main(){
 int socks = socket(AF_INET,SOCK_STREAM,0);
 struct sockaddr_in servaddr,cliaddr;
 servaddr.sin_family = AF_INET;
 servaddr.sin_port = htons(9001);
 servaddr.sin_addr.s_addr=INADDR_ANY;
 int l = connect(socks,(struct sockaddr*)&servaddr,sizeof(servaddr));
 char data[26];
 recv(socks,data,sizeof(data),0);
 printf("%s",data);
 }