#include <stdio.h>

void stud_add(void);
void stud_del(void);
void stud_show(void);
void stud_mod(void);
void stud_save(void);
void stud_save_sort(void);
void stud_load(void);

struct student
{
    int roll;
    char name[50];
    float percentage;
    struct student *next;
};

struct student *hptr = NULL;

int main()
{
    char choice, ch;
    do
    {
        printf("\nA/a : Add Student\n");
        printf("D/d : Delete Student\n");
        printf("S/s : Show Student records\n");
        printf("M/m : Modify Student records\n");
	printf("V/v : Save Records\n");
        printf("E/e : Exit\n");

        printf("\nEnter Your Option: \n");
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'A':
            case 'a':
                stud_add();
                break;

            case 'D':
            case 'd':
                stud_del();
                break;

            case 'S':
            case 's':
                stud_show();
                break;

            case 'M':
            case 'm':
                stud_mod();
                break;

	    case 'V':
            case 'v':
                stud_save_sort();
                break;

            case 'E':
            case 'e':

                printf("\nS/s : Save and Exit");
                printf("\nE/e : Exit Without Saving");

                printf("\nEnter Your Choice: ");
                scanf(" %c", &ch);

                if (ch == 'S' || ch == 's')
                {
                    stud_save();
                    return 0;
                }
                else if (ch == 'E' || ch == 'e')
                {
                    printf("\nExiting without saving!\n");
                    return 0;
                }
                else
                {
                    printf("\nInvalid Choice!\n");
                }

                break;

            default:
                printf("Invalid Option!\n");
        }

        printf("Do you want to enter again (Y/N)? \n");
        scanf(" %c", &ch);

    } while (ch == 'Y' || ch == 'y');

    return 0;
}
