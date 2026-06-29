#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

static void del_by_roll(int roll) {
    STUDENT *p = head, *prev = NULL;
    while (p) {
        if (p->roll == roll) {
            if (prev)
                prev->next = p->next;
            else
                head = p->next;
            free(p);
            printf("Record deleted successfully!\n");
            return;
        }
        prev = p;
        p = p->next;
    }
    printf("Record not found!\n");
}

static void del_by_name() {
    char name[50];
    int count = 0, roll, found = 0;
    STUDENT *p;

    printf("Enter Name: ");
    scanf(" %[^\n]", name);

    p = head;
    while (p) {
        if (strcasecmp(p->name, name) == 0) {
            if (!found) {
                printf("\nMatching Records:\n");
                printf("--------------------------------------\n");
                printf("Roll No     Name         Percentage\n");
                printf("--------------------------------------\n");
                found = 1;
            }
            printf("%-12d%-14s%.2f\n", p->roll, p->name, p->per);
            count++;
        }
        p = p->next;
    }

    if (!found) {
        printf("No records found with name: %s\n", name);
        return;
    }

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);
    del_by_roll(roll);
}

void stud_del() {
    char ch;
    if (!head) {
        printf("No records to delete!\n");
        return;
    }
    printf("\nR/r : Delete using Roll Number\n");
    printf("N/n : Delete using Name\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &ch);

    switch (ch) {
        case 'R':
        case 'r': {
            int roll;
            printf("Enter Roll Number: ");
            scanf("%d", &roll);
            del_by_roll(roll);
            break;
        }
        case 'N':
        case 'n':
            del_by_name();
            break;
        default:
            printf("Invalid choice!\n");
    }
}
