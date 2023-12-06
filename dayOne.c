#include <stdio.h>
#include <ctype.h>
#include <string.h>

int checkForIntStrings(char *line){
    char *numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int values[] = {1,2,3,4,5,6,7,8,9};

    for(int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++){
        if(strcmp(line, numbers[i]) == 0){
            return values[i];
        }
    }
    return -1;
}

int getFirstInt(char *str){
    int firstInt = -1;
    char substring[50];
    int index = 0;

    for(int i = 0; str[i] != '\0'; i++){
        if(isdigit(str[i])){
            firstInt = str[i] - '0';
            break; //Terminate so firstInt doesnt get overwritten
        }else{
            
        }
    }
    return firstInt;
}

int getLastInt(char *str){
    int lastInt = -1;
    char substring[50];
    int index = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(isdigit(str[i])){
            lastInt = str[i] - '0';
        }else{
            
        }
    }
    return lastInt;
}

int main(){
    //Declares Variables for file, str(which will represent a line in the file) and sum(sum of all values)
    FILE *file;
    char str[100]; // String Array, which will represent the strings of every line
    int sum = 0; // Sum of first int*10 and last Int 

    //Opens File, checks for null
    file = fopen("input.txt", "r");
    if(file==NULL){
        perror("Can't open file");
        return 1;
    }
    //Iterates line by line through file:
    while (fgets(str, sizeof(str), file) != NULL) {

        int firstInt = getFirstInt(str); 
        int lastInt = getLastInt(str);

        if(firstInt != -1){
            printf("First Number Found is: %d" , firstInt);
        }else{
            firstInt = 0;
        }
        if(lastInt != -1){
            printf(" last Number Found is: %d\n", lastInt);
        }else{
            lastInt = 0;
        }
        sum = sum + firstInt*10 + lastInt;
    }
    printf("Sum of all the calibration values is: %d\n", sum);
    fclose(file);
    return 0;
}
