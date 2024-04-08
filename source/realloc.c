#include "malloc.h"

t_zone *get_zone(uint8_t *ptr);

void *realloc(void *ptr, size_t size)
{
    if (ptr == NULL)
        return (malloc(size));

    t_zone *zone = get_zone(ptr);
    if (zone == NULL)
        return (malloc(size));

    if (zone->type == ZONE_TYPE_BLOCK)
    {
        t_metadata_block metadata = read_metadata_block_from_array(zone->mem);
        if (metadata.size_of_each_block >= size)
            return (ptr);
    }

    uint8_t *new_ptr = malloc(size);
    if (new_ptr == NULL)
        return (NULL);
    for (size_t i = 0; i < size; i++)
    {
        new_ptr[i] = ((uint8_t *)ptr)[i];
    }

    free(ptr);
    return (new_ptr);
}