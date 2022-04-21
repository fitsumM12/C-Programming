#include<stdio.h>
#include<conio.h>
typedef struct node
{
int data;
struct node *link;
}dnode;
typedef struct
{
int count;
//node *pos;
dnode *head;
dnode *rear;
}list;
dnode *pnew,*ppre,*clist,*ploc,*last;
list *plist;
void createlist()
{
plist=(list*)malloc(sizeof(list));
plist->head=NULL;
plist->rear=NULL;
plist->count=0;
}
void insert()
{
pnew=(dnode*)malloc(sizeof(dnode));
printf("enter the data to be inserted\n");
scanf("%d",&pnew->data);
pnew->link=NULL;
if(ppre==NULL)
{
pnew->link=plist->head;
plist->head=pnew;
if(plist->count==0)
plist->rear=pnew;
last=plist->rear;
last->link=pnew;
}
else
{
pnew->link=ppre->link;
ppre->link=pnew;
if(pnew->link==plist->head)
{
plist->rear=pnew;
}
}
plist->count++;
}
int search()
{
int targ;
ppre=NULL;
ploc=plist->head;
if(plist->count==0)
printf("list is empty\n");
else
{
printf("enter the data\n");
scanf("%d",&targ);
while(ploc->link!=plist->head&&targ>ploc->data)
{
ppre=ploc;
ploc=ploc->link;
}
if(ploc==NULL)
{
printf("Data not found in the list");
return 0;
}
else
{
if(targ==ploc->data)
{
printf("element found\n");
return 1;
}
else
{
printf("element not found\n");
return 0;
}
}
}
}
void del()
{
if(ppre==NULL)
{
plist->head=ploc->link;
last=plist->rear;
last->link=plist->head;
}
else
ppre->link=ploc->link;
if(ploc->link==plist->head)
{
plist->rear=ppre;
last=plist->rear;
last=plist->head;
}
plist->count--;
free(ploc);
}
void traversal()
{
int i;
if(plist->count==0)
printf("list is empty\n");
else
{
clist=plist->head;
for(i=plist->count;i>0;i--)
{
printf("%d\t",clist->data);
clist=clist->link;
}
}
}
void main()
{
int ch;
clrscr();
printf("List menu\n");
printf("1.Create list\n2.Insertion\n3.Deletion\n4.Traversal\n5.Exit\n");
do
{
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:createlist();
	break;
case 2:printf("1. Insertion at beginning\n 2.Insertion at middle or end\n");
       printf("enter your choice\n");
       scanf("%d",&ch);
       switch(ch)
       {
       case 1:traversal();
	      ppre=NULL;
	      insert();
	      traversal();
	      break;
       case 2:  traversal();
		if(search())
	       {
	       ppre=ploc;
	       insert();
	       traversal();
	       }
	       break;
	       }
       break;
case 3: traversal();
	if(search())
	del();
	traversal();
	break;
case 4:traversal();
	break;
case 5:exit(0);
}
}while(ch!=5);
getch();
}

