#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
char ssn[10];
char name[15];
char dept[10];
char desgn[15];
long int sal,phno;
struct node *prev,*next;
};
struct node *f=NULL,*l=NULL,*r=NULL,*rlink,*llink;
struct node *create();
void insertend();
void insertfront();
void deleteend();
void deletefront();
void display();
void main()
{
int choice,i,n;
while(1)
{
 printf("\n 1-create \n 2-display \n 3-insertend \n 4-deleteend \n 5-insertfront \n 6-deletefront \n 7-
dequeue \n 8-exit \n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:printf("enter the no of employee\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 insertfront();
 break;
 case 2:display();
 break;
 case 3:insertend();
 break;
 case 4:deleteend();
 break;
 case 5:insertfront();
 break;
 case 6:deletefront();
 break;
 case 7:printf("since insertion and deletion can be done from both end it works as a double ended
queue\n");
 case 8:exit(0);
 }
}
}
struct node *create()
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->next=NULL;
temp->prev=NULL;
printf("enter ssn \n");
scanf("%s",temp->ssn);
printf("enter name \n");
scanf("%s",temp->name);
printf("enter dept \n");
scanf("%s",temp->dept);
printf("enter desgn\n");
scanf("%s",temp->desgn);
printf("enter salary\n");
scanf("%ld",&temp->sal);
printf("enter phno \n");
scanf("%ld",&temp->phno);
return temp;
}
void insertend()
{
struct node *temp;
temp=create();
if(f==NULL)
{
 f=temp;
 l=temp;
 return;
}
else
{
 l->next=temp;
 temp->prev=l;
 l=temp;
}
}
void insertfront()
{
struct node *temp;
temp=create();
if(f==NULL)
{
 f=temp;
 l=temp;
 return;
}
else
{
 temp->next=f;
 f->prev=temp;
 f=temp;
}
}
void deleteend()
{
struct node *temp;
if(f==NULL)
{
 printf("empty list\n");
 return;
}
temp=l;
if(f==l)
{
 f=NULL;
 l=NULL;
 free(temp);
}
else
{
 l=l->prev;
 l->next=NULL;
 free(temp);
}
}

void deletefront()
{
struct node *temp;
if(f==NULL)
{
 printf("empty list\n");
 return;
}
temp=f;
if(f==l)
{
 f=NULL;
 l=NULL;
 free(temp);
}
else
{
 f=f->next;
 f->prev=NULL;
 free(temp);
}
}
void display()
{
struct node *temp;
if(f==NULL)
{
 printf("the list is empty\n");
 return;
}
 printf("elements in the forward direction\n");
 for(temp=f;temp;temp=temp->next)
 printf("\n %10s %10s %10s %10s %ld %ld",temp->ssn,temp->name,temp->dept,temp->desgn,temp-
>sal,temp->phno);
 printf("\n");
 printf("elements in the backward direction\n");
 for(temp=l;temp;temp=temp->prev)
 printf("\n %10s %10s %10s %10s %ld %ld",temp->ssn,temp->name,temp->dept,temp->desgn,temp-
>sal,temp->phno);
}
