#include "malloc.h"
int main()
{
    for (size_t i = 0; i < 200 * 100; i++)
    {
        void *test = malloc(10);
        free(test);
        test = malloc(10);
    }

    printf("Capacity %i\n", storage.capacity);
    return (0);
}