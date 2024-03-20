#include "malloc.h"

t_storage storage = {
    .zones = NULL,
    .capacity = 0,
    .page_size = 0,
    .block_sizes = BLOCK_SIZES,
};

void *get_block_memory(size_t size, uint8_t block_type);
void *get_single_memory(size_t size);

void *ft_malloc(size_t size)
{
    printf("HELLO\n");
    if (storage.page_size == 0)
        storage.page_size = getpagesize();

    if (size == 0)
        return (NULL);

    for (size_t i = 0; i < BLOCK_SIZES_LEN; i++)
    {
        const uint32_t block_size = storage.block_sizes[i];
        if (size <= block_size)
        {
            void *res = get_block_memory(size, block_size);
            if (res != NULL)
                return (res);
            add_zone(size);
            return (get_block_memory(size, block_size));
        }
    }

    return (get_single_memory(size));
}

void *get_block_memory(size_t size, uint8_t block_type)
{
    for (size_t i = 0; i < storage.capacity; i++)
    {
        const t_zone *zone = storage.zones + i;
        if (zone->mem == NULL)
            continue;

        if (zone->type != ZONE_TYPE_BLOCK)
            continue;

        t_metadata_block metadata = read_metadata_block_from_array(zone->mem);
        const uint32_t isEnoughSpace = metadata.nbr_of_used_blocks < metadata.max_nbr_of_blocks;
        if (!isEnoughSpace)
            continue;

        const uint32_t metadata_offset = 16;
        for (uint32_t i = 0; i < metadata.max_nbr_of_blocks; i++) // 16 is after the metadata and the start of the bookkeeping
        {
            uint32_t bit = i % 8;
            uint32_t byte = i / 8;

            const uint8_t isAlreadyUsed = get_bit(zone->mem[metadata_offset + byte], bit);
            if (isAlreadyUsed)
                continue;

            activate_bit(zone->mem + metadata_offset + byte, bit);
            metadata.nbr_of_used_blocks++;
            write_metadata_block_from_array(zone->mem, metadata);

            void *user_memory = zone->mem + metadata.index_of_first_alloc + (i * metadata.size_of_each_block);
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