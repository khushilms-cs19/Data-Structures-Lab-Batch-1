#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory full\n");
        exit(0);
    }
    return x;
}

void freenode(NODE x)
{
    free(x);
}
void display (NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Linked List is empty ,Cannot Display items");
        return;
    }
    printf("The contents of the linked list are: \n");
    for(temp=first;temp!=NULL;temp=temp->link)
    {
        printf("%d\n",temp->info);
    }

}
NODE insert_rear(int item,NODE first)
{
    NODE temp,cur;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)
    {
        return temp;
    }
    cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}

NODE concat(NODE first,NODE second)
{
    NODE cur;
    if(first==NULL)
        return second;
    if(second==NULL)
        return first;
    cur=first;
    while(cur->link!=NULL)
        cur=cur->link;
    cur->link=second;
    return first;            
}

NODE reverse(NODE first)
{
    NODE cur,temp;
    cur=NULL;
    while(first!=NULL)
    {
        temp=first;
        first=first->link;
        temp->link=cur;
        cur=temp;
    }
    return cur;
}

int main()
{
    NODE first=NULL;
    NODE second=NULL;
    int item, choice,llno;
    for(;;)
    {
        printf("1:insert rear\n2:Concatenate the two linked lists\n3:reverse the linked list\n4:Display\n5:EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the LL number (1 or 2) :");
                    scanf("%d",&llno);
                    printf("Enter the item at the rear end: ");
                    scanf("%d",&item);
                    if(llno==1)
                        first=insert_rear(item,first);
                    else
                        second=insert_rear(item,second);    
                    break;

            case 2: first=concat(first,second);
                    break;
            case 3: printf("Enter the LL number (1 or 2) :");
                    scanf("%d",&llno);
                    if(llno==1)
                        first=reverse(first);
                    else
                        second=reverse(second);
            case 4: printf("The contents of the first LL:\n");
                    display(first);
                    printf("\n********************************\n");
                    printf("\nThe contents of the second LL:\n");
                    display(second);
                    break;
            case 5: exit(0);
                    break;
            default: printf("Enter a valid option\n");
        }
    }
    return 0;
}