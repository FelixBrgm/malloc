#include "malloc.h"

t_storage storage = {0};

void *malloc(size_t size)
{
    if (size <= TINY_ALLOC_SIZE)
    {
    }
    else if (size <= SMALL_ALLOC_SIZE)
    {
    }
    else
    {
        if (add_zone(size))
            return (NULL);
        return (get_large_mem(size));
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

void dealloc(void *ptr, size_t size)
{
    if (ptr != NULL && size > 0)
    {
        munmap(ptr, size);
    }
}