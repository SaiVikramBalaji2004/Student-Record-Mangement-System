#ifndef STUDENT_H
#define STUDENT_H

#define FILENAME "student.dat"

typedef struct student {
    int roll;
    char name[50];
    float per;
    struct student *next;
} STUDENT;

extern STUDENT *head;

void stud_add();
void stud_del();
void stud_show();
void stud_mod();
void stud_save();
void stud_load();
void stud_sort_name();
void stud_sort_per();
void stud_free();

#endif
