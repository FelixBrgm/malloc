#include "malloc.h"

int main()
{
    printf("Pagesize: %i\n", getpagesize());
    void *test = NULL;
    int i = 0;
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    printf("BEFORE\n");
    test = malloc(140);
    printf("After\n");
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);
    test = malloc(140);

    show_alloc_mem();

    return (0);
}