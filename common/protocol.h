#pragma once
#include "checksum.h"

#define MAX_DATA_SIZE (0x4000)

typedef struct
{
    size_t data_size;
    checksum_t data_checksum;
    uint8_t data[MAX_DATA_SIZE];
} packet_t;
