/*
 * Books Stack (bs)
 *
 * Implemented using Simple Dynamic Stack
 *
 * */

typedef struct Book {
    char isbn[255];
    char title[255];
    char author[255];
    int pagesQtd;
    double price;
} Book;

typedef struct BooksStackElement {
    Book book;
    struct BooksStackElement *next;
} BooksStackElement;

typedef struct BooksStack {
    BooksStackElement *top;
} BooksStack;

BooksStack * bs_create_stack();
Book * bs_create_book(char *isbn, char *title, char *author, int pagesQtd, double price);

void bs_init_stack(BooksStack *src);
void bs_reset_stack(BooksStack *src);
int bs_insert_book(BooksStack *src, Book newBook);
int bs_delete_book(BooksStack *src);

BooksStackElement *bs_first_element(BooksStack *src);
Book bs_first_book(BooksStack *src);
void bs_print_stack(BooksStack *src);




