/*
 * Sequential Registrations List (sqll_reg)
 *
 * Implemented using Sequential Linear List (sqll)
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct SqRegistrationsList {
    int registrations[MAX];
    int len;
} SqRegistrationsList;

typedef struct SqRegistrationsList_v2 {
    int *registrations;
    int len;
    int lenMax;
} SqRegistrationsList_v2;

SqRegistrationsList * sqll_reg_create_list() {
    SqRegistrationsList *src = malloc(sizeof (SqRegistrationsList));
    src->len = 0;
    return src;
}

SqRegistrationsList_v2 * sqll_reg_create_list_v2(int lenMax) {
    SqRegistrationsList_v2 *src = malloc(sizeof (SqRegistrationsList_v2));
    src->registrations = malloc(sizeof (int) * lenMax);
    src->len = 0;
    return src;
}

int sqll_reg_get_len(SqRegistrationsList *src) {
    if (src == NULL) return -1;
    else return src->len;
}

int sqll_reg_search_seq_sorted(SqRegistrationsList *src, int value) {
    for (int i = 0; i < src->len; i++) {
        if (src->registrations[i] >= value) {
            return (src->registrations[i] == value) ? i : -1;
        }
    }

    return -1;
}

int sqll_reg_insert_sorting(SqRegistrationsList *src, int newRegistration) {
    int result;

    /* if list is full -> return -1 */

//    result =
}
