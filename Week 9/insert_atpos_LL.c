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

NODE delete_pos(int pos,NODE first)
{
    NODE prev,cur;
    int count;
    if(first==NULL || pos<=0)
    {
        printf("Invalid position\n");
        return NULL;
    }
    if(pos==1)
    {
        cur=first;
        first=first->link;
        freenode(cur);
        return first;
    }
    prev=NULL;
    cur=first;
    count=1;
    while(cur!=NULL)
    {
        if(count==pos)
        {
            break;
        }
        prev=cur;
        cur=cur->link;
        count++;
    }
    if(count!=pos)
    {
        printf("Invalid Position\n");
        return first;
    }
    prev->link=cur->link;
    freenode(cur);
    return first;
}

NODE insert_pos(int item,int pos,NODE first)
{
    NODE temp,cur,prev;
    int count;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(first==NULL && pos==1)
    {
        return temp;
    }
    if(first==NULL)
    {
        printf("Invalid Position\n");
        return NULL;
    }
    if(pos==1)
    {
        temp->link=first;
        return temp;
    }
    count=1;
    prev=NULL;
    cur=first;
    while(cur!=NULL && count!=pos)
    {
        prev=cur;
        cur=cur->link;
        count++;
    }
    if(count==pos)
    {
        prev->link=temp;
        temp->link=cur;
        return first;
    }
    printf("invalid position\n");
    return first;
}

void display (NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Linked List is empty ,Cannot Display items");
    }
    printf("The contents of the linked list are: \n");
    for(temp=first;temp!=NULL;temp=temp->link)
    {
        printf("%d\n",temp->info);
    }
}

int main()
{
    NODE first=NULL;
    int item, choice ,pos;
    for(;;)
    {
        printf("1:insert rear\n2:Delete at a position\n3:Insert at a position\n4:Display\n5:EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the item at the rear end: ");
                    scanf("%d",&item);
                    first=insert_rear(item,first);
                    break;

            case 2: printf("Enter the position :");
                    scanf("%d",&pos);
                    first=delete_pos(pos,first);
                    break;

            case 3: printf("Enter the item and the position : ");
                    scanf("%d%d",&item,&pos);
                    first=insert_pos(item,pos,first);
                    break;

            case 4: display(first);
                    break;

            case 5: exit(0);
                    break;
            default: printf("Enter a valid option\n");
        }
    }
    return 0;
}