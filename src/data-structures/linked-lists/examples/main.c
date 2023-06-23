#include <stdio.h>
#include <stdlib.h>

//#include "data-structures/libs/dynamic-linked-list.h"
//#include "data-structures/libs/doubled-linked-list.h"
#include "../../../utils/show.h"

#include "registrations-list-example.h"

void init_main_() {
    init_show();
}

int main() {
    init_main_();

    show_header("Example - Registrations (Static Linked List)", MAGENTA);

    Registrations *list = reg_create_list();

    reg_print_list(list);
    Student *a = reg_create_student(10014, "Gabriel", 19);
    Student *b = reg_create_student(10043, "Rafael", 3);
    Student *c = reg_create_student(10032, "Miguel", 20);

    Student *students[] = { a, b, c };

    for (int i = 0; i < 3; i++) {
        reg_insert_student(list, students[i]);
    }

    reg_print_list(list);

    show_separator(20, WHITE);
    int len = reg_get_len(list);
    show_attr_int("List length", len);

    reg_delete_student(list, 10032);
    reg_print_list(list);

    return 0;
}