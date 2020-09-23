#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5
int top=-1;
int s[10];
int item;
void push()
{
    if(top==STACK_SIZE-1)
    {
        printf("\nSTACK OVERFLOW\n");
        return;
    }
    top+=1;
    s[top]=item;
}
int pop()
{
    if(top==-1)
        return -1;
    return s[top--];    
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\nSTACK UNDERFLOW\n");
        return;
    }
    printf("The contents fo the stack are:\n");
    for (i=0;i<=top;i++)
    {
        printf("%d\n",s[i]);
    }
}
void main()
{
    int item_deleted,choice;
    while(1)
    {
        printf("\n1: Push\n2: Pop\n3: Display\n4: EXIT\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            printf("\nEnter the item to be inserted:");
            scanf("%d",&item);
            push();
            break;
            case 2:
            item_deleted=pop();
            if(item_deleted==-1)
            {
                printf("\nSTACK UNDERFLOW\n");
            } 
            else
            {
                printf("\nThe item deleted is %d\n",item_deleted);
            }
            break;
            case 3:
            display();
            break;
            default:exit(0);


        }
    }

}
