#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void centeredprint(char name[])
{
    printf("%*s", 80+strlen(name)/2, name, 80-strlen(name)/2, "");
}

void alignleft(char name[])
{
    for(int i=0;i<70;i++){
        printf(" ");
    }
    printf("%s",name);
}