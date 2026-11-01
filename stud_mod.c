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

void stud_mod(void)
{
    struct student *temp;
    int roll, found = 0;
    char name[50], ch;

//entering the choice to search
    printf("\nEnter options \n");
    printf("\nR/r : Roll Number\n");
    printf("N/n : Name\n");

    printf("Enter Your Choice: ");
    scanf(" %c", &ch);

    temp = hptr;

    switch (ch)
    {
        case 'R':
        case 'r':
            printf("Enter Roll Number: ");
            scanf("%d", &roll);
            while (temp != NULL)
            {
                if (temp->roll == roll)
                {
                    found = 1;
                    printf("\nRoll No: %d  Name: %s  Percentage: %.1f\n",
                           temp->roll, temp->name, temp->percentage);
                    break;
                }

                temp = temp->next;
            }
            break;


	    case 'N':
	    case 'n':
	   	 printf("Enter Student Name: ");
   		 scanf(" %[^\n]", name);

   		 while (temp != NULL)
 		   {
    		    if (strcmp(temp->name, name) == 0)
 		       {
		            printf("\nRoll No: %d  Name: %s  Percentage: %.1f\n",
    		               temp->roll, temp->name, temp->percentage);
       		     found = 1;
          		  break;
     			}

        		temp = temp->next;
   		 }

   		 break;


        default:
            printf("Invalid Choice!\n");
            return;
    }

    if (!found)
    {
        printf("\nRecord Not Found!\n");
        return;
    }


//entering the modify field    
    printf("\nEnter the modification mode\n");
    printf("\nN/n : Name\n");
    printf("P/p : Percentage\n");

    printf("Enter Your Choice: ");
    scanf(" %c", &ch);

    switch (ch)
    {
        case 'N':
        case 'n':
            printf("Enter New Name: ");
            scanf(" %[^\n]", temp->name);
            printf("\nName Modified Successfully!\n");
            break;

        case 'P':
        case 'p':
            printf("Enter New Percentage: ");
            scanf("%f", &temp->percentage); 
            printf("\nPercentage Modified Successfully!\n");
            break;

        default:
            printf("Invalid Choice!\n");
    }
}
