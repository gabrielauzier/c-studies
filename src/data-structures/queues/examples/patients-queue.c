/*
 * Patients Queue (pq)
 *
 * Implemented using Simple (Dynamic) Queue
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "patients-queue.h"
#include "../../../utils/show.h"

PatientsQueue * pq_create_queue() {
    PatientsQueue *src = malloc(sizeof (PatientsQueue));
    pq_queue_init(src);
    return src;
}

Patient * pq_create_patient(int id, char *name, char *cpf, int age) {
    Patient *src = malloc(sizeof (Patient));

    src->id = id;
    strcpy(src->name, name);
    strcpy(src->cpf, cpf);
    src->age = age;

    return src;
}

void pq_queue_init(PatientsQueue *src) {
    src->front = NULL;
    src->back = NULL;
}

void pq_reset(PatientsQueue *src) {
    PatientsQueueElement *target;
    PatientsQueueElement *crawler = src->front;

    while (crawler != NULL) {
        target = crawler;
        crawler = crawler->next;
        free(target);
    }

    src->front = NULL;
}

int pq_insert_patient(PatientsQueue *src, Patient newPatient) {
    PatientsQueueElement *newElement;

    newElement = malloc(sizeof (PatientsQueueElement));

    if (newElement == NULL) return 0;

    newElement->patient = newPatient;
//    strcpy(newElement->patient.name, newPatient.name);
//    strcpy(newElement->patient.cpf, newPatient.cpf);
//    newElement->patient.id = newPatient.id;
//    newElement->patient.age = newPatient.age;

    newElement->next = NULL;

    if (src->front == NULL) {
        src->front = newElement;
    } else {
        src->back->next = newElement;
    }

    src->back = newElement;


    return 1;
}

int pq_delete_patient(PatientsQueue *src) {
    if (src->front == NULL) return 0;

    PatientsQueueElement *crawler = src->front;
    src->front = src->front->next;
    free(crawler);

    return 1;
}

PatientsQueueElement pq_get_first_element(PatientsQueue *src) {
    return *(src->front);
}

Patient pq_get_first_patient(PatientsQueue *src) {
    return src->front->patient;
}

void pq_print_queue(PatientsQueue *src) {
    endline();
    PatientsQueueElement *crawler = src->front;

    show_highlight(" FRONT ", BLUE, BLACK);
    printf(" --> ");

    while (crawler != NULL) {
        char text[255];
        sprintf(text, " (%d) %s ", crawler->patient.id, crawler->patient.name);
        show_highlight(text, CYAN, BLACK);

        if (crawler != NULL) printf(" --> ");
        crawler = crawler->next;
    }

    show_highlight(" BACK ", BLUE, BLACK);
    endline();
}
