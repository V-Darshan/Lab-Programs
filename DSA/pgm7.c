#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
 char usn[15];
 char name[20];
 char pgm[10];
 int sem;
 long int phno;
 struct node *next;
};
typedef struct node NODE;
NODE *first=NULL,*cur=NULL,*last=NULL;
struct node * create()
{ struct node *temp;
 temp=(NODE*)malloc(sizeof(NODE));
 printf("Enter the usn\t");
 scanf("%s",temp->usn);
 printf("Enter the name\t");
 scanf("%s",temp->name);
 printf("Enter the pgm\t");
 scanf("%s",temp->pgm);
 printf("Enter the sem\t");
 scanf("%d",&temp->sem);
 printf("Enter the phno\t");
 scanf("%ld",&temp->phno);
 temp->next=NULL;
 return temp;
}
void display()
{ struct node *temp;
 int count=0;
 if(first==NULL)
{
 printf("Empty list\n");
 return;
}
 temp=first;
 while(temp!=NULL)
 {
 count++;
 printf("Student %d",count);
 printf("usn is %s\n",temp->usn);
 printf("name is %s\n",temp->name);
 printf("pgm is %s\n",temp->pgm);
 printf("sem is %d\n",temp->sem);
 printf("phno is %ld\n",temp->phno);
 temp=temp->next;
 }
 printf("There are %d students",count);
}
void insert_end()
{ struct node *temp;
 if(first==NULL)
 {

 first=create();
 }
 else
 {
 temp=create();
 cur=first;
 while(cur->next!=NULL)
 cur=cur->next;
 cur->next=temp;
 }
}
void delete_end()
{
 if(first==NULL)
 {
 printf("Empty list\n");
 return;
 }
 if(first->next==NULL)
 {
 free(first);
 first=NULL;
 return;
 }
 else
 {
 last=first;
 cur=first;
 while(cur->next!=NULL)
 {
 last=cur;
 cur=cur->next;
 }
 last->next=NULL;
 free(cur);
 }
}
void insert_front()
{ struct node *temp;
 if(first==NULL)
 {

 first=create();
 }
 else
 {
 temp=create();
 temp->next=first;
 first=temp;
 }
}
void delete_front()
{ struct node *temp;
 if(first==NULL)
 {
 printf("Empty list\n");
 return;
 }
 else
 {
 temp=first;
 first=first->next;
 free(temp);
 }
}
void main()
{
 int choice,n,i;
 while(1)
 {
 printf("\n\nList Operations\n\n");
 printf("\n1.Create list of n students\n");
 printf("\n2.Display status and count\n");
 printf("\n3.Insertion at front\n");
 printf("\n4.Delete at front\n");
 printf("\n5.Insert at end\n");
 printf("\n6.Delete at end\n");
 printf("\n7.Exit\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:printf("Enter the value of n\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
 insert_front();
 }
 break;
 case 2:display();
 break;
 case 3:insert_front();
 break;
 case 4:delete_front();
 break;
 case 5:insert_end();
 break;
 case 6:delete_end();
 break;
 case 7:exit(1);
 }
 }
}
