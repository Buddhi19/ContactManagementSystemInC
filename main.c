//=========================================== HEADER FILES ==============================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>
#include <ctype.h>

//=======================================IMPORTING LOCAL HEADERS ========================================
#include "totxtfile.h"
#include "savetolocal.h"
#include "readdata.h"
#include "outputhandler.h"
#include "authenticate.h"
#include "validatemail.h"
//+++++++++++++++++++++++++++++++++++++++++ END OF HEADER FILES +++++++++++++++++++++++++++++++++++++++++

// ==================================== DECLARATION OF STRUCTURES ========================================

typedef struct
{
    char phone[10];
    char name[20];
    char address[50];
    char email[30];

}contact_t;

// +++++++++++++++++++++++++++++++++++ END OF DECLARATION OF STRUCTURES +++++++++++++++++++++++++++++++++++

//==================================== DECLARATION OF LOCAL FUNCTIONS ===================================
int readint();
int charint();
char readmain();
char readchar();
int char2int(char);
void handleoption(char);
void listallcontacts();
void printspace(int);
void addnewcontact();
void searchcontact();
void deleteentry();
int toname();
void delete(int);
int tophone();
void editdetails();
void edit(int);
void changephonenumber(int);
void changeemail(int);
void changeaddress(int);
void continous();
//++++++++++++++++++++++++++++++++++++++++ END OF LOCAL FUNCTIONS +++++++++++++++++++++++++++++++++++++++

//=================================== DECLARATION OF DETAILS =============================================

contact_t students[10000];
int TOTAL_STUDENTS=0;
//+++++++++++++++++++++++++++++++++++ END OF DECLARATION OF DETAILS ++++++++++++++++++++++++++++++++++++++

