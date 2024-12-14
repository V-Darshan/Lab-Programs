#include<stdio.h>
#define max 5
#define mod(x) x%max
void linearprobe(int a[],int num,int key)
 {
 int i;
 if(a[key]==-1)
 {
 a[key]=num;
 }
 else
 {

 printf("\ncollision detected\n");
 for(i=mod(key+1); i!=key ; i= mod(++i))
 {
 if(a[i]==-1)
 break;
 }

 if(i!=key)
 {
 a[i]=num;
 printf("\nCollisssion avoided and inserted the element successfully\n");
 }
 else
 printf("hash table is full");
 }
 }

 void display(int a[])
 {
 int ch,i;
 printf("\n 1.Filtered display\n2. display all\n enter choice\n");
 scanf("%d",&ch);
 printf("\nHash table is:\n");
 for(i=0;i<max;i++)
 {
 if(a[i]>0 || ch-1)
 printf("%d %d\n",i,a[i]);
 }
 }

 void main()
 {
 int a[max],num,i;
 printf("Collision handling by linear probing\n");
 for(i=0;i<max;a[i++]=-1);
 do
 {
 printf("enter the data");
 scanf("%d",&num);
 linearprobe(a,num,mod(num));
 printf("want to continue 1/0 \n");
 scanf("%d",&i);
 }while(i);

 display(a);
 }
