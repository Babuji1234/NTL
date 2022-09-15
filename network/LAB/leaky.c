#include<stdio.h>
int main()
{
int incoming,outgoing,buck_size,n,store=0;
printf("enter bucket size,outgoing rate and no of inputs: ");
scanf("%d%d%d",&buck_size,&outgoing,&n);
while(n!=0)
{
printf("enter the incoming packet size: ");
scanf("%d",&incoming);
printf("incoming packet size %d \n",incoming);
if(incoming<=(buck_size-store))
{
store+=incoming;
printf("bucket buffer size %d out of %d \n",store,buck_size);

}
else
{
printf("dropped %d no of packets \n",incoming-(buck_size-store));
printf("bucket buffer size %d out of %d \n",store,buck_size);
store=buck_size;

}
store=store-outgoing;
printf("after outgoing %d  packets left out of %d in buffer \n",store,buck_size);
n--;

}
}
