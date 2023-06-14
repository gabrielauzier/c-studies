#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readFile() {
    char *filename = "C:/Users/gabriel/CLionProjects/myplace/inputs/input5.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // reading line by line, max XXX bytes
    const unsigned MAX_LENGTH = 100;
    char buffer[MAX_LENGTH];

    while (fgets(buffer, MAX_LENGTH, fp)) {

    }

    return 0;
}