#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    char name[50];
    float percentage;
    struct student *next;
};

extern struct student *hptr;

void stud_sort(char ch);
void stud_show(void);

void stud_save(void)
{
    FILE *fp;
    struct student *temp;

    fp = fopen("student.dat", "w");

    if (fp == NULL)
    {
        printf("File opening failed!\n");
        return;
    }

    temp = hptr;

    while (temp != NULL)
    {
        fprintf(fp, "%d %s %.2f\n",
                temp->roll,
                temp->name,
                temp->percentage);

        temp = temp->next;
    }

    fclose(fp);

    printf("Records saved successfully!\n");
}

void stud_load(void)
{
    FILE *fp;
    struct student *newnode, *temp;

    fp = fopen("student.dat", "r");

    if (fp == NULL)
    {
        return;
    }

    while (1)
    {
        newnode = malloc(sizeof(struct student));

        if (newnode == NULL)
        {
            printf("Memory allocation failed!\n");
            fclose(fp);
            return;
        }

        if (fscanf(fp, "%d %49s %f",
                   &newnode->roll,
                   newnode->name,
                   &newnode->percentage) != 3)
        {
            free(newnode);
            break;
        }

        newnode->next = NULL;

        if (hptr == NULL)
        {
            hptr = newnode;
        }
        else
        {
            temp = hptr;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    fclose(fp);

    printf("Records loaded successfully!\n");
}

void stud_save_sort(void)
{
    char ch;

    stud_save();

    printf("\nDo you want to sort the records? (Y/N): ");
    scanf(" %c", &ch);

    if (ch == 'Y' || ch == 'y')
    {
        printf("\nN/n - Sort by Name");
        printf("\nP/p - Sort by Percentage");

        printf("\nEnter your choice: ");
        scanf(" %c", &ch);

        if (ch == 'N' || ch == 'n' ||
            ch == 'P' || ch == 'p')
        {
            stud_sort(ch);

            printf("\nSorted Records:\n");
            stud_show();

            /* Save the sorted order */
            stud_save();
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }
}
