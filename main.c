//=========================================== HEADER FILES ==============================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>
#include <ctype.h>

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
char readchar();
int char2int(char);
void handleoption(int);
void invalidoption();
void listallcontacts();
void printspace(int);
void addnewcontact();
void searchcontact();
void serachbyphone();
void searchbyname();
void deleteentry();
void deletebyname();
void delete(int);
void deletebyphone();
//++++++++++++++++++++++++++++++++++++++++ END OF LOCAL FUNCTIONS +++++++++++++++++++++++++++++++++++++++

//=================================== DECLARATION OF DETAILS =============================================

contact_t students[100];
int TOTAL_STUDENTS=0;
//+++++++++++++++++++++++++++++++++++ END OF DECLARATION OF DETAILS ++++++++++++++++++++++++++++++++++++++


void UI()
{
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("CONTACT MANAGMENT SYSTEM\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");

    printf("0. QUIT\n1. ADD A NEW CONTACT\n2. LIST ALL CONTACTS\n3. SEARCH FOR CONTACT\n4. DELETE A CONTACT\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("SELECT AN OPTION[0-4]\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");

}

//=================================================== DRIVER CODE ==========================================

int main()
{
    while(1)
    {
        UI();
        handleoption(readint());
    }
    return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++ END OF DRIVER CODE ++++++++++++++++++++++++++++++++++++++


// ================================================= BASIC FUNCTIONS ==========================================

int readint()
{
    int integerinput;
    scanf("%d",&integerinput);
    return integerinput;
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

void printspace(int n)
{
    for(int i=0;i<n;i++){
        printf(" ");
    }
}
// +++++++++++++++++++++++++++++++++++++++++++ END OF BASIC FUNCTIONS ++++++++++++++++++++++++++++++++++++++++++++++++++

void handleoption(int option){
    switch (option)
    {
    case 0:
        printf("END OF THE SESSION\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        exit(0);
    case 1:
        addnewcontact();
        return;
    case 2:
        listallcontacts();
        return;
    case 3:
        searchcontact();
        break;
    case 4:
        deleteentry();
        return;
    default:
        return invalidoption();
    }
}

void invalidoption()
{
    printf("PLEASE ENTER A VALID OPTION\n");
    int s=readint();
    handleoption(s);
}

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


    
}

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

    printf("ENTER YOUR EMAIL - ");
    char studentemail[30];
    scanf("%s",studentemail);
    strcpy(students[TOTAL_STUDENTS].email,studentemail);
    printf("\n");
    TOTAL_STUDENTS+=1;
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("DATA ENTERING SUCCESSFUL\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}

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
            return;
        case 0:
            serachbyphone();
            return;
        case 1:
            searchbyname();
            return;
        default:
            printf("INVALID INPUT\n");
            return searchcontact();
    }

}

void serachbyphone()
{
    char phonenumber[10];
    printf("ENTER PHONE NUMBER - +94");
    scanf("%s",phonenumber);
    printf("\nSEARCHING...\n");

    for(int i=0;i<TOTAL_STUDENTS;i++)
    {
        if(strcmp(phonenumber,students[i].phone)==0)
        {
            printf("STUDENT NAME - %s\n",students[i].name);
            printf("STUDENT ADDRESS - %s\n",students[i].address);
            printf("STUDENT EMAIL - %s\n",students[i].email);
            return searchcontact();

        }
    }
    printf("NO RESULT FOUND.\n");
    return searchcontact();

}

void searchbyname()
{
    char studentname[20];
    printf("ENTER STUDENT NAME - ");
    scanf("%s",studentname);
    printf("\nSEARCHING...\n\n");

    for(int i=0;i<TOTAL_STUDENTS;i++)
    {
        if(strcmp(studentname,students[i].name)==0)
        {
            printf("STUDENT PHONE -+94%s\n",students[i].phone);
            printf("STUDENT ADDRESS - %s\n",students[i].address);
            printf("STUDENT EMAIL - %s\n",students[i].email);
            printf("\n");
            return searchcontact();

        }
    }
    printf("NO RESULT FOUND.\n");
    return searchcontact();
}

void deleteentry()
{
    printf("|TO DELETE BY SEARCHING NAME ENTER 0|TO DELETE BY SEARCHING PHONE ENTER 1|TO RETURN TO MAIN MENU ENTER -1|\n");
    int n=readint();
    switch (n)
    {
        case 0:
            return deletebyname();
        case 1:
            return deletebyphone();
        case -1:
            return;
        default:
            printf("INVALID INPUT\n");
            return deleteentry();
    }


}

void deletebyname()
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
            return delete(breaking);

        }
    }
    printf("NO RESULT FOUND.\n");
    return deleteentry();
}

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
        printf("\n");
        return;
    }
    else{
        return deleteentry();
    }
}

void deletebyphone()
{
    char phonenumber[10];
    printf("ENTER PHONE NUMBER - +94");
    scanf("%s",phonenumber);
    printf("\nSEARCHING...\n");

    for(int i=0;i<TOTAL_STUDENTS;i++)
    {
        if(strcmp(phonenumber,students[i].phone)==0)
        {
            printf("STUDENT NAME - %s\n",students[i].name);
            printf("STUDENT ADDRESS - %s\n",students[i].address);
            printf("STUDENT EMAIL - %s\n",students[i].email);
            return delete(i);

        }
    }
    printf("NO RESULT FOUND.\n");
    return deleteentry();
}