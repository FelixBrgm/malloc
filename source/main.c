#include "malloc.h"

int main()
{
    printf("Pagesize: %i\n", getpagesize());
    void *test = NULL;
    int i = 0;
    test = malloc(14);
    while (test)
    {
        i++;
        test = malloc(16);
        printf("Malloc:%p\n\n", test);
    }
    show_alloc_mem();

    printf("%i\n", i);
    return (0);
}