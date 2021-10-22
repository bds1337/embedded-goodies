#include <stdio.h>
#include "state.h"

state_func_ptr_t state = state_time;

void *state_time()
{
    printf("Time: 20:22\n");
}

void *state_date()
{
    printf("Date: 3 of september\n");
}

