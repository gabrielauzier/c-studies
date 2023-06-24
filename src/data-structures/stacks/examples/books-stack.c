#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "books-stack.h"
#include "../../../utils/show.h"

BooksStack * bs_create_stack() {
    BooksStack *src = malloc(sizeof (BooksStack));
    bs_init_stack(src);
    return src;
}

Book * bs_create_book(char* isbn, char *title, char *author, int pagesQtd, double price) {
    Book *src = malloc(sizeof (Book));

    strcpy(src->isbn, isbn);
    strcpy(src->title, title);
    strcpy(src->author, author);
    src->pagesQtd = pagesQtd;
    src->price = price;

    return src;
}

void bs_init_stack(BooksStack *src) {
    src->top = NULL;
}

void bs_reset_stack(BooksStack *src) {}

int bs_insert_book(BooksStack *src, Book newBook) {
    BooksStackElement *newElement = malloc(sizeof (BooksStackElement));
    if (newElement == NULL) return 0;
    newElement->book = newBook;
    newElement->next = src->top;
    src->top = newElement;
    return 1;
}

int bs_delete_book(BooksStack *src) {
    if (src->top == NULL) return 0;
    BooksStackElement *top = src->top;
    src->top = src->top->next;
    free(top);
    return 1;
}

BooksStackElement * bs_first_element(BooksStack *src) {
    return src->top;
}

Book bs_first_book(BooksStack *src) {
    return src->top->book;
}

void bs_print_stack(BooksStack *src) {
    endline();

    BooksStackElement *crawler = src->top;

    int maxLine = 0;
    while (crawler != NULL) {
        int len;
        len = (int) strlen(crawler->book.title);
        if (len > maxLine) maxLine = len;
        len = (int) strlen(crawler->book.author);
        if (len > maxLine) maxLine = len;
        crawler = crawler->next;
    }

    maxLine += 10;
    show_start(GREEN, BLACK);
    show_text_align_center("TOP", maxLine);
    show_close();

    endline();
    endline();

    crawler = src->top;
    char text[255];

    while (crawler != NULL) {
        show_start(CYAN, BLACK);
        show_text_align_center(crawler->book.title, maxLine);
        show_close();
        endline();

        show_start(YELLOW, BLACK);
        sprintf(text, "ISBN: %s", crawler->book.isbn);
        show_text_align_center(text, maxLine);
        show_close();
        endline();

        show_start(YELLOW, BLACK);
        sprintf(text, "Author: %s", crawler->book.author);
        show_text_align_center(text, maxLine);
        show_close();
        endline();

        show_start(YELLOW, BLACK);
        sprintf(text, "Pages: %d", crawler->book.pagesQtd);
        show_text_align_center(text, maxLine);
        show_close();
        endline();

        show_start(YELLOW, BLACK);
        sprintf(text, "R$: %.2lf", crawler->book.price);
        show_text_align_center(text, maxLine);
        show_close();
        endline();

        endline();
        crawler = crawler->next;
    }

    show_close();
    endline();
}


