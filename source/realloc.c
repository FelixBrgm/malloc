#include "malloc.h"

t_zone *get_zone(uint8_t *ptr);

void *ft_realloc(void *ptr, size_t size)
{
    printf("Hello\n");
    if (ptr == NULL)
        return (NULL);

    t_zone *zone = get_zone(ptr);
    if (zone == NULL)
        return (NULL);

    if (zone->type == ZONE_TYPE_BLOCK)
    {
        t_metadata_block metadata = read_metadata_block_from_array(zone->mem);
        printf("Value: %i\n", metadata.size_of_each_block);
        if (metadata.size_of_each_block >= size)
            return (ptr);
    }

    uint8_t *new_ptr = alloc(size);
    if (new_ptr == NULL)
        return (NULL);
    for (size_t i = 0; i < size; i++)
    {
        new_ptr[i] = ((uint8_t *)ptr)[i];
    }

    ft_free(ptr);
    return (new_ptr);
}