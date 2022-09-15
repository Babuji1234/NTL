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
 char msg[20]="hello from server";
 int l = bind(socks,(struct sockaddr*)&servaddr,sizeof(servaddr));
 if(l==0)
 {
	printf(" connection sucessful ");
 }

  listen(socks,1);
 int clientsocket = accept(socks,NULL,NULL);
 send(clientsocket,msg,sizeof(msg),0);
}
