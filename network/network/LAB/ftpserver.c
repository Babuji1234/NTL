#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define SERV_TCP_PORT 5035
#define MAX 60
char buff[4096],t;
FILE *f1;
int main(int afg,char *argv)
{
int sockfd,newsockfd,clength;
struct sockaddr_in serv_addr,cli_addr;
char t[MAX],str[MAX];
strcpy(t,"exit");
sockfd=socket(AF_INET,SOCK_STREAM,0);
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;

serv_addr.sin_port=htons(SERV_TCP_PORT);
printf("[+] binded");
printf("\n[+] listening...");
bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
listen(sockfd,5);
clength=sizeof(cli_addr);
newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clength);
close(sockfd);
read(newsockfd,&str,MAX);
printf("\nclient message \n file name : %s \n",str);
f1=fopen(str,"r");
while(fgets(buff,4096,f1)!=NULL)
{
write(newsockfd,buff,MAX);
printf("%s",buff);
}
fclose(f1);
printf("\n file transferred \n");
return 0;

}