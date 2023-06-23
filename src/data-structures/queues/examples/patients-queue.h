/*
 * Patients Queue (pq)
 *
 * Implemented using Simple (Dynamic) Queue
 *
 * */

typedef struct Patient {
    int id;
    char name[255];
    char cpf[255];
    int age;
} Patient;

typedef struct PatientsQueueElement {
    Patient patient;
    struct PatientsQueueElement *next;
} PatientsQueueElement;

typedef struct PatientsQueue {
    PatientsQueueElement *front;
    PatientsQueueElement *back;
} PatientsQueue;

PatientsQueue * pq_create_queue();
Patient * pq_create_patient(int id, char *name, char *cpf, int age);

void pq_queue_init(PatientsQueue *src);
void pq_reset(PatientsQueue *src);
int pq_insert_patient(PatientsQueue *src, Patient newPatient);
int pq_delete_patient(PatientsQueue *src);

PatientsQueueElement pq_get_first_element(PatientsQueue *src);
Patient pq_get_first_patient(PatientsQueue *src);

void pq_print_queue(PatientsQueue *src);