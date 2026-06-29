#include <stdio.h>
#include "student.h"

void stud_show() {
    STUDENT *p = head;
    if (!p) {
        printf("No records to display!\n");
        return;
    }
    printf("--------------------------------------\n");
    printf("%-12s%-14s%s\n", "Roll No", "Name", "Percentage");
    printf("--------------------------------------\n");
    while (p) {
        printf("%-12d%-14s%.2f\n", p->roll, p->name, p->per);
        p = p->next;
    }
    printf("--------------------------------------\n");
}
