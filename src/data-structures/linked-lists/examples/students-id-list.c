
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//    int registration;
//    char *name;
//    int age;
//} Student;
//
//typedef struct element {
//    Student student;
//    struct element *next;
//} Element;
//
//typedef struct {
//    Element *head;
//} RegistrationsList;
//
//void init_list(RegistrationsList *src) {
//    src->head = NULL;
//}
//
//int get_valid_elements(RegistrationsList *src) {
//    int len = 0;
//    Element *crawler = src->head;
//
//    while (crawler != NULL) {
//        len++;
//        crawler = crawler->next;
//    }
//
//    return len;
//}
//
//void print_list(RegistrationsList *src) {
//    Element *crawler = src->head;
//
//    while (crawler != NULL) {
//        show_subtitle("Student");
//        show_attr_str("Name", crawler->student.name);
//        show_attr_int("Age", crawler->student.age);
//        show_attr_int("Registration", crawler->student.registration);
//
//        crawler = crawler->next;
//    }
//}
//
//Element * find_one(RegistrationsList *src, int registrationTarget) {
//    Element *crawler = src->head;
//
//    while (crawler != NULL) {
//        if (crawler->student.registration == registrationTarget) return crawler;
//
//        crawler = crawler->next;
//    }
//
//    return NULL;
//}
//
//Element * find_element_and_previous(RegistrationsList *src, int newRegistration, Element **previous) {
//    *previous = NULL;
//
//    Element *crawler = src->head;
//
//    while (crawler != NULL && crawler->student.registration < newRegistration) {
//        *previous = crawler;
//        crawler = crawler->next;
//    }
//
//    if (crawler != NULL && crawler->student.registration == newRegistration) return crawler;
//
//    return NULL;
//}
//
//int insert_student(RegistrationsList *src, Student newStudent) {
//    int newRegistration = newStudent.registration;
//    Element *previous;
//    Element *crawler;
//
//    crawler = find_element_and_previous(src, newRegistration, &previous);
//
//    if (crawler != NULL) return 0;
//
//    crawler = malloc(sizeof (Element));
//
//    crawler->student = newStudent;
//
//    if (previous == NULL) {
//        crawler->next = src->head;
//        src->head = crawler;
//    } else {
//        crawler->next = previous->next;
//        previous->next = crawler;
//    }
//
//    return 1;
//}
//
//int delete_student(RegistrationsList *src, int registrationTarget) {
//    Element *previous;
//    Element *crawler;
//
//    crawler = find_element_and_previous(src, registrationTarget, &previous);
//
//    if (crawler == NULL) return 0;
//
//    if (previous == NULL) {
//        src->head = crawler->next;
//    } else {
//        previous->next = crawler->next;
//    }
//
//    free(crawler);
//    return 1;
//}
//
//void restart_list(RegistrationsList *src) {
//    Element *crawler = src->head;
//
//    while (crawler != NULL) {
//        Element *target = crawler;
//        crawler = crawler->next;
//
//        free(target);
//    }
//
//    src->head = NULL;
//}