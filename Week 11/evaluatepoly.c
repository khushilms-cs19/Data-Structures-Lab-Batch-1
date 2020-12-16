#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    float cf;
    float px;
    float py;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc (sizeof(struct node));
    if(x==NULL)
    {
        printf("mem full\n");
        exit(0);
    }
    return x;
}
NODE insert_rear(float cf,float x, float y, NODE head)
{
    NODE temp,cur;
    temp=getnode();
    temp->cf=cf;
    temp->px=x;
    temp->py=y;
    cur=head->link;
    while(cur->link!=head)
    {
        cur=cur->link;
    }
    cur->link=temp;
    temp->link=head;
    return head;
}

NODE read_poly(NODE head)
{
    int i;
    float cf,px,py;
    printf("Enter the coefficient as -999 to end the polynomial\n");
    for(i=1;;i++)
    {
        printf("Enter the %d term\n",i);
        printf("Coeff: ");
        scanf("%f",&cf);
        if(cf==-999)
        {
            break;
        }
        printf("Pow x: ");
        scanf("%f",&px);
        printf("pow y: ");
        scanf("%f",&py);
        head=insert_rear(cf,px,py,head);
    }
    return head;
}

float evaluate(NODE head)
{
    float x,y,sum=0;
    NODE poly;
    printf("Enter the value of x and y: ");
    scanf("%f%f",&x,&y);
    poly=head->link;
    while(poly!=head)
    {
        sum=sum+poly->cf*pow(x,poly->px)*pow(y,poly->py);
        poly=poly->link;
    }
    return sum;
}
void display(NODE head)
{
    NODE temp;
    if(head->link==head)
    {
        printf("Polynomial does not exist\n");
        return ;
    }
    temp=head->link;
    while(temp!=head)
    {
        printf("+%5.2fx^%3.1fy^%3.1f",temp->cf,temp->px,temp->py);
        temp=temp->link;
    }
    printf("\n");
}

void main()
{
    NODE head;
    float res;
    head=getnode();
    head->link=head;
    printf("Enter the polynomials:\n");
    head=read_poly(head);
    res=evaluate(head);
    printf("The given polynomial is\n");
    display(head);
    printf("The Result %f\n",res);
}