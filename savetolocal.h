#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char phone[10];
    char name[20];
    char address[50];
    char email[30];

}contact_save;


void endsession(contact_save students[],int TOTAL_STUDENTS)
{
    printf("|TO SAVE ADDED DATA LOCALLY ENTER 0|TO END THE SESSION WITHOUT SAVING DATA ENTER 1|\n");
    int n;
    scanf("%d",&n);
    if (n==0){
        save2local(students,TOTAL_STUDENTS);
        printf("DATA SAVED SUCCESSFULLY\n");
    }
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("END OF THE SESSION\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}




void save2local(contact_save students[],int TOTAL_STUDENTS)
{
    FILE *fptr;

    fptr=fopen("./database.txt","w");

    fprintf(fptr,"%d\n",TOTAL_STUDENTS);
    for (int i=0;i<TOTAL_STUDENTS;i++)
    {
        fprintf(fptr,"%s\n%s\n%s\n%s\n",students[i].phone,students[i].name,students[i].address,students[i].email);
    }
    fclose(fptr);
}