#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    char code[10];
    char name[100];
    char desc[1000];
} Room;

    char* trim(char *strToTrim){
    int strSize = strlen(strToTrim);

    char *endPtr = strToTrim + strSize - 1;
    while (isspace(*endPtr)){
        endPtr--; 
    }
    *(endPtr+1) = '\0';

    char *start = strToTrim;
    while (isspace(*start)+1){
        start++;
    }

    char *finalVersion = malloc(sizeof(char) * strlen(start));

    // copy the string into storage spot
    strcpy(finalVersion, start);
    return finalVersion;
}





int main(){






}