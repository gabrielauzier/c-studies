#include <stdio.h>
#include <stdlib.h>

#include "../../../utils/show.h"
#include "books-stack.h"

void init_main() {
    init_show();
}

int main() {
    init_main();

    show_header("Example - Stack/pile of books", YELLOW);

    BooksStack *stack = bs_create_stack();
    Book *b = bs_create_book("8544002161", "Crime e Castigo", "Fiodor Dostoievski", 584, 93.93);
    Book *a = bs_create_book("8535933921", "Sapiens", "Yuval N. H.", 472, 42.50);
    Book *c = bs_create_book("6555981520", "1984", "George Orwell", 448, 37.99);

    bs_insert_book(stack, *a);
    bs_insert_book(stack, *b);
    bs_insert_book(stack, *c);
    bs_print_stack(stack);

    bs_delete_book(stack);
    bs_print_stack(stack);

    Book book = bs_first_book(stack);
    BooksStackElement *el = bs_first_element(stack);

    printf("First book: %s\n", book.title);
    printf("First elem: %s\n", el->book.title);
    endline();

    bs_reset_stack(stack);
    bs_print_stack(stack);

    return 0;
}