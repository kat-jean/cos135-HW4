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





int main(int argc, char *argv[]){

    FILE *fp = fopen(argv[1], "r");
        
    int capacity = 5;
    int count = 0;

    Room *rooms = malloc(capacity * sizeof(Room));
    
    

    /* Stuff done in class, incorperate later or remove
    char sep[] = ":";

    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), fp)){
        char *tp = strtok(buffer, sep);
        printf("|%s|\n", tp);
    }
    */




}