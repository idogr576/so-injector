#include <time.h>
#include "utils.h"

uint64_t get_absolute_nanoseconds(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);

    return ((uint64_t)ts.tv_sec * 1000000000ULL) + (uint64_t)ts.tv_nsec;
}