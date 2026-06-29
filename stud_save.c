#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void stud_save() {
    FILE *fp = fopen(FILENAME, "wb");
    if (!fp) {
        printf("Error opening file for writing!\n");
        return;
    }
    STUDENT *p = head;
    while (p) {
        fwrite(p, sizeof(STUDENT), 1, fp);
        p = p->next;
    }
    fclose(fp);
    printf("Records saved successfully!\n");
}

void stud_load() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp)
        return;

    STUDENT temp;
    while (fread(&temp, sizeof(STUDENT), 1, fp) == 1) {
        STUDENT *node = (STUDENT *)malloc(sizeof(STUDENT));
        if (!node) {
            printf("Memory allocation failed!\n");
            break;
        }
        *node = temp;
        node->next = NULL;

        if (!head) {
            head = node;
        } else {
            STUDENT *p = head;
            while (p->next)
                p = p->next;
            p->next = node;
        }
    }
    fclose(fp);
}
