#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

char* users[5]={"buddhi","admin"};
char* passwords[5]={"admin","buddhi"};
int USERS=2;

void delay(int number_of_seconds) {
    int milli_seconds = CLOCKS_PER_SEC * number_of_seconds;
  
    clock_t start_time = clock();
  
    while (clock() < start_time + milli_seconds) {}
}

void tag()
{
    centeredprint("-----------------------------------------------------------------------------------------------------------------\n");
    centeredprint("WELCOME TO CONTACT MANAGMENT SYSTEM\n");
    centeredprint("-----------------------------------------------------------------------------------------------------------------\n");
    centeredprint("PLEASE LOGIN\n");
    centeredprint("------------------------------------------------------------------\n");

}

void flow()
{
    alignleft("USERNAME - ");
    char username[10];
    scanf("%s",username);
    alignleft("PASSWORD - ");
    char password[10];
    scanf("%s",password);

    for (int i=0;i<2;i++){
        if(strcmp(users[i],username)==0){
            if(strcmp(passwords[i],password)==0){
                alignleft("  WELCOME ");
                printf("%s\n",users[i]);
                centeredprint("------------------------------------------------------------------\n");
                delay(2);
                system("clear");
                return;
            }
        }
    }
    system("clear");
    tag();
    centeredprint("WRONG USERNAME PASSWORD COMBINATION PLEASE TRY AGAIN\n");
    return flow();

}

void authentication()
{
    tag();
    flow();
}

void adduser()
{
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("ADD NEW USER\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");

    printf("USERNAME - ");
    char username[30];
    scanf("%s",username);
    printf("PASSWORD - ");
    char password[20];
    scanf("%s",password);
    
    users[USERS]=username;
    passwords[USERS]=password;
    USERS++;
    printf("NEW USER ADDED\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    delay(3);
    system("clear");
    
}