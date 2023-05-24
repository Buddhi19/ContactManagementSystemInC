#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


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
    char* users[2]={"buddhi","admin"};
    char* passwords[2]={"admin","buddhi"};
    printf("USERNAME - ");
    char username[10];
    scanf("%s",username);
    printf("PASSWORD - ");
    char password[10];
    scanf("%s",password);

    for (int i=0;i<2;i++){
        if(strcmp(users[i],username)==0){
            if(strcmp(passwords[i],password)==0){
                printf("\n");
                system("clear");
                return;
            }
        }
    }
    system("clear");
    tag();
    printf("\nWRONG USERNAME PASSWORD COMBINATION PLEASE TRY AGAIN\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    return flow();

}

void authentication()
{
    tag();
    flow();
}