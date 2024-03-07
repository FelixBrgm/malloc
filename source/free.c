#include "malloc.h"

t_zone *get_zone(uint8_t *ptr);
void free_single(t_zone *zone);
void free_block(t_zone *zone, uint8_t *ptr);
void dealloc_zone(t_zone *zone);

void ft_free(void *ptr)
{
    if (ptr == NULL)
        return;

    t_zone *zone = get_zone(ptr);
    if (zone == NULL)
        return;

    if (zone->type == ZONE_TYPE_SINGLE)
        free_single(zone);
    else if (zone->type == ZONE_TYPE_BLOCK)
        free_block(zone, ptr);
}

void free_single(t_zone *zone)
{
    dealloc_zone(zone);
}

void free_block(t_zone *zone, uint8_t *ptr)
{
    const uint32_t start_of_blocks = read_u32_from_array(zone->mem + 12);
    const uint32_t relative_ptr = zone->mem - ptr;
    const uint32_t size_of_blocks = read_u32_from_array(zone->mem + 8);
    const uint32_t index = relative_ptr / size_of_blocks;

    const uint8_t byte = index / 8;
    const uint8_t bit = index % 8;

    clear_bit(zone->mem + byte, bit);

    uint32_t nbr_of_used_blocks = read_u32_from_array(zone->mem);
    nbr_of_used_blocks--;
    write_u32_to_array(zone->mem, nbr_of_used_blocks);

    if (nbr_of_used_blocks == 0)
        dealloc_zone(zone);
}

void dealloc_zone(t_zone *zone)
{
    dealloc(zone->mem, zone->size);
    zone->mem = NULL;
    zone->size = 0;
    zone->type = 0;
}

t_zone *get_zone(uint8_t *ptr)
{
    t_zone *zone = NULL;
    for (size_t i = 0; i < storage.capacity; i++)
    {
        t_zone *tmp = storage.zones + i;
        if (ptr >= tmp->mem && ptr <= (tmp->mem + tmp->size))
        {
            zone = tmp;
            break;
        }
    }
}