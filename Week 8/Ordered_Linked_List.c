#include <stdio.h>
#include <stdlib.h>
#include <process.h>
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
        printf("Memory is full\n");
        exit(0);
    }
    return x;
}

void freenode(NODE x)
{
    free(x);
}
NODE order_list(int item,NODE first)
{
    NODE temp,prev,cur;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(first==NULL) return temp;
    if(item<first->info)
    {
        temp->link=first;
        return temp;
    }
    prev=NULL;
    cur=first;
    while(cur!=NULL && item>cur->info)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=temp;
    temp->link=cur;
    return first;
}
NODE delete_info(int key,NODE first)
{
    NODE prev,cur;
    if(first==NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    if(key==first->info)
    {
        cur=first;
        first=first->link;
        freenode(cur);
        return first;
    }
    prev=NULL;
    cur=first;
    while(cur!=NULL)
    {
        if(key==cur->info)break;
            prev=cur;
        cur=cur->link;
    }
    if(cur==NULL)
    {
        printf("search is unsuccessfull\n");
        return first;
    }
    prev->link=cur->link;
    printf("key deleted is %d",cur->info);
    freenode(cur);
    return first;
}
void display(NODE first)
{
    NODE temp;
    if(first==NULL)
        printf("List is EMPTY , Cannot Display Items\n");
    printf("\n***************************************************************\n");    
    for(temp=first;temp!=NULL;temp=temp->link)
    {
        printf("%d\n",temp->info);
    }    
    printf("\n***************************************************************\n");    

}

void main()
{
    int item,choice,pos,key;
    NODE first=NULL;
    for(;;)
    {
        printf("\n1:Insert in Order List\n2:Delete Item\n3:display\n4:Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the item to be inserted in ordered list: ");
                scanf("%d",&item);
                first=order_list(item,first);
                break;
            case 2:printf("Enter the key to be Deleted: ");
            scanf("%d",&key);
            first=delete_info(key,first);
            break;    
            case 3:display(first);
	            break;
            default:exit(0);
	            break;
        }
    }
}