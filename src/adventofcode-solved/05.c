#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define STACK_SIZE 100
#define TRUE 1

typedef struct {
    char *mem;
    size_t size;
    int top;
} Stack;

/*

Initial stacks (input)

[T]     [D]         [L]
[R]     [S] [G]     [P]         [H]
[G]     [H] [W]     [R] [L]     [P]
[W]     [G] [F] [H] [S] [M]     [L]
[Q]     [V] [B] [J] [H] [N] [R] [N]
[M] [R] [R] [P] [M] [T] [H] [Q] [C]
[F] [F] [Z] [H] [S] [Z] [T] [D] [S]
[P] [H] [P] [Q] [P] [M] [P] [F] [D]
 1   2   3   4   5   6   7   8   9

*/

Stack *stack_create(char *mem, size_t size);
void stack_push(Stack *stack, char c);
char stack_pop(Stack *stack);
char stack_peek(Stack const *stack);
void stack_print(Stack *stack);
void stack_initialize(Stack *stack, char *str);

void moveFromTo(Stack *stack_origin, Stack *stack_dest);
void move(int move_times, Stack *stack_origin, Stack *stack_dest);

int main() {
    char stacks_mem[10][STACK_SIZE];
    Stack *stacks[10];

    const int stacks_num = 9;

    for (int i = 0; i < stacks_num; i++) {
        stacks[i] = stack_create(stacks_mem[i], STACK_SIZE);
    }

    /* process */
    printf("\nMove starting\n");

    stack_initialize(stacks[0], "PFMQWGRT");
    stack_initialize(stacks[1], "HFR");
    stack_initialize(stacks[2], "PZRVGHSD");
    stack_initialize(stacks[3], "QHPBFWG");
    stack_initialize(stacks[4], "PSMJH");
    stack_initialize(stacks[5], "MZTHSRPL");
    stack_initialize(stacks[6], "PTHNML");
    stack_initialize(stacks[7], "FDQR");
    stack_initialize(stacks[8], "DSCNLPH");

    /* read file */
    char *filename = "C:/Users/gabriel/CLionProjects/myplace/input5.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // reading line by line, max XXX bytes
    const int MAX_LENGTH = 100;
    char buffer[MAX_LENGTH];

    int counter = 0;

    while (fgets(buffer, MAX_LENGTH, fp)) {

        int moves, from, to;
        char *array[4];
        int i = 0;

        array[i] = strtok(buffer, " ");

        while(array[i] != NULL) {
            array[++i] = strtok(NULL, " ");
        }

        moves = (int) strtol(array[0], (char **) NULL, 10);
        from = (int) strtol(array[1], (char **) NULL, 10);
        to = (int) strtol(array[2], (char **) NULL, 10);

        move(moves, stacks[--from], stacks[--to]);
        counter++;
    }

    printf("Move [%d]\n", counter);
    for (int j = 0; j < stacks_num; j++) {
        printf("[%d] ", j);
        stack_print(stacks[j]);
    }

    /* stacks afterwards */

    return EXIT_SUCCESS;
}

Stack *stack_create(char *mem, size_t size) {
    assert(mem && size);

    Stack *output = malloc(sizeof(Stack));

    output->mem = mem;
    output->size = size;
    output->top = -1;
    return output;
}

void stack_initialize(Stack *stack, char *str) {
    for (int i = 0; i < strlen(str); i++) {
        stack_push(stack, str[i]);
    }
}

void stack_push(Stack *stack, char c){
    assert(stack);

    if(c < 0) {
        return;
    }

    if((stack->top + 1) < stack->size) {
        stack->mem[stack->top + 1] = c;
        stack->top++;
    }
}

void stack_print(Stack *stack) {
    assert(stack);

//    if(!stack->top) {
//        printf("Nothing on stack to print. \n");
//        return;
//    }

    printf("Entire stack: ");
    int i;

    for(i = 0; i <= stack->top; i++) {
        printf("[%c] ", stack->mem[i]);
    }

    printf("\n");
}

char stack_pop(Stack *stack) {
    assert(stack);

    if(stack-> top < 0) {
        fprintf(stderr, "Cannot pop from empty stack.\n");
        return -1;
    }

    char output;
    output = stack->mem[stack->top];
    stack->top--;
    return output;
}

void moveFromTo(Stack *stack_origin, Stack *stack_dest) {
    char c = stack_pop(stack_origin);
    stack_push(stack_dest, c);
}

void move(int move_times, Stack *stack_origin, Stack *stack_dest) {
    if (move_times == 1) {
        moveFromTo(stack_origin, stack_dest);
        return;
    }

    char mem[STACK_SIZE];
    Stack *helper = stack_create(mem, STACK_SIZE);

    for (int i = 0; i < move_times; i++) {
        moveFromTo(stack_origin, helper);
    }

    for (int i = 0; i < move_times; i++) {
        moveFromTo(helper, stack_dest);
    }
}


