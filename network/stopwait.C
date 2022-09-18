#include<stdio.h>
#include<stdlib.h>
int main(){
     int i,n,r,a;
     printf("enter the no of packets");
     scanf("%d", &n);
     for (i = 1; i <= n;i++){
         printf("the packet sent is %d\n ", i);
         r = rand() % 2;
         if(r==1){
             a = rand() % 2;

            if(a==1){
                printf("Ack number: %d \n", i + 1);
            }
            else{
                printf("No ack number :%d \n", i + 1);
                i--; 
            }
         
         }
         else{
             printf("time out , resend \n");
             i--;
         }

     }
}