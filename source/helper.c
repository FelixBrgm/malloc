#include "malloc.h"

void write_uint16_t_as_uint8_ts(uint8_t *ptr, uint16_t s)
{
    if (ptr == NULL)
        return;
    ptr[0] = s >> 8;
    ptr[1] = s & 0xFF;
}

uint16_t read_uint8_ts_as_uint16_t(uint8_t *ptr)
{
    if (ptr == NULL)
        return 0;
    uint16_t res = 0;
    res = res | ptr[0] << 8;
    res = res | ptr[1];

    return (res);
}