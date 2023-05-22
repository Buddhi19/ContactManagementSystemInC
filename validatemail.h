#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdbool.h>


bool checkmail(char* email)
{
    int len=strlen(email);
    int check=0;
    for(int i=0;i<len;i++){
        if(email[i]=='@'){
            check=1;
        }
        if(email[i]==' '){
            return false;
        }
    }
    if (check==1){
        return true;
    }
    return false;
}