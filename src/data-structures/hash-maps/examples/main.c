#include <stdlib.h>
#include <stdio.h>

#include "patients-hash.h"
#include "../../../utils/show.h"

int init_main() {
    init_show();
}

void patients_hash_example() {
    show_header("Example - Patients Simple Hash", MAGENTA);
    HashTable table;
    Patient patient, *p;
}

int main() {
    init_main();

    patients_hash_example();

    return 0;
}