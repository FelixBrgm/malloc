#include "malloc.h"


void show_alloc_mem(void)
{  
    t_zone *current = NULL;
    t_zone *smallest = NULL;
    do
    {
        current = NULL;
        for (size_t i = 0; i < storage.capacity; i++)
        {
            t_zone *zone = storage.zones + i;
            if (zone->mem)
                continue;
            if (zone->mem > smallest && zone->mem < current)
                current = zone;
        }

        // print

        smallest = current;
    } while (current);
    
}

void show_zone(t_zone *zone);

unsigned long show_zone_single(t_zone *zone);

unsigned long show_zone_block(t_zone *zone);