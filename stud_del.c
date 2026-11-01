#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int roll;
    char name[50];
    float percentage;
    struct student *next;
};

extern struct student *hptr;

void stud_del(void)
{
    struct student *temp, *prev;
    int roll, found = 0;
    char name[50], choice;
    printf("\nR/r : Delete using Roll Number");
    printf("\nN/n : Delete using Name");
    printf("\nEnter Your Choice: ");
    scanf(" %c", &choice);

// Delete using Roll Number
    if (choice == 'R' || choice == 'r')
    {
        printf("Enter Roll Number: ");
        scanf("%d", &roll);

        temp = hptr;
        prev = NULL;

        while (temp != NULL)
        {
            if (temp->roll == roll)
            {
                if (prev == NULL)
                    hptr = temp->next;
                else
                    prev->next = temp->next;

                free(temp);

                printf("\nRecord Deleted Successfully!\n");
                return;
            }

            prev = temp;
            temp = temp->next;
        }
	printf("\nRoll Number Not Found!\n");
    }

// Delete the student details by using Name
    else if (choice == 'N' || choice == 'n')
    {
        printf("Enter Student Name: ");
        scanf(" %49[^\n]", name);

        temp = hptr;

        printf("\nStudent Details:\n");

// Display all matching student details because it prevent the duplicates
        while (temp != NULL)
        {
            if (strcmp(temp->name, name) == 0)
            {
                printf("\nRoll Number : %d", temp->roll);
                printf("\nName        : %s", temp->name);
                printf("\nPercentage  : %.2f\n", temp->percentage);

                found = 1;
            }

            temp = temp->next;
        }

        if (found == 0)
        {
            printf("\nStudent Name Not Found!\n");
            return;
        }

// after displaying the all details of that name and asking user to confirm which student to delete
        printf("\nEnter Roll Number to Delete: ");
        scanf("%d", &roll);

        temp = hptr;
        prev = NULL;

        while (temp != NULL)
        {
            if (temp->roll == roll &&
                strcmp(temp->name, name) == 0)
            {
                if (prev == NULL)
                    hptr = temp->next;
                else
                    prev->next = temp->next;

                free(temp);

                printf("\nRecord Deleted Successfully!\n");
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        printf("\nInvalid Roll Number!\n");
    }

    else
    {
        printf("\nInvalid Choice!\n");
    }
}
