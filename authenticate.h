#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void authentication()
{
    char* users[2]={"buddhi","admin"};
    char* passwords[2]={"admin","buddhi"};

    printf("WELCOME TO CONTACT MANAGMENT SYSTEM PLEASE LOGIN\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("USERNAME - ");
    char username[10];
    scanf("%s",username);
    printf("\nPASSWORD - ");
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
    printf("\nWRONG USERNAME PASSWORD COMBINATION PLEASE TRY AGAIN\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    return authentication();

}
