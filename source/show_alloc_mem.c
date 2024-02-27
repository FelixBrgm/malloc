#include "malloc.h"

void print_dynamic_zone(t_zone *zone)
{
    short nxt = 0;
    int short alloc_count = 0;
    short size = 0;

    nxt = read_chars_as_short(zone->mem);
    while (nxt)
    {
        alloc_count++;
        size = read_chars_as_short(zone->mem + nxt + 2);
        printf("  | Index: %i \t u_index: %i \t Size: %i \t Next: %i\n", nxt, nxt + 4, size, read_chars_as_short(zone->mem + nxt));
        nxt = read_chars_as_short(zone->mem + nxt);
    }

    printf("  |\n  |---------------- %i allocs ----------------\n\n", alloc_count);
}

void show_alloc_mem(void)
{
    printf("------------ Allocation Bookkeeping ------------\n\n");

    int i = 0;
    while (i < storage.index)
    {
        t_zone *zone = storage.zones + i++;
        printf("  |-------------- Zone[%i]: Dynamic ------------\n  |\n", i - 1);

        switch (zone->type)
        {
        case ZONE_TYPE_DYNAMIC:
            print_dynamic_zone(zone);
            break;

        default:
            break;
        }
    }
}