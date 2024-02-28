#include "malloc.h"

int main()
{
    printf("Pagesize: %i\n", getpagesize());
    void *test = NULL;
    int i = 0;
    for (size_t i = 0; i < 2; i++)
    {
        test = malloc(10);
        printf("RUN: %i with value %p\n", i, test);
        
    }
    show_alloc_mem();

    return (0);
}