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
    const int MAX_LEN = 100;
    FILE *file;
    char str[MAX_LEN];
    int sum = 0;

    file = fopen("input.txt", "r");
    if(file==NULL){
        perror("Can't open file");
        return 1;
    }

    while (fgets(str, sizeof(str), file) != NULL) {
        int firstInt = 0, lastInt = 0;
        int count = -1;

        for(int i = 0; str[i] != '\0'; i++){
            if(isdigit(str[i])){
                count++;
                if(count == 0){
                    firstInt = str[i] - '0';
                }else if(count > 0){
                    lastInt = str[i] - '0';
                }
            }
        }

        if(lastInt == 0){lastInt = firstInt;}
        printf("firstInt: %d. lastInt: %d\n", firstInt, lastInt);
        sum = sum + firstInt*10 + lastInt;
    }
    printf("Sum of all the calibration values is: %d\n", sum);
    fclose(file);
    return 0;
}

