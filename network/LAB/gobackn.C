#include<stdio.h>
#include<stdlib.h>
int main(){
    int winsize,sent=0,i,ack;
    printf("\nEnter the window size ");
    scanf("%d",&winsize);
    while (1)
    {
        for(i=0;i<winsize;i++){
        printf("\nFrame %d transmitted \n",sent+1);
        sent++;
        if(sent == winsize){
                break;
        }}
        printf("\nEnter the last ack recieved \n ");
        scanf("%d",&ack);
        if(ack==winsize){
            break;
        }
        else{
            sent = ack;
            sent = sent-1;
        }

    }
}
    
    
    