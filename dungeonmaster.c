#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// define the Room struct to hold dungeon room data
typedef struct{
    char code[10];
    char name[1000];
    char desc[1000];
} Room;

    // function from class... removes excess whitespace from a string
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

    // open the file passed in the command line argument in read mode
    FILE *fp = fopen(argv[1], "r");
    
    // set up variables for an array of Room structs
    int capacity = 5;
    int count = 0;

    // allocate the initial memory for 5 rooms
    Room *rooms = malloc(capacity * sizeof(Room));
    
    char sep[] = ":";
    char buffer[5000];

    // read the file line by line using strtok...

    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        // skip empty lines in the file
        if (buffer[0] == '\n'){
            continue;
        }
        // create a copy of the line because strtok modifies strings in-place
        char buffer_copy[5000];
        strcpy(buffer_copy, buffer);

        // split the line into a key and value ("room name" & it's actual name)
        char *key = strtok(buffer_copy, sep);
        char *value = strtok(NULL, sep);

        // check if both the key and value were found and clean the extra whitespace
        if (key != NULL && value != NULL){
            char *cleaned_value = trim(value);
        
            // if the key is "Room Name", store it in the current room slot ... 
            // and resize the array if the current capacity limit is reached
            if (strcmp(key, "Room Name") == 0){
                if (count >= capacity){
                    capacity *= 2;
                    Room *temp = realloc(rooms, capacity * sizeof(Room));
                rooms = temp;
                }
            strncpy(rooms[count].name, cleaned_value, sizeof(rooms[count].name) - 1);
            rooms[count].name[sizeof(rooms[count].name) - 1] = '\0';
            }
            // if the key is "Room Code", store it in the current room slot ...
            else if (strcmp(key, "Room Code") == 0) {
                strncpy(rooms[count].code, cleaned_value, sizeof(rooms[count].code) - 1);
                rooms[count].code[sizeof(rooms[count].code) - 1] = '\0';
            }
            // if the key is "Room Description", store it and increment room count
            else if (strcmp(key, "Room Description") == 0) {
                strncpy(rooms[count].desc, cleaned_value, sizeof(rooms[count].desc) - 1);
                rooms[count].desc[sizeof(rooms[count].desc) - 1] = '\0';
                count++;
        }
        // free the memory dynamically allocated by the trim function
        free(cleaned_value);
    }
}
    // close the file stream once all lines have been processed
    fclose(fp);

    // loop through the stored rooms and print out their codes and names
    for (int i = 0; i < count; i++) {
        printf("Room %s: %s\n", rooms[i].code, rooms[i].name);
    }

    // free the dynamically allocated memory for the rooms array
    free(rooms);
    return 0;
}
