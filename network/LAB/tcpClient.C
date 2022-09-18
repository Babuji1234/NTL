#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
int main(){
    int sock = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9001);
    servAddr.sin_addr.s_addr = INADDR_ANY;
    if(sock < 0){
        printf("\n [-] Error while creating the socket ");
    }
    else{
        printf("\n[+]Socket created!!!!");
    }
    int connection_S = connect(sock,(struct sockaddr*)&servAddr,sizeof(servAddr));
    if (connection_S == -1){
        printf("\n[-]Error.....!!!!");
    }
    else{
        char strData[24];
        recv(sock,strData,sizeof(strData),0);
        printf("\n[+]Message : %s \n",strData);
    }
}