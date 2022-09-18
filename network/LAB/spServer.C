#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int i,n,ch;
    char input[20];
    FILE *in;
    random();
    printf("\n\t\tStop and wait\n");
    printf("\n1.Send \n2.Check ACK\n3.End");
    while(1){
        printf("Enter the choice .. ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            in = fopen("data.txt","w");
            printf("Enter the data");
            scanf("%s",input);
            break;
        
        default:
            break;
        }
    }
}