#include<stdio.h>
int main(){
    int n,bucketsize,ouputrate,storage=0,sizeLeft,packetsize;
    printf("Enter the no of packets & bucket size ");
    
    scanf("%d %d ",&n,&bucketsize);
    printf("\nEnter the output rate ");
    scanf("%d",&ouputrate);
    storage = 0;
    for(int i=0;i<n;i++){
        printf("\nEnter the input packet size ");
        scanf("%d",&packetsize);
        sizeLeft = bucketsize - storage;
        if(packetsize<=sizeLeft){
            storage+=packetsize;
        }
        else{
            printf("Packet loss %d ",packetsize);
        }
        printf("\nThe buffer %d of %d",storage,bucketsize);
        sizeLeft-=ouputrate;
    }
}