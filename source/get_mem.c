#include "malloc.h"

int get_alloc_count(size_t size, int alloc_size)
{
    // Wild calculus i know
    int usable_mem = size - 2 - 1; // -2 for starting count -1 for security
    usable_mem = usable_mem * 8;
    int alloc_count = usable_mem / ((alloc_size * 8) + 1);

    return (alloc_count);
}

u_int8_t get_bit(u_int8_t *ptr, u_int8_t index)
{
    return (*ptr & (0x1 << (0x7 - index)));
}

void activate_bit(u_int8_t *ptr, u_int8_t index)
{
    *ptr = *ptr | (0x1 << (0x7 - index));
}

void *get_tiny_mem(size_t size)
{
    int i = 0;

    uint16_t alloc_count = get_alloc_count(TINY_ZONE_PAGE_MLTPLR * storage.page_size, TINY_ALLOC_SIZE);

    while (i < storage.index)
    {
        if (storage.zones[i].type == TINY_TYPE)
        {
            t_zone *zone = storage.zones + i;
            if (alloc_count <= read_uint8_ts_as_uint16_t(zone->mem))
            {
                i++;
                continue;
            }

            // loop over the bitmap and check if one is free
            int j = 0;
            while (j < alloc_count)
            {
                u_int16_t byte = (j / 8) + 2;
                u_int16_t bit = j % 8;
                if (get_bit(zone->mem + byte, bit) == 0)
                {
                    activate_bit(zone->mem + byte, bit);
                    write_uint16_t_as_uint8_ts(zone->mem, read_uint8_ts_as_uint16_t(zone->mem) + 1);
                    return (zone->mem + 2 + (alloc_count / 8) + 1 + (j * TINY_ALLOC_SIZE));
                }
                j++;
            }
            // set the bit and with the index collect the ptr and make the alloc count one bigger
        }
        i++;
    }

    return (NULL);
}
void *get_small_mem(size_t size);

void *get_large_mem(size_t size)
{
    int i = 0;

    while (i < storage.index)
    {

        if (storage.zones[i].type == LARGE_TYPE_FREE)
        {
            storage.zones[i].type = LARGE_TYPE_USED;
            return (storage.zones[i].mem);
        }
        i++;
    }
    return (NULL);
}