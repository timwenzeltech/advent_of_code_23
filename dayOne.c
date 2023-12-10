#include <ctype.h>
#include <stdio.h>
#include <string.h>

int getFirstInt(char *str) {
  int firstInt = -1;
  char substring[50];
  int index = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    if (isdigit(str[i])) {
      return str[i] - '0';
    } else { // If there is no digit, iterate further through the string to find
             // a digit represented as a word like "one" and then return
             // firstInt as that digit
      if (str[i] == 'o' && str[i + 1] == 'n' && str[i + 2] == 'e') {
        return 1;
      } else if (str[i] == 't' && str[i + 1] == 'w' && str[i + 2] == 'o') {
        return 2;
      } else if (str[i] == 't' && str[i + 1] == 'h' && str[i + 2] == 'r' &&
                 str[i + 3] == 'e' && str[i + 4] == 'e') {
        return 3;
      } else if (str[i] == 'f' && str[i + 1] == 'o' && str[i + 2] == 'u' &&
                 str[i + 3] == 'r') {
        return 4;
      } else if (str[i] == 'f' && str[i + 1] == 'i' && str[i + 2] == 'v' &&
                 str[i + 3] == 'e') {
        return 5;
      } else if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'x') {
        return 6;
      } else if (str[i] == 's' && str[i + 1] == 'e' && str[i + 2] == 'v' &&
                 str[i + 3] == 'e' && str[i + 4] == 'n') {
        return 7;
      } else if (str[i] == 'e' && str[i + 1] == 'i' && str[i + 2] == 'g' &&
                 str[i + 3] == 'h' && str[i + 4] == 't') {
        return 8;
      } else if (str[i] == 'n' && str[i + 1] == 'i' && str[i + 2] == 'n' &&
                 str[i + 3] == 'e') {
        return 9;
      }
    }
  }
  // No integers between 1 and 9 found, therfore return -1:
  return -1;
}

int getLastInt(char *str) {
  int lastInt = -1;
  char substring[50];
  int index = 0;

  for (int i = 0; str[i] != '\0'; i++) {
    if (isdigit(str[i])) {
      lastInt = str[i] - '0';
    } else { // If there is no digit, iterate further through the string to find
             // a digit represented as a word like "one" and then return
             // firstInt as that digit
      if (str[i] == 'o' && str[i + 1] == 'n' && str[i + 2] == 'e') {
        lastInt = 1;
      } else if (str[i] == 't' && str[i + 1] == 'w' && str[i + 2] == 'o') {
        lastInt = 2;
      } else if (str[i] == 't' && str[i + 1] == 'h' && str[i + 2] == 'r' &&
                 str[i + 3] == 'e' && str[i + 4] == 'e') {
        lastInt = 3;
      } else if (str[i] == 'f' && str[i + 1] == 'o' && str[i + 2] == 'u' &&
                 str[i + 3] == 'r') {
        lastInt = 4;
      } else if (str[i] == 'f' && str[i + 1] == 'i' && str[i + 2] == 'v' &&
                 str[i + 3] == 'e') {
        lastInt = 5;
      } else if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'x') {
        lastInt = 6;
      } else if (str[i] == 's' && str[i + 1] == 'e' && str[i + 2] == 'v' &&
                 str[i + 3] == 'e' && str[i + 4] == 'n') {
        lastInt = 7;
      } else if (str[i] == 'e' && str[i + 1] == 'i' && str[i + 2] == 'g' &&
                 str[i + 3] == 'h' && str[i + 4] == 't') {
        lastInt = 8;
      } else if (str[i] == 'n' && str[i + 1] == 'i' && str[i + 2] == 'n' &&
                 str[i + 3] == 'e') {
        lastInt = 9;
      }
    }
  }
  // No integers between 1 and 9 found, therfore return -1:
  return lastInt;
}

int main() {
  // Declares Variables for file, str(which will represent a line in the file)
  // and sum(sum of all values)
  FILE *file;
  char str[100]; // String Array, which will represent the strings of every
                 // line
  int sum = 0;   // Sum of first int*10 and last Int

  // Opens File, checks for null
  file = fopen("input.txt", "r");
  if (file == NULL) {
    perror("Can't open file");
    return 1;
  }
  // Iterates line by line through file:
  while (fgets(str, sizeof(str), file) != NULL) {
    int firstInt = getFirstInt(str);
    int lastInt = getLastInt(str);

    if (firstInt != -1) {
      printf("First Number Found is: %d", firstInt);
    } else {
      firstInt = 0;
    }
    if (lastInt != -1) {
      printf(" last Number Found is: %d\n", lastInt);
    } else {
      lastInt = 0;
    }
    sum = sum + firstInt * 10 + lastInt;
  }
  printf("Sum of all the calibration values is: %d\n", sum);
  fclose(file);
  return 0;
}
