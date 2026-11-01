#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    char name[50];
    float percentage;
    struct student *next;
};

extern struct student *hptr;

void stud_sort(char ch)
{
    struct student *temp, *nextnode;

    int roll;
    char name[50];
    float percentage;

    for (temp = hptr; temp != NULL; temp = temp->next)
    {
        for (nextnode = temp->next;
             nextnode != NULL;
             nextnode = nextnode->next)
        {
            if ((ch == 'N' || ch == 'n') &&
                strcmp(temp->name, nextnode->name) > 0)
            {
                roll = temp->roll;
                temp->roll = nextnode->roll;
                nextnode->roll = roll;

                strcpy(name, temp->name);
                strcpy(temp->name, nextnode->name);
                strcpy(nextnode->name, name);

                percentage = temp->percentage;
                temp->percentage = nextnode->percentage;
                nextnode->percentage = percentage;
            }

            else if ((ch == 'P' || ch == 'p') &&
                     temp->percentage > nextnode->percentage)
            {
                roll = temp->roll;
                temp->roll = nextnode->roll;
                nextnode->roll = roll;

                strcpy(name, temp->name);
                strcpy(temp->name, nextnode->name);
                strcpy(nextnode->name, name);

                percentage = temp->percentage;
                temp->percentage = nextnode->percentage;
                nextnode->percentage = percentage;
            }
        }
    }

    printf("\nSorting completed!\n");
}
