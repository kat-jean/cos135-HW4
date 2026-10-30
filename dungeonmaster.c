#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
    char code[10];
    char name[1000];
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
    while (isspace(*start)){
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
    
    char sep[] = ":";
    char buffer[5000];

    // read the file line by line using strtok...

    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        if (buffer[0] == '\n'){
            continue;
        }
        char buffer_copy[5000];
        strcpy(buffer_copy, buffer);

        char *key = strtok(buffer_copy, sep);
        char *value = strtok(NULL, sep);

        if (key != NULL && value != NULL){
            char *cleaned_value = trim(value);
        

            if (strcmp(key, "Room Name") == 0){
                if (count >= capacity){
                    capacity *= 2;
                    Room *temp = realloc(rooms, capacity * sizeof(Room));
                rooms = temp;
                }
            strncpy(rooms[count].name, cleaned_value, sizeof(rooms[count].name) - 1);
            rooms[count].name[sizeof(rooms[count].name) - 1] = '\0';
            }
            else if (strcmp(key, "Room Code") == 0) {
                strncpy(rooms[count].code, cleaned_value, sizeof(rooms[count].code) - 1);
                rooms[count].code[sizeof(rooms[count].code) - 1] = '\0';
            }
            else if (strcmp(key, "Room Description") == 0) {
                strncpy(rooms[count].desc, cleaned_value, sizeof(rooms[count].desc) - 1);
                rooms[count].desc[sizeof(rooms[count].desc) - 1] = '\0';
                count++;
        }
        free(cleaned_value);
    }
}

    fclose(fp);

    for (int i = 0; i < count; i++) {
        printf("Room %s: %s\n", rooms[i].code, rooms[i].name);
    }

    free(rooms);
    return 0;
}
