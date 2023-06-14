#include <stdio.h>
#include <stdlib.h>

int main() {
    char *filename = "C:/Users/gabriel/CLionProjects/myplace/input1.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // reading line by line, max 10 bytes
    const unsigned MAX_LENGTH = 10;
    char buffer[MAX_LENGTH];

    int counter = 0;
    int calories = 0;
    int greaterCalories = 0;



    while (fgets(buffer, MAX_LENGTH, fp)) {
        if (buffer[0] == '\n') {

            if (calories > greaterCalories && calories < 66306)
                greaterCalories = calories;

            counter = 0;
            calories = 0;

//            printf("empty bro ----------\n");
            continue;
        }

        int i = atoi(buffer);
        calories += i;
        counter++;

//        printf("%s", buffer);
    }

    // close the file
    fclose(fp);

    printf("%d", greaterCalories);
    return 0;
}