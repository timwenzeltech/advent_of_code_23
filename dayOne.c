/*
Day 1: Trebuchet?!
The newly-improved calibration document consists of lines of text; each str originally contained a specific calibration value that the
Elves now need to recover. On each str, the calibration value can be found by combining the first digit and the last digit
(in that order) to form a single two-digit number.

For example:

1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.

Consider your entire calibration document. What is the sum of all of the calibration values?
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    const int MAX_LEN = 50;
    FILE *file;
    char str[MAX_LEN];

    file = fopen("input.txt", "r");
    if(file==NULL){
        perror("Can't open file");
        return 1;
    }
    int sum = 0;
    while (fgets(str, sizeof(str), file) != NULL) {
        int firstInt = 0, lastInt = 0;
        char integer[MAX_LEN];
        int count = -1;

        for(int i = 0; str[i] != '\0'; i++){
            if(isdigit(str[i])){
                count++;
                integer[count] = str[i];
            }
        }
        printf("%s \n", integer);
        //Now we have a string full of integers named integer[]
        //Catch the possiblity of there only being one int 
        if(integer[0] != '\0'){
            firstInt = integer[0];
        }else if(integer[1] != '\0'){
            for(int i = 0; integer[i] != '\0'; i++){
                lastInt = integer[i];
            }
        }else{
            lastInt = 0;
        }
        sum = sum + firstInt + lastInt;
        
    }
    printf("Sum of all ints is: %d\n", sum);
       fclose(file);
    return 0;
}

