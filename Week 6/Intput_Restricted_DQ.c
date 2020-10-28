#include<stdio.h>
#include<conio.h>
#include<process.h>
#define qsize 5
int f=0,r=-1,ch;
int item,q[10];

int isfull()
{
    return(r==qsize-1)?1:0;
}
int isempty()
{
    return(f>r)?1:0;
}
void insert_rear()
{
    if(isfull())
	{
	    printf("queue overflow\n");
	    return;
	}
    r=r+1;
    q[r]=item;
}
void delete_front()
{
    if(isempty())
	{
	    printf("queue empty\n");
	    return;
	}
    printf("item deleted is %d\n",q[(f)++]);
    if(f>r)
	{
	    f=0;
	    r=-1;
	}
}
void delete_rear()
{
    if(isempty())
	{
	    printf("queue is empty\n");
	    return;
	}
    printf("item deleted is %d\n",q[(r)--]);
    if(f>r)
	{ 
        f=0;
	    r=-1;
	}
}
void display()
{
	
    int i;
    if(isempty())
	{
	    printf("queue empty\n");
	    return;
	}
    for(i=f;i<=r;i++)
	printf("%d\n",q[i]);
}
void main()
{
    for(;;)
    {
        printf("\n*****************************************************\n");
	    printf("1.insert_rear\n2.delete_rear\n3.delete_front\n4.display\n5.exit\n");
	    printf("enter choice: ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    case 1:printf("Enter the item: ");
			  scanf("%d",&item);
			  insert_rear();
			  break;
	    case 2:delete_rear();
			  break;
	    case 3:delete_front();
			  break;
	    case 4:display();
			  break;
	    default:exit(0);
        }
        printf("\n*****************************************************\n");
    }
}
