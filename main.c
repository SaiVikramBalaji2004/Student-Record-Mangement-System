#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

STUDENT *head = NULL;

void stud_sort_name()
 {
    if (!head || !head->next)
        return;
    int swapped;
    STUDENT *p;
    STUDENT *last = NULL;

    do
     {
        swapped = 0;
        p = head;
        while (p->next != last) 
        {
            if (strcasecmp(p->name, p->next->name) > 0)
             {
                STUDENT temp = *p;
                *p = *p->next;
                *p->next = temp;
                p->next->next = temp.next;
                swapped = 1;
            }
            p = p->next;
        }
        last = p;
    } while (swapped);
    printf("List sorted by Name!\n");
}

void stud_sort_per() 
{
    if (!head || !head->next)
        return;

    int swapped;
    STUDENT *p;
    STUDENT *last = NULL;

    do 
    {
        swapped = 0;
        p = head;
        while (p->next != last) 
        {
            if (p->per > p->next->per) 
            {
                STUDENT temp = *p;
                *p = *p->next;
                *p->next = temp;
                p->next->next = temp.next;
                swapped = 1;
            }
            p = p->next;
        }
        last = p;
    } while (swapped);
    printf("List sorted by Percentage!\n");
}

void stud_free() 
{
    STUDENT *p = head;
    while (p) 
    {
        STUDENT *temp = p;
        p = p->next;
        free(temp);
    }
    head = NULL;
}

int main() 
{
    char ch;
    stud_load();

    do {
        printf("\n**** STUDENT RECORD MENU ****\n\n");
        printf("A/a : Add New Record\n");
        printf("D/d : Delete a Record\n");
        printf("S/s : Show the List\n");
        printf("M/m : Modify a Record\n");
        printf("V/v : Save\n");
        printf("T/t : Sort the List\n");
        printf("E/e : Exit\n\n");
        printf("Enter Your Choice: ");
        scanf(" %c", &ch);

        switch (ch) {
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
                stud_save();
                break;
            case 'T':
            case 't': {
                char c;
                printf("\nN/n : Sort by Name\n");
                printf("P/p : Sort by Percentage\n");
                printf("Enter Your Choice: ");
                scanf(" %c", &c);
                switch (c) {
                    case 'N':
                    case 'n':
                        stud_sort_name();
                        break;
                    case 'P':
                    case 'p':
                        stud_sort_per();
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            }
            case 'E':
            case 'e': {
                char c;
                printf("\nS/s : Save and Exit\n");
                printf("E/e : Exit Without Saving\n");
                printf("Enter Your Choice: ");
                scanf(" %c", &c);
                switch (c) {
                    case 'S':
                    case 's':
                        stud_save();
                        stud_free();
                        printf("Goodbye!\n");
                        return 0;
                    case 'E':
                    case 'e':
                        stud_free();
                        printf("Goodbye!\n");
                        return 0;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            }
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}
