
#include <stdio.h>

int main()
{
    struct student_details{
        char id[10];
        int age;
        float marks;
        
    };
    struct student_details stud_d[10];
    int i=0,op;
    while(1)
    {
        printf("\nEnter the following details for Student %d",i);
        printf("\nEnter the ID No. :  ");
        scanf("%s",&stud_d[i].id);
        printf("Enter the Age:  ");
        scanf("%d",&stud_d[i].age);
        printf("Enter the Marks:  ");
        scanf("%f",&stud_d[i].marks);
        
        if (stud_d[i].age<21)
        {
            printf("\nYour are not eligible for admissions");
            printf("\nYour age must be above 20.");
            continue;
        }
        else if(stud_d[i].marks<65)
        {
            printf("\nYour are not eligible for admissions");
            printf("\nYour marks must be greater or equal to 65.");
            continue;
        }
        else
        {
            printf("\nYou are eligible for admissions");
        }
        
        printf("\nEnter '0' Exit \n OR\nEnter any other number to add another response: ");
        scanf("%d",&op);
        if (op==0)
        {
            break;
        }
        i++;
    }
    printf("\nThe following are the details of the students eligible for admissions");
    for (int j=0;j<(i+1);j++)
    {
        printf("\nThe following are the details of the Student %d:",j);
        printf("\nID: %s",stud_d[j].id);
        printf("\nAge: %d",stud_d[j].age);
        printf("\nMarks: %f",stud_d[j].marks);
    }
    return 0;
}
