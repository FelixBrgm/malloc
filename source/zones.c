#include "malloc.h"

t_zone *get_empty_zone(void);
int alloc_zone(t_zone *zone, size_t size);

// Function which makes vector bigger and so on
int extend_zones()
{
    if (storage.zones == NULL || storage.capacity == 0)
    {

        storage.zones = alloc(sizeof(t_zone) * INITIAL_ZONE_LEN);
        if (storage.zones == NULL)
            return (-1);
        storage.page_size = getpagesize();
        storage.index = 0;
        storage.capacity = INITIAL_ZONE_LEN;
    }
    else if (storage.index >= storage.capacity)
    {
        storage.capacity = storage.capacity * 2;
        t_zone *tmp = alloc(sizeof(t_zone) * INITIAL_ZONE_LEN);
        int i = 0;
        while (i < storage.index)
        {
            tmp[i] = storage.zones[i];
            i++;
        }
        dealloc(storage.zones, sizeof(t_zone) * storage.capacity / 2);

        storage.zones = tmp;
    }
    return (0);
}

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

// A not used zone is one with zone.mem == NULL
int add_zone(size_t size)
{

    t_zone *zone = NULL;

    zone = get_empty_zone();
    if (zone == NULL)
    {
        if (extend_zones())
            return (-1);

        zone = get_empty_zone();
    }

    if (zone == NULL)
        return (-1);

    if (alloc_zone(zone, size))
        return (-1);
    return (0);
}

int alloc_zone(t_zone *zone, size_t size)
{
    if (size <= TINY_ALLOC_SIZE)
    {
        zone->mem = alloc(storage.page_size);
        if (zone->mem == NULL)
            return (-1);
        zone->size = storage.page_size;
        zone->type = TINY_TYPE;
    }
    else if (size <= SMALL_ALLOC_SIZE)
    {
        zone->mem = alloc(storage.page_size * 4);
        if (zone->mem == NULL)
            return (-1);
        zone->size = storage.page_size * 4;
        zone->type = SMALL_TYPE;
    }
    else
    {
        zone->mem = alloc(size);
        if (zone->mem == NULL)
            return (-1);
        zone->size = size;
        zone->type = LARGE_TYPE_FREE;
    }
    storage.index++;
    return (0);
}

t_zone *get_empty_zone(void)
{
    int i = 0;

    while (i < storage.capacity)
    {
        if (storage.zones[i].mem == NULL)
            return (storage.zones + i);
        i++;
    }
    return (NULL);
}
