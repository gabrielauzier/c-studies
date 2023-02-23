#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Scores:
    1 - Rock
    2 - Paper
    3 - Scissors

    Plus the outcomes:
    0 - lost
    3 - draw
    6 - won

    Choices:
    A or X - rock
    B or Y - paper
    C or Z - scissors
 */

int getGameResultFirstHalf(char opponentChoice, char myChoice) {

    int score = 0;

    switch(opponentChoice) {
        case 'A': opponentChoice = 'R'; break;
        case 'B': opponentChoice = 'P'; break;
        case 'C': opponentChoice = 'S'; break;
        default: break;
    }

    switch (myChoice) {
        case 'X': myChoice = 'R'; score += 1; break;
        case 'Y': myChoice = 'P'; score += 2; break;
        case 'Z': myChoice = 'S'; score += 3; break;
        default: break;
    }

    /* draw */
    if (opponentChoice == myChoice) score += 3;

        /* i win */
    else if (opponentChoice == 'S' && myChoice == 'R') score += 6;
    else if (opponentChoice == 'P' && myChoice == 'S') score += 6;
    else if (opponentChoice == 'R' && myChoice == 'P') score += 6;

    return score;
}

int getGameResultSecondHalf(char opponentChoice, char myChoice) {

    int score = 0;

    switch (myChoice) {
        case 'X': score += 0; break;
        case 'Y': score += 3; break;
        case 'Z': score += 6; break;
        default: break;
    }

    switch(opponentChoice) {
        case 'A': opponentChoice = 'R'; break;
        case 'B': opponentChoice = 'P'; break;
        case 'C': opponentChoice = 'S'; break;
        default: break;
    }

    if (opponentChoice == 'R') {
        if (myChoice == 'X') score += 3;
        else if (myChoice == 'Y') score += 1;
        else if (myChoice == 'Z') score += 2;
    }
    else if (opponentChoice == 'P') {
        if (myChoice == 'X') score += 1;
        else if (myChoice == 'Y') score += 2;
        else if (myChoice == 'Z') score += 3;
    }
    else if (opponentChoice == 'S') {
        if (myChoice == 'X') score += 2;
        else if (myChoice == 'Y') score += 3;
        else if (myChoice == 'Z') score += 1;
    }

    return score;
}

int main() {
    char *filename = "C:/Users/gabriel/CLionProjects/myplace/input2.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // reading line by line, max 10 bytes
    const unsigned MAX_LENGTH = 10;
    char buffer[MAX_LENGTH];

    int score = 0;

    while (fgets(buffer, MAX_LENGTH, fp)) {
        if (buffer[0] == '\n') {
            continue;
        }


        char opponentChoice = (char) buffer[0];
        char myChoice = (char) buffer[2];

        score += getGameResultSecondHalf(opponentChoice, myChoice);
    }

    printf("Total score: %d\n", score);
    fclose(fp);

    return 0;
}