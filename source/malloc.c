#include "malloc.h"

t_storage storage = {0};

void *malloc(size_t size)
{
    if (storage.zones == NULL || storage.capacity == 0)
    {
        storage.page_size = getpagesize();
        storage.index = 0;
        storage.capacity = 10;
        storage.zones = alloc(sizeof(t_storage) * 10);
        // REMOVE THIS
        storage.zones[0].mem = alloc(storage.page_size);
        storage.zones[0].size = storage.page_size;
        storage.zones[0].type = ZONE_TYPE_DYNAMIC;
        storage.zones[0].widest_gap = storage.page_size - 2;
        storage.index++;
    }

    uint8_t type = get_type_from_size(size);

    switch (type)
    {
    case ZONE_TYPE_DYNAMIC:
        return create_dynamic_zone_alloc(size);
    }

    return NULL;
}

void free(void *ptr)
{
    if (ptr == NULL)
        return;
    // is null

    // existing

    // what type
}

void *alloc(size_t size)
{
    size_t *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED)
        return NULL;
    return ptr;
}