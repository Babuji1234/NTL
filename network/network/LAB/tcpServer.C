#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<arpa/inet.h>
int main(){
    int l;
    int socks = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in servAddr,cliaddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9001);
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    char msg[24] = "Hello from server";
    printf("[+]Waiting for connection ........");
    l = bind(socks,(struct sockaddr*)&servAddr,sizeof(servAddr));
    if(l==0){
        printf("\n[+]Connection established and message sent");
    }
    listen(socks,1);
    int clientsocket = accept(socks,NULL,NULL);
    send(clientsocket,msg,sizeof(msg),0);

    }