#include <stdio.h>
#include <string.h>
#include "student.h"

static void modify_record(int roll) {
    STUDENT *p = head;
    while (p) {
        if (p->roll == roll) {
            char ch;
            printf("\nN/n : Name\n");
            printf("P/p : Percentage\n");
            printf("Enter Your Choice: ");
            scanf(" %c", &ch);
            switch (ch) {
                case 'N':
                case 'n':
                    printf("Enter new Name: ");
                    scanf(" %[^\n]", p->name);
                    printf("Name modified successfully!\n");
                    break;
                case 'P':
                case 'p':
                    printf("Enter new Percentage: ");
                    scanf("%f", &p->per);
                    printf("Percentage modified successfully!\n");
                    break;
                default:
                    printf("Invalid choice!\n");
            }
            return;
        }
        p = p->next;
    }
    printf("Record not found!\n");
}

void stud_mod() {
    char ch;
    if (!head) {
        printf("No records to modify!\n");
        return;
    }

    printf("\nR/r : Roll Number\n");
    printf("N/n : Name\n");
    printf("P/p : Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &ch);

    switch (ch) {
        case 'R':
        case 'r': {
            int roll;
            printf("Enter Roll Number: ");
            scanf("%d", &roll);
            modify_record(roll);
            break;
        }
        case 'N':
        case 'n': {
            char name[50];
            int found = 0;
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
                }
                p = p->next;
            }
            if (!found) {
                printf("No records found!\n");
            } else {
                int roll;
                printf("\nEnter Roll Number to modify: ");
                scanf("%d", &roll);
                modify_record(roll);
            }
            break;
        }
        case 'P':
        case 'p': {
            float per;
            int found = 0;
            STUDENT *p;
            printf("Enter Percentage: ");
            scanf("%f", &per);
            p = head;
            while (p) {
                if (p->per == per) {
                    if (!found) {
                        printf("\nMatching Records:\n");
                        printf("--------------------------------------\n");
                        printf("Roll No     Name         Percentage\n");
                        printf("--------------------------------------\n");
                        found = 1;
                    }
                    printf("%-12d%-14s%.2f\n", p->roll, p->name, p->per);
                }
                p = p->next;
            }
            if (!found) {
                printf("No records found!\n");
            } else {
                int roll;
                printf("\nEnter Roll Number to modify: ");
                scanf("%d", &roll);
                modify_record(roll);
            }
            break;
        }
        default:
            printf("Invalid choice!\n");
    }
}
