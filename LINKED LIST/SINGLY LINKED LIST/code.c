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
dnode *head;
dnode *rear;
}list;
dnode *pnew,*ppre,*clist,*ploc;
list *plist;
void createlist()
{
plist=(list *)malloc(sizeof(list));
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
}
else
{
pnew->link=ppre->link;
ppre->link=pnew;
if(pnew->link==NULL)
plist->rear=pnew;
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
while(ploc->link!=NULL&&targ>ploc->data)
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
plist->head=ploc->link;
else
ppre->link=ploc->link;
if(ploc->link==NULL)
plist->rear=ppre;
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
printf("\nenter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:createlist();
	break;
case 2: printf("1.Insert at begining\n2. Insert at middle or last\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: ppre=NULL;
		insert();
		break;
	case 2:if(search())
	       {
		insert();
	       }
	      break;
	}
	break;
case 3: traversal();
	search();
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

