#include "checksum.h"

checksum_t calculate_checksum(void *buff, size_t size)
{
    checksum_t xor = 0;
    checksum_t *conv_buff = (checksum_t *)buff;
    for (size_t i = 0; i < size; i++)
    {
        xor ^= conv_buff[i];
    }
    return xor;
}