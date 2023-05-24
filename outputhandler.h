#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void centeredprint(char name[])
{
    printf("%*s", 80+strlen(name)/2, name, 80-strlen(name)/2, "");
}