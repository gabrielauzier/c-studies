#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getDuplicatedValue(const char *string01, const char *string02, int mid);
int getPriorityValue(char item);

int analyzeStringFirstHalfProblem(char *string) {

    char firstHalfString[100], secondHalfString[100];
    int length = (int) strlen(string);
    int mid = length / 2, i, j;

    for(i = 0; i < mid; i++) {
        firstHalfString[i] = string[i];
    }

    for(i = mid, j = 0; i <= length; i++, j++) {
        secondHalfString[j] = string[i];
    }

    char item = getDuplicatedValue(firstHalfString, secondHalfString, mid);
    int priority = getPriorityValue(item);

    return priority;
}

char getDuplicatedValue(const char *string01, const char *string02, int mid) {
    int i, j;

    for(i = 0; i < mid; i++) {
        for(j = 0; j < mid; j++) {
            if (string01[i] == string02[j])
                return string01[i];
        }
    }

    return 'X';
}

int getPriorityValue(char item) {
    switch (item) {
        case 'a': return 1;
        case 'b': return 2;
        case 'c': return 3;
        case 'd': return 4;
        case 'e': return 5;
        case 'f': return 6;
        case 'g': return 7;
        case 'h': return 8;
        case 'i': return 9;
        case 'j': return 10;
        case 'k': return 11;
        case 'l': return 12;
        case 'm': return 13;
        case 'n': return 14;
        case 'o': return 15;
        case 'p': return 16;
        case 'q': return 17;
        case 'r': return 18;
        case 's': return 19;
        case 't': return 20;
        case 'u': return 21;
        case 'v': return 22;
        case 'w': return 23;
        case 'x': return 24;
        case 'y': return 25;
        case 'z': return 26;
        case 'A': return 27;
        case 'B': return 28;
        case 'C': return 29;
        case 'D': return 30;
        case 'E': return 31;
        case 'F': return 32;
        case 'G': return 33;
        case 'H': return 34;
        case 'I': return 35;
        case 'J': return 36;
        case 'K': return 37;
        case 'L': return 38;
        case 'M': return 39;
        case 'N': return 40;
        case 'O': return 41;
        case 'P': return 42;
        case 'Q': return 43;
        case 'R': return 44;
        case 'S': return 45;
        case 'T': return 46;
        case 'U': return 47;
        case 'V': return 48;
        case 'W': return 49;
        case 'X': return 50;
        case 'Y': return 51;
        case 'Z': return 52;
        default: return 0;
    }
}

char * getValuesInCommon(char *string01, char *string02) {
    static char values[10];
    int i, j, counter = 0;

    for(i = 0; i < strlen(string01); i++) {
        for(j = 0; j < strlen(string02); j++) {
            if (string01[i] == string02[j]) {
                values[counter] = string01[i];
                counter++;
            }
        }
    }

    return values;
}

int findGroupBadge(char *str01, char *str02, char *str03) {
    char values[10], *p = getValuesInCommon(str01, str02);

    /* assign values as a string */
    int i = 0;
    while (*p != '\0') {
        values[i] = *(p + i);
        i++;
    }

    printf("Values in common: %s\n", values);
    return 1;
}

int main() {
    char *filename = "C:/Users/gabriel/CLionProjects/myplace/input3.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // reading line by line, max XXX bytes
    const unsigned MAX_LENGTH = 100;
    char buffer[MAX_LENGTH];

    int value = 0;
    int countGroup = 0;
    char str01[50], str02[50], str03[50];

    while (fgets(buffer, MAX_LENGTH, fp)) {
        countGroup++;

        if (countGroup == 1) {
            strcpy(str01, buffer);
            continue;
        }
        else if (countGroup == 2) {
            strcpy(str02, buffer);
            continue;
        }
        else if (countGroup == 3) {
            strcpy(str03, buffer);
            int sla = findGroupBadge(str01, str02, str03);

            printf("Group \n");
//            printf("%s\n", str01);
//            printf("%s\n", str02);
//            printf("%s\n", str03);
            countGroup = 0;
        }
    }

    return 0;
}