#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *filename = "C:/Users/gabriel/CLionProjects/myplace/input4.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // reading line by line, max XXX bytes
    const unsigned MAX_LENGTH = 100;
    char buffer[MAX_LENGTH];

    int counter = 0;
    int intervals[5];

    while (fgets(buffer, MAX_LENGTH, fp)) {
        int i = 0;

        while (buffer[i] != '\n') {
            if (buffer[i] == '-' || buffer[i] == ',') buffer[i] = '/';

            i++;
        }

        char *array[10];

        i = 0;

        array[i] = strtok(buffer, "/");

        while(array[i] != NULL) {
            array[++i] = strtok(NULL, "/");
        }

        for (int j = 0; j < 4; j++) {
            intervals[j] = (int) strtol(array[j], (char **) NULL, 10);
            printf("%d ", intervals[j]);
        }
        printf("\n");

        if (intervals[0] <= intervals[2] && intervals[1] >= intervals[3] ||
            intervals[0] >= intervals[2] && intervals[1] <= intervals[3]) {
            counter++;
            continue;
        }

        int hasIntersection;
        if (intervals[2] > intervals[1] || intervals[0] > intervals[3]) hasIntersection = 0;
        else hasIntersection = 1;

        if (hasIntersection) counter++;
    }

    printf("Counter = %d\n", counter);
    return 0;
}