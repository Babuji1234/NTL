#include<stdio.h>
int main(){
    int no_of_queries, storage, output_packet_size;
    int input_packet_size, bucket_size, size_left;
    storage = 0;
    printf("\nEnter the no of inputs & bucket size ");
    scanf("%d %d", &no_of_queries , &bucket_size);
    printf("\nEnter the output rate ");
    scanf("%d", &output_packet_size);
    input_packet_size = 4;
    for (int i = 0; i < no_of_queries;i++){
        printf("\nEnter the input packet size ");
        scanf("%d", &input_packet_size);
        size_left = bucket_size - storage;
        if(input_packet_size <= size_left){
            storage += input_packet_size;
        }
        else{
            printf("Packet loss = %d \n", input_packet_size);
        }
        printf("Buffer size = %d out of bucket size = %d \n", storage, bucket_size);
        storage -= output_packet_size;
        

    }
}