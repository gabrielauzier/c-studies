#include <stdio.h>
#include <stdlib.h>

#include "../../../utils/show.h"
#include "patients-queue.h"

void init_main_() {
    init_show();
}

int main() {
    init_main_();

    show_header("Example - Patients (Dynamic Queue)", BLUE);

    PatientsQueue *queue = pq_create_queue();
    Patient *a = pq_create_patient(113, "Gabriel", "701.224.672-30", 19);
    Patient *b = pq_create_patient(242, "Filipe", "421.543.634-60", 32);

    pq_insert_patient(queue, *a);
    pq_insert_patient(queue, *b);
    pq_print_queue(queue);

    pq_delete_patient(queue);
    pq_print_queue(queue);

    pq_delete_patient(queue);
    pq_print_queue(queue);

    return 0;
}