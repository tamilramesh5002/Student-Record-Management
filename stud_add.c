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

void stud_add(void)
{
    struct student *newnode, *temp;
    int roll = 1, find, i;
    
// Creating memory
    newnode = malloc(sizeof(struct student));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }


// Inserting node into linked list
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


// Getting student name from user(keyboard)
    printf("Enter Student Name: ");

    while (getchar() != '\n');

    fgets(newnode->name, 50, stdin);


// Removing newline and adding '\0' char
    i = 0;
    while (newnode->name[i] != '\0')
    {
        if (newnode->name[i] == '\n')
        {
            newnode->name[i] = '\0';
            break;
        }
        i++;
    }


// Getting percentage from user
    printf("Enter Percentage: ");

    if (scanf("%f", &newnode->percentage) != 1)
    {
        printf("Invalid input!\n");
        free(newnode);

        while (getchar() != '\n');

        return;
    }

    if (newnode->percentage < 0 ||
        newnode->percentage > 100)
    {
        printf("Invalid percentage!\n");
        free(newnode);
        return;
    }


// Finding smallest available roll number
    do
    {
        find = 0;
        temp = hptr;

        while (temp != NULL)
        {
            if (temp->roll == roll)
            {
                find = 1;
                roll++;
                break;
            }

            temp = temp->next;
        }

    } while (find);

    newnode->roll = roll;
    newnode->next = NULL;


    printf("\nStudent Added Successfully!\n");
    printf("Generated Roll Number: %d\n", newnode->roll);
}
