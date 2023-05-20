#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char phone[10];
    char name[20];
    char address[50];
    char email[30];

}contact_file;

void add2file(contact_file students[],int TOTAL_STUDENTS)
{
    FILE *fptr;
    
    fptr=fopen("D:\\Semester 4\\CO253 - Introduction to Programming and Networking for Electrical Engineering\\Project\\ContactManagementSystemInC\\output.txt","w");

    fprintf(fptr,"LIST OF ALL CONTACTS\n");
    fprintf(fptr,"-----------------------------------------------------------------------------------------------------------------\n");
    fprintf(fptr,"|   PHONE   ");
    fprintf(fptr,"|        NAME       ");
    fprintf(fptr,"|                       ADDRESS                   ");
    fprintf(fptr,"|              EMAIL          |\n");
    fprintf(fptr,"-----------------------------------------------------------------------------------------------------------------\n");


    for(int i=0;i<TOTAL_STUDENTS;i++)
    {
        fprintf(fptr,"|");
        fprintf(fptr," %s",students[i].phone);
        int phonelength=10-strlen(students[i].phone);
        for(int k=0;k<phonelength;k++){
            fprintf(fptr," ");
        }

        fprintf(fptr,"|");
        fprintf(fptr," %s",students[i].name);
        int namelength=18-strlen(students[i].name);
        for(int k=0;k<namelength;k++){
            fprintf(fptr," ");
        }

        fprintf(fptr,"|");
        fprintf(fptr," %s",students[i].address);
        int addresslength=48-strlen(students[i].address);
        for(int k=0;k<addresslength;k++){
            fprintf(fptr," ");
        }

        fprintf(fptr,"|");
        fprintf(fptr," %s",students[i].email);
        int emaillength=28-strlen(students[i].email);
        for(int k=0;k<emaillength;k++){
            fprintf(fptr," ");
        }

        fprintf(fptr,"|\n");


    }
    fprintf(fptr,"-----------------------------------------------------------------------------------------------------------------\n");
    fclose(fptr);
    printf("OPERATION SUCCESSFUL\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    

}