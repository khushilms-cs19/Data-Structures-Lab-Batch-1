#include<stdio.h>
#include<process.h>
#define QUE_SIZE 3


int item,front=0,rear=-1,q[10];
void insertrear()
{
    if(rear==QUE_SIZE-1)
    {
        printf("\n-------------------------------\nQUEUE OVERFLOW\n-------------------------------\n");
        return;
    }
    rear+=1;
    q[rear]=item;
}

int deletefront()
{
    if(front>rear)
    {
        front=0;
        rear=-1;
        return -1;
    }
    return q[front++];
}

void displayQ()
{
    int i;
    if(front>rear)
    {
        printf("\n-----------------------------------\nQUEUE IS EMPTY\n-----------------------------------\n");
        return;
    }
    printf("Contents of the queue:\n");
    for(i=front;i<=rear;i++)
    {
        printf("%d\n",q[i]);
    }
}

void main()
{
    int choice;
    for(;;)
    {
        printf("\n1:Insert Rear\n2:Delete Front\n3:Display Queue\n4:EXIT\n");
        printf("Enter your choice:  ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nEnter the value to be inserted:  ");
                   scanf("%d",&item);
                   insertrear();
                   break;
            case 2:item=deletefront();
                   if(item==-1)
                       printf("\n--------------------------------------\nQUEUE IS EMPTY\n--------------------------------------\n");
                   else 
                       printf("Item Deleted= %d\n",item);
                   break;
            case 3:displayQ();
                   break;
            default:return;       
        }
    }
}
