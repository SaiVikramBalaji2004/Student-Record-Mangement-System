#include <stdio.h>
#include <stdlib.h>
#include "student.h"

static int find_next_roll() {
    int roll = 1;
    STUDENT *p;
    while (1) {
        int found = 0;
        p = head;
        while (p) {
            if (p->roll == roll) {
                found = 1;
                break;
            }
            p = p->next;
        }
        if (!found)
            return roll;
        roll++;
    }
}

void stud_add() {
    STUDENT *p, *temp;
    temp = (STUDENT *)malloc(sizeof(STUDENT));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->roll = find_next_roll();
    printf("Enter Name: ");
    scanf(" %[^\n]", temp->name);
    printf("Enter Percentage: ");
    scanf("%f", &temp->per);
    temp->next = NULL;

    if (!head) {
        head = temp;
    } else {
        p = head;
        while (p->next)
            p = p->next;
        p->next = temp;
    }
    printf("Record added successfully! Roll No: %d\n", temp->roll);
}