//========================================= MAIN MENU ==============================================================================================================
void UI()
{
    centeredprint("-----------------------------------------------------------------------------------------------------------------\n");
    centeredprint("CONTACT MANAGMENT SYSTEM\n");
    centeredprint("-----------------------------------------------------------------------------------------------------------------\n");

    alignleft("0. QUIT\n");
    alignleft("1. ADD A NEW CONTACT\n");
    alignleft("2. LIST ALL CONTACTS\n");
    alignleft("3. SEARCH FOR CONTACT\n");
    alignleft("4. EDIT DETAILS\n");
    alignleft("5. DELETE A CONTACT\n");
    alignleft("6. EXPORT AS A TXT FILE\n");
    centeredprint("-----------------------------------------------------------------------------------------------------------------\n");
    centeredprint("SELECT AN OPTION[0-6]\n");
    centeredprint("-----------------------------------------------------------------------------------------------------------------\n");

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//?=================================================== DRIVER CODE ==========================================

int main()
{
    system("clear");
    authentication();
    update(students,&TOTAL_STUDENTS);
    while(1)
    {
        UI();

        handleoption(readmain());

    }
    return 0;
}

//?++++++++++++++++++++++++++++++++++++++++++++++++++ END OF DRIVER CODE ++++++++++++++++++++++++++++++++++++++


// ================================================= BASIC FUNCTIONS ==========================================

int readint()
{
    int integerinput;
    scanf("%d",&integerinput);
    return integerinput;
}

char readmain()
{
    char s[4];
    scanf("%s",s);
    return s[0];
}

int char2int(char s)
{
    int num=s-'0';
    return num;
}

char readchar()
{
    char s;
    scanf("%c",&s);
    return s;
}

int charint()
{
    char input;
    scanf("%c",&input);
    int out=input-48;
    return out;
}

void printspace(int n)
{
    for(int i=0;i<n;i++){
        printf(" ");
    }
}

// +++++++++++++++++++++++++++++++++++++++++++ END OF BASIC FUNCTIONS ++++++++++++++++++++++++++++++++++++++++++++++++++


//============================================ HANDLING ALL OPTIONS ====================================================
void handleoption(char option){
    system("clear");
    switch (option)
    {
    case '0':
        endsession(students,TOTAL_STUDENTS);
        exit(0);
    case '1':
        addnewcontact();
        return;
    case '2':
        listallcontacts();
        return;
    case '3':
        searchcontact();
        break;
    case '4':
        editdetails();
        return;
    case '5':
        deleteentry();
        return;
    case '6':
        add2file(students,TOTAL_STUDENTS);
        return;
    default:
        printf("PLEASE ENTER A VALID OPTION!________\n");
        return;
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*
LISTING ALL CONTACTS IN A TALE
*/
void listallcontacts()
{
    printf("LIST OF ALL CONTACTS\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("|   PHONE   ");
    printf("|        NAME       ");
    printf("|                       ADDRESS                   ");
    printf("|              EMAIL          |\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");


    for(int i=0;i<TOTAL_STUDENTS;i++)
    {
        printf("|");
        printf(" %s",students[i].phone);
        int phonelength=10-strlen(students[i].phone);
        printspace(phonelength);

        printf("|");
        printf(" %s",students[i].name);
        int namelength=18-strlen(students[i].name);
        printspace(namelength);

        printf("|");
        printf(" %s",students[i].address);
        int addresslength=48-strlen(students[i].address);
        printspace(addresslength);

        printf("|");
        printf(" %s",students[i].email);
        int emaillength=28-strlen(students[i].email);
        printspace(emaillength);

        printf("|\n");


    }
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("PRESS ANY KEY TO RETURN TO THE MAIN MENU\n");
    char s[4];
    scanf("%s",s);
    system("clear");


    
}
/*
ADDING NEW CONTACTS
*/
void addnewcontact()
{
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("ADD NEW DETAILS\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    
    printf("ENTER YOUR PHONE NUMBER -+94");
    char phonenumber[10];
    scanf("%s",phonenumber);
    strcpy(students[TOTAL_STUDENTS].phone,phonenumber);
    printf("\n");

    printf("ENTER YOUR NAME - ");
    char studentname[20];
    scanf("%s",studentname);
    strcpy(students[TOTAL_STUDENTS].name,studentname);
    printf("\n");

    printf("ENTER YOUR ADDRESS\n");
    char studentaddress[50];
    scanf(" %[^\n]s",studentaddress);
    strcpy(students[TOTAL_STUDENTS].address,studentaddress);
    printf("\n");

    addemail();
    printf("\n");
    TOTAL_STUDENTS+=1;
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("DATA ENTERING SUCCESSFUL\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    continous();
}

void continous()
{
    printf("| ENTER 0 TO RETURN TO THE MAIN MENU| ENTER 1 TO ADD ANOTHER CONTACT |\n");
    char s[4];
    scanf("%s",s);
    system("clear");
    switch (s[0])
    {
        case '0':
            return;
        case '1':
            return addnewcontact();
        default:
            return;
    }
}

void addemail()
{
    printf("ENTER YOUR EMAIL - ");
    char studentemail[30];
    scanf(" %[^\n]s",studentemail);
    if(checkmail(studentemail)){
        strcpy(students[TOTAL_STUDENTS].email,studentemail);
        return;
    }
    printf("\nPLEASE ENTER A VALID EMAIL\n\n");
    return addemail();
}
/*
SEARCH FOR CONTACTS
*/
void searchcontact()
{
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("SEARCH DETAILS\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("| TO SEARCH BY PHONE NUMBER ENTER 0 | TO SEARCH BY NAME ENTER 1 | TO GOBACK TO MAIN MENU ENTER -1 |\n");
    int n=readint();
    switch (n)
    {
        case -1:
            system("clear");
            return;
        case 0:
            int phone=tophone();
            return searchcontact();
        case 1:
            int name=toname();
            return searchcontact();
        default:
            printf("INVALID INPUT\n");
            return searchcontact();
    }

}
/*
DELETE ENTRIES
*/
void deleteentry()
{
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("DELETE AN ENTRY\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("|TO DELETE BY SEARCHING NAME ENTER 0|TO DELETE BY SEARCHING PHONE ENTER 1|TO RETURN TO MAIN MENU ENTER -1|\n");
    int n=readint();
    switch (n)
    {
        case 0:
            int breaking1=toname();
            if(breaking1!=-1){
                return delete(breaking1);
            }
            else{
                return deleteentry();
            }
        case 1:
            int breaking2=tophone();
            if(breaking2!=-1){
                return delete(breaking2);
            }
            else{
                return deleteentry();
            }
        case -1:
            system("clear");
            return;
        default:
            printf("INVALID INPUT\n");
            return deleteentry();
    }


}
//======================================================== FINDS SIMILAR NAME IN THE DATA BASE ========================================
int toname()
{
    char studentname[20];
    printf("ENTER STUDENT NAME - ");
    scanf("%s",studentname);
    printf("\nSEARCHING...\n\n");

    int breaking;
    for(int i=0;i<TOTAL_STUDENTS;i++)
    {
        if(strcmp(studentname,students[i].name)==0)
        {
            printf("STUDENT PHONE -+94%s\n",students[i].phone);
            printf("STUDENT ADDRESS - %s\n",students[i].address);
            printf("STUDENT EMAIL - %s\n",students[i].email);
            printf("\n");
            breaking=i;
            return breaking;

        }
    }
    printf("NO RESULT FOUND.\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    return -1;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*
Deleting selected entry
*/
void delete(int breaking)
{
    printf("|TO CONTINUE ENTER 0|TO RETURN TO DELETE OPTION ENTER 1|\n");
    int option=readint();
    if (option==0){
        for (int i=breaking;i<TOTAL_STUDENTS-1;i++){
            students[i]=students[i+1];
        }
        TOTAL_STUDENTS-=1;
        printf("DATA DELECTION SUCCESSFUL\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");  
        printf("\n");
        return deleteentry();
    }
    else{
        return deleteentry();
    }
}
//============================================ Finds similar phone in the data base ==========================================================
int tophone()
{
    char phonenumber[10];
    printf("ENTER PHONE NUMBER - +94");
    scanf("%s",phonenumber);
    printf("\nSEARCHING...\n\n");

    for(int i=0;i<TOTAL_STUDENTS;i++)
    {
        if(strcmp(phonenumber,students[i].phone)==0)
        {
            printf("STUDENT NAME - %s\n",students[i].name);
            printf("STUDENT ADDRESS - %s\n",students[i].address);
            printf("STUDENT EMAIL - %s\n",students[i].email);
            printf("\n");
            return i;

        }
    }
    printf("NO RESULT FOUND.\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    return -1;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void editdetails()
{
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("CHANGE DETAILS\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("|TO CHANGE DETAILS BY SEARCHING NAME ENTER 0|TO CHANGE DETAILS BY SEARCHING PHONE ENTER 1|TO RETURN TO MAIN MENU ENTER -1|\n");
    int n=readint();
    switch (n)
    {
        case 0:
            int sim1=toname();
            if (sim1!=-1){
                return edit(sim1);
            }
            else{
                return editdetails();
            }
        case 1:
            int sim2=tophone();
            if(sim2!=-1){
                return edit(sim2);
            }
            else{
                return editdetails();
            }
        case -1:
            system("clear");
            return;
        default:
            printf("INVALID INPUT\n");
            return editdetails();
    }
}


void edit(int breaking)
{
    printf("|TO CHANGE PHONE ENTER 0|TO CHANGE ADDRESS ENTER 1|TO CHANGE EMAIL ENTER 2|TO RETURN TO MAIN MENU ENTER -1|\n");
    int n=readint();
    switch (n)
    {
        case 0:
            return changephonenumber(breaking);
        case 1:
            return changeaddress(breaking);
        case 2:
            return changeemail(breaking);
        case -1:
            system("clear");
            return;
        default:
            printf("INVALID INPUT\n");
            return edit(breaking);
    }
}

void changephonenumber(int breaking)
{
    printf("PREVIOUS PHONE - +94%s\n",students[breaking].phone);
    printf("ENTER NEW PHONE - +94");
    char phone[10];
    scanf("%s",phone);
    strcpy(students[breaking].phone,phone);
    printf("\nPHONE CHANGED SUCCESSFULLY\n");
    return edit(breaking);
}

void changeaddress(int breaking)
{
    printf("PREVIOUS ADDRESS - %s\n",students[breaking].address);
    printf("NEW ADDRESS - \n");
    char address[50];
    scanf(" %[^\n]s",address);
    strcpy(students[breaking].address,address);
    printf("\nADDRESS CHANGED SUCCESSFULLY\n");
    return edit(breaking);
}

void changeemail(int breaking)
{
    printf("PREVIOUS EMAIL - %s\n",students[breaking].email);
    printf("NEW EMAIL -");
    char email[30];
    scanf(" %[^\n]s",email);
    if (checkmail(email))
    {
        strcpy(students[breaking].email,email);
        printf("\nEMAIL CHANGED SUCCESSFULLY\n");
        return edit(breaking);

    }
    printf("\nPLEASE ENTER A VALID EMAIL\n\n");
    return changeemail(breaking);
}