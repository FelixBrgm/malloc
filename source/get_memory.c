#include "malloc.h"

void *get_block_memory(size_t size, uint8_t block_type)
{
    for (size_t i = 0; i < storage.capacity; i++)
    {
        const t_zone *zone = storage.zones + i;
        if (zone->mem == NULL)
            continue;

        if (zone->type != ZONE_TYPE_BLOCK)
            continue;

        const uint32_t nbr_of_used_blocks = read_u32_from_array(zone->mem);
        const uint32_t max_nbr_of_blocks = read_u32_from_array(zone->mem + 4);
        const uint32_t isEnoughSpace = nbr_of_used_blocks < max_nbr_of_blocks;
        if (!isEnoughSpace)
            continue;

        const uint32_t metadata_offset = 16;
        for (uint32_t i = 0; i < max_nbr_of_blocks; i++) // 16 is after the metadata and the start of the bookkeeping
        {
            uint32_t bit = i % 8;
            uint32_t byte = i / 8;

            const uint8_t isAlreadyUsed = get_bit(zone->mem[metadata_offset + byte], bit);
            if (isAlreadyUsed)
                continue;

            activate_bit(zone->mem + metadata_offset + byte, bit);
            write_u32_to_array(zone->mem, nbr_of_used_blocks + 1);

            const uint32_t block_size = read_u32_from_array(zone->mem + 8);
            const uint32_t first_block = read_u32_from_array(zone->mem + 12);
            const void *user_memory = zone->mem + first_block + (i * block_size);
            return (user_memory);
        }
    }

    return (NULL);
}

void *get_single_memory(size_t size)
{
    t_zone *new = add_zone(size);
    if (new == NULL)
        return (NULL);
    return new->mem;
}