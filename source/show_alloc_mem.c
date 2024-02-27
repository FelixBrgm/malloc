#include "malloc.h"

void show_alloc_mem(void)
{
    printf("------------ Allocation Bookkeeping ------------\n\n");

    int i = 0;
    while (i < storage.index)
    {
        t_zone *zone = storage.zones + i++;
        printf("  |----------------- Zone[%i]:  ---------------\n  |\n", i - 1);
    }
}