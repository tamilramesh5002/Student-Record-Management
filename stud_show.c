#include <stdio.h>

struct student
{
    int roll;
    char name[50];
    float percentage;
    struct student *next;
};

extern struct student *hptr;

void stud_show(void)
{
    struct student *temp;

    if (hptr == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }


// entering the student details in order 
    printf("\n---------------------------------------------\n");
    printf("%-10s %-20s %-10s\n", "Roll No", "Name", "Percentage");
    printf("---------------------------------------------\n");

    temp = hptr;

    while (temp != NULL)
    {
        printf("%-10d %-20s %-10.1f\n",
               temp->roll, temp->name, temp->percentage);

        temp = temp->next;
    }

    printf("---------------------------------------------\n");
}
