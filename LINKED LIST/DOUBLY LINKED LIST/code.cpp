#include<stdio.h>
#include<conio.h>
typedef struct node
{
int data;
struct node *b;
struct node *f;
}dnode;
typedef struct
{
int count;
//node *pos;
dnode *head;
dnode *rear;
}list;
dnode *pnew,*ppre,*succ,*clist,*ploc;
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
pnew->f=NULL;
if(ppre==NULL)
{
pnew->b=NULL;
pnew->f=plist->head;
plist->head=pnew;
if(plist->count==0)
plist->rear=pnew;
}
else
{
pnew->f=ppre->f;
pnew->b=ppre;
}
if(ppre->f==NULL)
plist->rear=pnew;
else
succ->b=pnew;
ppre->f=pnew;
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
while(ploc->f!=NULL&&targ>ploc->data)
{
ppre=ploc;
ploc=ploc->f;
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
if(ploc->b!=NULL)
{
ppre=ploc->b;
ppre->f=ploc->f;
}
else
plist->head=ploc->f;
if(ploc->f!=NULL)
{
succ=ploc->f;
succ->b=ploc->b;
}
else
plist->rear=ploc->b;
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
clist=clist->f;
}
printf("\n");
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
case 2: printf("1. Insertion at beginning\n2. Insertion at middle or end\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:traversal();
	if(search())
	{
	ppre=NULL;
	succ=ploc;
	insert();
	}
	traversal();
	break;
	case 2:traversal();
	if(search())
	{
	ppre=ploc;
	succ=ploc->f;
	insert();
	}
	traversal();
	break;
	}
	break;
case 3: traversal();
	if(search())
	{
	succ=ploc->f;
	del();
	}
	traversal();
	break;
case 4:traversal();
	break;
case 5:exit(0);
}
}while(ch!=5);
getch();
}

