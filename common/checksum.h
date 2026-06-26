#pragma once

#include <stddef.h>
#include <stdint.h>


typedef uint8_t checksum_t;

checksum_t calculate_checksum(void *buff, size_t size);