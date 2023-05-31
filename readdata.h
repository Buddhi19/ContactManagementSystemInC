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
        fclose(fptr);
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
    fclose(fptr);

}

void updateusers(char users[],char passwords[],int* USERS)
{
    FILE *fptr1;
    fptr1 = fopen("./users.txt","r");

    if (fptr1==NULL){
        *USERS=0;
        fclose(fptr1);
        return;
    }
    int n;
    fscanf(fptr1,"%d",&n);
    *USERS=n;
    for(int i=0;i<*USERS;i++)
    {
        scanf("%s",users[i]);
        scanf("%s",passwords[i]);
    }
    fclose(fptr1);

}