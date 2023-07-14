/*
 * Patients hash v2
 *
 * Implemented using simple hash with trivial hash function and linked list
 *
 * */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../../../utils/show.h"

#define MAX_SIZE 101
#define MAX_CHAR 255

typedef struct Patient {
    int code;
    int age;
    char name[MAX_CHAR];
    char cpf[MAX_CHAR];
} Patient;

typedef struct Element {
    Patient patient;
    struct Element *next;
} Element;

typedef Element * HashTable[MAX_SIZE];

int hashmap(int code);
int insert(HashTable src, Patient patient);
void initialize_hash(HashTable src);
void print_hash(HashTable src);
Patient * find_patient(HashTable src, int code);

Patient * create_patient(int code, int age, char *name, char *cpf) {
    Patient *new = malloc(sizeof (Patient));
    new->code = code;
    new->age = age;
    strcpy(new->name, name);
    strcpy(new->cpf, cpf);
    return new;
}

void initialize_hash(HashTable src) {
    for (int i = 0; i < MAX_SIZE; i++) {
        src[i] = NULL;
    }
}

int hashmap(int code) {
    return code % MAX_SIZE;
}

int insert(HashTable src, Patient patient) {
    int key = hashmap(patient.code);

    Element *previous = NULL;
    Element *crawler = src[key];

    while (crawler != NULL) {
        if (crawler->patient.code == patient.code) return 0;

        previous = crawler;
        crawler = crawler->next;
    }

    if (crawler == NULL) {
        crawler = malloc(sizeof (Element));
        crawler->patient = patient;
        crawler->next = NULL;

        if (previous == NULL) src[key] = crawler;
        else previous->next = crawler;
    }

    return 1;
}

Patient * find_patient(HashTable src, int TargetCode) {
    int key = hashmap(TargetCode);
    Element *crawler = src[key];

    while (crawler != NULL) {
        if (crawler->patient.code == TargetCode) {
            return &crawler->patient;
        } else {
            crawler = crawler->next;
        }
    }
    return NULL;
}

void print_hash(HashTable src) {
    Element *crawler;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (src[i] != NULL) {
            crawler = src[i];
            show_attr_int("Patient.code: ", src[i]->patient.code);

            while (crawler != NULL) {
                show_attr_str("Patient.name: ", src[i]->patient.name);
                crawler = crawler->next;
            }
        } else {
            show_attr_str("Patient", "NULL");
        }
    }
}
