#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char phone[10];
    char name[20];
    char address[50];
    char email[30];

}contact_read;

void update(contact_read students[],int* TOTAL_STUDENTS)
{
    FILE *fptr;
    fptr = fopen("./database.txt","r");

    if (fptr==NULL){
        *TOTAL_STUDENTS=0;
        return;
    }
    int n;
    fscanf(fptr,"%d",&n);
    *TOTAL_STUDENTS=n;
    for(int i=0;i<*TOTAL_STUDENTS;i++)
    {
        char phone[10];
        fscanf(fptr,"%s",phone);
        strcpy(students[i].phone,phone);

        char name[20];
        fscanf(fptr,"%s",name);
        strcpy(students[i].name,name);

        char address[50];
        fscanf(fptr," %[^\n]s",address);
        strcpy(students[i].address,address);

        char email[30];
        fscanf(fptr,"%s",email);
        strcpy(students[i].email,email);
    }
}